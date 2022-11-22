#ifndef SET4LIBINTERFACES_HH
#define SET4LIBINTERFACES_HH

#include <map>
#include <sstream>
#include <memory>
#include <iostream>
#include <string>
#include <dlfcn.h>
#include <vector>

#include "LibInterface.hh"


class Set4LibInterfaces
{
public:
    bool execPreprocessor(const char *fileName, std::istringstream &Istrm4Cmds);    bool LoadLibraries(std::vector<std::string> pluginPath);
    bool execCommands(std::istream &cmdStream, std::shared_ptr<Scene> &scene);

private:
    std::map<std::string, std::shared_ptr<LibInterface>> _mapLibraries;
    Interp4Command *_cmdInstance;

};

#endif