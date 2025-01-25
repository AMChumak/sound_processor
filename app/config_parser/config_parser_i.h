#ifndef CONFIG_PARSER_INTERFACE_HEADER
#define CONFIG_PARSER_INTERFACE_HEADER
#include "../utils/command_structure.h"
using namespace std;

class ConfigParserI {
public:
  virtual int getCommandForOccurrence(int *startPosition,
                                      int sampleSecondNumber,
                                      commandStruct *nextCommand) = 0;
};

#endif