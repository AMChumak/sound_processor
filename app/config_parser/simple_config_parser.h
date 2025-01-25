#ifndef SIMPLE_CONFIG_PARSER_HEADER
#define SIMPLE_CONFIG_PARSER_HEADER
#include "config_parser_i.h"
#include <string>
using namespace std;

class simpleConfigParser : public ConfigParserI {
private:
  string configFile;

public:
  simpleConfigParser(string configFile);
  simpleConfigParser() { configFile = ""; };
  simpleConfigParser(const simpleConfigParser &copySource) {
    configFile = copySource.configFile;
  };
  simpleConfigParser(const simpleConfigParser &&moveSource) {
    configFile = moveSource.configFile;
  };
  simpleConfigParser &operator=(const simpleConfigParser &copysource) {
    configFile = copysource.configFile;
    return *this;
  };
  simpleConfigParser &operator=(const simpleConfigParser &&moveSource) {
    configFile = moveSource.configFile;
    return *this;
  };

  virtual int getCommandForOccurrence(int *startPosition,
                                      int sampleSecondNumber,
                                      commandStruct *nextCommand) override;
};

#endif