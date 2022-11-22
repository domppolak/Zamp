#include <iostream>
#include <dlfcn.h>
#include <cassert>
#include "Set4LibInterfaces.hh"
#include "Interp4Command.hh"
#include "MobileObj.hh"
#include "parser.hh"

using namespace std;


int main()
{
  /*void *pLibHnd_Move = dlopen("libInterp4Move.so",RTLD_LAZY);
  Interp4Command *(*pCreateCmd_Move)(void);
  void *pFun;

  if (!pLibHnd_Move) {
    cerr << "!!! Brak biblioteki: Interp4Move.so" << endl;
    return 1;
  }


  pFun = dlsym(pLibHnd_Move,"CreateCmd");
  if (!pFun) {
    cerr << "!!! Nie znaleziono funkcji CreateCmd" << endl;
    return 1;
  }
  pCreateCmd_Move = *reinterpret_cast<Interp4Command* (**)(void)>(&pFun);


  Interp4Command *pCmd = pCreateCmd_Move();

  cout << endl;
  cout << pCmd->GetCmdName() << endl;
  cout << endl;
  pCmd->PrintSyntax();
  cout << endl;
  pCmd->PrintCmd();
  cout << endl;
  
  delete pCmd;

  dlclose(pLibHnd_Move);*/

  Set4LibInterfaces libInter;
  Parser pars;
  std::istringstream istream;
  std::shared_ptr<Scene> scene;
  std::vector<std::string> libs;
  libs.push_back("libs/libInterp4Move.so");
  libs.push_back("libs/libInterp4Pause.so");
  libs.push_back("libs/libInterp4Rotate.so");
  libs.push_back("libs/libInterp4Set.so");
  libInter.LoadLibraries(libs);

  pars.setCmdFile("dzialania.cmd");
  pars.parseCMD(istream);
  //libInter.execPreprocessor("dzialania.cmd", istream);
  libInter.execCommands(istream, scene);

  return 0;

}
