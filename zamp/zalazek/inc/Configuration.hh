#ifndef CONFIGURATION_HH
#define CONFIGURATION_HH

#include <map>
#include <vector>
#include <memory>
#include <string>

#include "MobileObj.hh"



class Configuration {
  public:
  Configuration(){}
  ~Configuration() { _libraryLits.clear(); }

  void AddMobileObj(
    std::string &objName,
      Vector3D &shift,
        Vector3D &scale,
          Vector3D &royXYZ,
            Vector3D &trans,
              Vector3D &RGB
  );
  void AddLibraryName(std::string &libName);

  private:
  std::map<std::string, std::shared_ptr<MobileObj>> _mobileObjects;
  std::vector<std::string> _libraryLits;
};


#endif
