#include "Set4LibInterfaces.hh"

bool Set4LibInterfaces::LoadLibraries(std::vector<std::string> pluginPaths)
{
    std::vector<std::string>::iterator it;

    for(it = pluginPaths.begin(); it < pluginPaths.end(); it++){
        std::shared_ptr<LibInterface> tmpLibary = std::make_shared<LibInterface>();
        if(!tmpLibary->init(*it)){
            std::cerr << "Blad inicjalizacji biblioteki" << std::endl;
            return false;
        }

        _mapLibraries.insert(std::make_pair(tmpLibary->getName(), tmpLibary));
    }

    return true;
}

bool Set4LibInterfaces::execCommands(std::istream &cmdStream, std::shared_ptr<Scene> &scene)
{
  std::string plugin, objName;
  std::shared_ptr<LibInterface> pLib;
  std::shared_ptr<MobileObj> pObj;
  
  while(cmdStream >> plugin)
  {
      std::map<std::string, std::shared_ptr<LibInterface>>::iterator it;
      it = _mapLibraries.find(plugin);

      if(it == _mapLibraries.end()){
        std::cerr << "Brak wtyczki dla: " << plugin << std::endl;
        return false; 
      }

      pLib = it->second; 
      _cmdInstance = pLib->CreateCmd();
      _cmdInstance->ReadParams(cmdStream);

      _cmdInstance->PrintSyntax();

      /*if(_cmdInstance->GetObjName() !=""){
        if(!scene->findMobileObject(_cmdInstance->GetObjName(), pObj)){
          std::cerr << "Nie znaleziono obiektu!" << std::endl;
          return false;
        }
      }*/

      //_cmdInstance->ExecCmd(obj, scene);

      _cmdInstance->PrintCmd();

      delete(_cmdInstance);   
  }

  return true;
}