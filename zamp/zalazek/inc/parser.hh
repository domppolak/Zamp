#ifndef _PARSER_HH
#define _PARSER_HH

#include <string>
#include <iostream>
#include <sstream>

//#include "xmlinterp.hh"

class Parser
{

public:
    void setCmdFile(std::string file) {cmdFile = file; }
    void setXMLFile(std::string file) {xmlFile = file; }

    bool parseCMD(std::istringstream &Istrm4Cmds);
    bool parseXML();

private:
    std::string cmdFile;
    std::string xmlFile;
};

#endif