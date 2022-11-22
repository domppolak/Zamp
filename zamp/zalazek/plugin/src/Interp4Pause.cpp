#include <iostream>
#include "Interp4Pause.hh"
#include "MobileObj.hh"

using std::cout;
using std::endl;

//////////// wtyczka //////////////////////

extern "C" {
  Interp4Command* CreateCmd(void);
  const char* GetCmdName(void);
}


const char* GetCmdName(void)
{
  return "Pause";
}

Interp4Command* CreateCmd(void)
{
  return Interp4Pause::CreateCmd();
}

/*!
 *
 */
Interp4Pause::Interp4Pause()
    : _pauseTime(0)
{}


/*!
 *
 */
void Interp4Pause::PrintCmd() const
{
  cout << GetCmdName() << " " << _pauseTime << endl;
}


/*!
 *
 */
const char* Interp4Pause::GetCmdName() const
{
  return "Pause";
}


/*!
 *
 */
bool Interp4Pause::ExecCmd( std::shared_ptr<MobileObj> &obj, std::shared_ptr<Scene> &access) const
{
  /*access->lockAccess();
  usleep(_pauseTime*1000);
  access->unlockAcess();

  std::cout << "Pause END" << std::endl;
  return true;*/
}


/*!
 *
 */
bool Interp4Pause::ReadParams(std::istream& Strm_CmdsList)
{
  Strm_CmdsList >> _pauseTime;
  return !Strm_CmdsList.fail();
}


/*!
 *
 */
Interp4Command* Interp4Pause::CreateCmd()
{
  return new Interp4Pause();
}


/*!
 *
 */
void Interp4Pause::PrintSyntax() const
{
  cout << "  Pause CzasPauzy[ms]" << endl;
}


void Interp4Pause::PrintParams()
{
  cout << "Pause: " << _pauseTime << endl;
}

