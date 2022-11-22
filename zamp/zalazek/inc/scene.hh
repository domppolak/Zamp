#ifndef SCENE_HH
#define SCENE_HH

#include <map>
#include <memory>
#include <string>

#include "AccessControl.hh"
#include "MobileObj.hh"

class Scene : public AccessControl
{
public:
    bool findMobileObject(std::string name, std::shared_ptr<MobileObj> & obj);
    void addMobileObiject(std::shared_ptr<MobileObj> handler);

    std::map<std::string, std::shared_ptr<MobileObj>> & getMapMobileObjects() { return this->_mapMobileObjects; }

private:
    std::map<std::string, std::shared_ptr<MobileObj>> _mapMobileObjects;


};

#endif