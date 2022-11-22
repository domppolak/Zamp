#include <iostream>
#include "Interp4Rotate.hh"
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
  return "Rotate";
}

Interp4Command* CreateCmd(void)
{
  return Interp4Rotate::CreateCmd();
}

/*!
 *
 */
Interp4Rotate::Interp4Rotate()
    : _objName("")
    , _angularVelocity(0)
    , _angel(0)
{}


/*!
 *
 */
void Interp4Rotate::PrintCmd() const
{
  cout << GetCmdName() << " " << _objName << " " << " " << _angularVelocity << " " << _angel << endl;
}


/*!
 *
 */
const char* Interp4Rotate::GetCmdName() const
{
  return "Rotate";
}


/*!
 *
 */
bool Interp4Rotate::ExecCmd( std::shared_ptr<MobileObj> &obj, std::shared_ptr<Scene> &acces) const
{
  /*double startYaw = obj->GetAng_Yaw_deg();
  double deltaYaw = 0;
  double step = (double)_angel/100;
  double timeStep = (((double)_angel/_angularVelocity)*1000000)/100;

  for(int i=0; i<100; ++i){
    acces->lockAccess();
    deltaYaw += step;
    obj->SetAng_Yaw_deg(deltaYaw + startYaw);
    acces->markChange();
    acces->unlockAcess();
    usleep(timeStep);
  }

  std::cout << "Rotate DONE" << std::endl;
  return true;*/
}


/*!
 *
 */
bool Interp4Rotate::ReadParams(std::istream& Strm_CmdsList)
{
  Strm_CmdsList >> _objName >> _angularVelocity >> _angel;
  return !Strm_CmdsList.fail();
}


/*!
 *
 */
Interp4Command* Interp4Rotate::CreateCmd()
{
  return new Interp4Rotate();
}


/*!
 *
 */
void Interp4Rotate::PrintSyntax() const
{
  cout << "   Rotate  NazwaObiektu  SzybkoscKatowa[m/s]  KatObrotu[m]" << endl;
}

void Interp4Rotate::PrintParams()
{
  cout << "Params" << endl;
  cout << _objName << " " << _angularVelocity << " " << _angel;
}

