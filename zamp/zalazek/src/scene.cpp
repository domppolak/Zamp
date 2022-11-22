#include "scene.hh"
#include <iterator>

bool Scene::findMobileObject(std::string name, std::shared_ptr<MobileObj> & obj)
{
    std::map<std::string, std::shared_ptr<MobileObj>>::iterator it;

    it = _mapMobileObjects.find(name);

    if(it == _mapMobileObjects.end()){
        std::cerr << "Nie znaleziono obiektu: " << name << std::endl;
        return false;
    }

    obj = it->second;
    return true;
}

void Scene::addMobileObiject(std::shared_ptr<MobileObj> handler)
{
    _mapMobileObjects.insert(std::make_pair(handler->GetName(), handler));
}