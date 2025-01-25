#ifndef PROCESSOR_HEADER
#define PROCESSOR_HEADER
#include "../config_parser/config_parser_i.h"
#include "../injector/injector_convertor.h"
#include "../wav_parser/wav_files_condition_keeper.h"

class processor {
private:
  ConfigParserI *configParser;
  ConditionKeeper *wavKeeper;
  injectorConvertorCreator *injector;

public:
  processor(ConfigParserI *newConfigParser, ConditionKeeper *newKeeper,
            injectorConvertorCreator *newInjector);
  int processWAVFile();
  void getHelp();
};

#endif