#ifndef LIB_INTERFACE_HH
#define LIB_INTERFACE_HH

#include "string"
#include "dlfcn.h"
#include "iostream"
#include "Interp4Command.hh"

class LibInterface
{
public:
    LibInterface() {}
    ~LibInterface();
    bool init(std::string path);
    std::string getName() { return this->_cmdName; }
    Interp4Command *CreateCmd() { return pCreateCmd(); }
    
private:
    void *_libHandler;
    std::string _cmdName;
    Interp4Command * (* pCreateCmd)(void);
};

#endif