#include <iostream>
#include "Interp4Move.hh"
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
  return "Move";
}

Interp4Command* CreateCmd(void)
{
  return Interp4Move::CreateCmd();
}



/*!
 *
 */
Interp4Move::Interp4Move()
  : _objName("")
  , _velocity(0)
  , _road(0)
{}


/*!
 *
 */
void Interp4Move::PrintCmd() const
{
  cout << GetCmdName() << " " << _objName <<" " << _velocity << " "  << _road << endl;
}


/*!
 *
 */
const char* Interp4Move::GetCmdName() const
{
  return ::GetCmdName();
}


/*!
 *
 */
bool Interp4Move::ExecCmd(std::shared_ptr<MobileObj> &obj, std::shared_ptr<Scene> &acess) const
{
  //Vector3D startPos = obj->GetPositoin_m();
  /*Vector3D newPosition;
  double angle=0;
  int direction = _velocity > 0 ? 1 : -1;
  double timeStep = (((double)_road/_velocity)*100)*1000000;

  for(int i=0; i<100; ++i){
    acess->lockAccess();

    newPosition = obj->GetPositoin_m();
    angle = obj->GetAng_Roll_deg();

    newPosition[0] += _velocity*direction*cos(M_PI *angle/180);
    newPosition[1] += _velocity*direction*sin(M_PI *angle/180);

    obj->SetPosition_m(newPosition);

    acess->markChange();
    acess->unlockAcess();
    usleep(timeStep);
  }

  std::cout << "Move DONE" << std::endl;
  return true;*/
}


/*!
 *
 */
bool Interp4Move::ReadParams(std::istream& Strm_CmdsList)
{
  Strm_CmdsList >> _objName >> _velocity >> _road;
  return !Strm_CmdsList.fail();
}


/*!
 *
 */
Interp4Command* Interp4Move::CreateCmd()
{
  return new Interp4Move();
}


/*!
 *
 */
void Interp4Move::PrintSyntax() const
{
  cout << "   Move  NazwaObiektu  Szybkosc[m/s]  DlugoscDrogi[m]" << endl;
}

void Interp4Move::PrintParams()
{
  cout << "Params" << endl;
  cout << _objName << " " << _velocity << " " << _road;
}



