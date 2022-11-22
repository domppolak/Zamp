#include <iostream>
#include "Interp4Set.hh"
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
  return "Set";
}

Interp4Command* CreateCmd(void)
{
  return Interp4Set::CreateCmd();
}

/*!
 *
 */
Interp4Set::Interp4Set()
    : _objName("")
    , _x_cord(0)
    , _y_cord(0)
    , _angel_OZ(0)
{}


/*!
 *
 */
void Interp4Set::PrintCmd() const
{
  cout << GetCmdName() << " " << _objName<< " " << _x_cord << " " << _y_cord << " " 
     << _angel_OZ << endl;
}


/*!
 *
 */
const char* Interp4Set::GetCmdName() const
{
  return "Set";
}


/*!
 *
 */
bool Interp4Set::ExecCmd( std::shared_ptr<MobileObj> &obj, std::shared_ptr<Scene> &access) const
{
    /*Vector3D newPosition = obj->GetPositoin_m();
    access->lockAccess();
    newPosition[0] = this->_x_cord;
    newPosition[1] = this->_y_cord;

    obj->SetPosition_m(newPosition);
    obj->SetAng_Yaw_deg(this->_angel_OZ);

    access->markChange();
    access->unlockAcess();

    std::cout << "Set DONE" << std::endl;
    return true;*/
}


/*!
 *
 */
bool Interp4Set::ReadParams(std::istream& Strm_CmdsList)
{
  Strm_CmdsList >> _objName >>_x_cord >> _y_cord >> _angel_OZ;
  return !Strm_CmdsList.fail();
}


/*!
 *
 */
Interp4Command* Interp4Set::CreateCmd()
{
  return new Interp4Set();
}


/*!
 *
 */
void Interp4Set::PrintSyntax() const
{
  cout << "   Set NazwaObiektu  Wspolrzedna_X  Wspolrzedna_Y Kat_OZ" << endl;
}

void Interp4Set::PrintParams()
{
  cout << "Params:" << endl; 
  cout << _objName << " " << _x_cord << " " << _y_cord << " " << _angel_OZ << endl;
}

