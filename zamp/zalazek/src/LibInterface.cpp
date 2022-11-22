#include "LibInterface.hh"

bool LibInterface::init(std::string path)
{
    void *pfun;

    _libHandler = dlopen(path.c_str(), RTLD_LAZY);

    if(!_libHandler){
        std::cerr << "Nie udalo sie otworzyc biblioteki: " << path << std::endl;
        return false;
    }

    pfun = dlsym(_libHandler, "CreateCmd");


    if(!pfun){
        std::cerr << "Brak funckji CreateCmd" << std::endl;
        return false;
    }

    pCreateCmd = * reinterpret_cast <Interp4Command * ( * )(void)> (pfun);
    
    pfun = dlsym(_libHandler, "GetCmdName");

    if(!pfun){
        std::cerr << "Brak funkcji GetCmdName" << std::endl;
        return false;
    }
    const char *(*cmdName)(void) = reinterpret_cast<const char* (*)(void)>(pfun);
    _cmdName = cmdName();

    return true;
}

LibInterface::~LibInterface()
{
    dlclose(_libHandler);
}


