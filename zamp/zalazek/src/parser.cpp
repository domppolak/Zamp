#include "parser.hh"

bool Parser::parseCMD(std::istringstream &Istrm4Cmds)
{
  std::string Cmd4Preproc = "cpp -P ";
  constexpr size_t LINE_SIZE = 500;
  char Line[LINE_SIZE];
  std::ostringstream OTmpStrm;

  Cmd4Preproc += cmdFile.c_str();
  FILE * pProc = popen(Cmd4Preproc.c_str(), "r");

  if (!pProc)
    return false;

  while (fgets(Line, LINE_SIZE, pProc)) {
    OTmpStrm << Line;
  }

  Istrm4Cmds.str(OTmpStrm.str());
  return pclose(pProc) == 0;
}

bool Parser::parseXML()
{

}