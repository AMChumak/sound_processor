#include "config_parser/simple_config_parser.h"
#include "exceptions/buisness_exception.h"
#include "injector/injector_convertor.h"
#include "processor/processor.h"
#include "wav_parser/wav_files_condition_keeper.h"
#include <cstring>
#include <iostream>
using namespace std;

int main(int argc, char **argv) {

  // парсим входные данные в команде

  string *inputFiles = new string[argc];
  string outputFile = "", configFile = "";
  int isHelp = 0;
  int firstFileIndex = -1;
  for (int i = 0; i < argc; i++) {
    if (strcmp(argv[i], "-h") == 0) {
      isHelp = 1;
    } else if (strcmp(argv[i], "-c") == 0) {
      firstFileIndex = i + 1;
    } else {
      if (i - firstFileIndex == 0) {
        configFile = argv[i];
      } else if (i - firstFileIndex == 1) {
        outputFile = argv[i];
      } else {
        inputFiles[i - firstFileIndex - 2] = argv[i];
      }
    }
  }
  // fix incorrect values
  if (firstFileIndex == -1) {
    firstFileIndex = argc;
  }

  char **coreSamples = new char *[4];
  for (int i = 0; i < 4; ++i) {
    coreSamples[i] = new char[8];
  }
  // cout << "files------------ " << firstFileIndex << " "<< argc -
  // firstFileIndex - 2 << endl;
  for (int i = 0; i < argc - firstFileIndex - 2; i++) {
    // cout << inputFiles[i] << endl;
  }
  // cout << "--------------" << endl;

  // инициализируем основные серверы
  try {
    simpleConfigParser processorConfigParser = simpleConfigParser(configFile);
    // cout << "test1" << endl;
    ConditionKeeper procesorWAVFilesKeeper =
        ConditionKeeper((argc - firstFileIndex - 2), inputFiles, outputFile);
    // cout << "test2" << endl;
    injectorConvertorCreator processorInjector = injectorConvertorCreator();
    // cout << "test3" << endl;
    //  инициализируем актора
    processor mainProcessor = processor(
        &processorConfigParser, &procesorWAVFilesKeeper, &processorInjector);
    // cout << "test4" << endl;
    //  запуск работы
    if (isHelp) {
      mainProcessor.getHelp();
    } else {
      mainProcessor.processWAVFile();
    }
  } catch (ProcessorException &exception) {
    // cout << exception.what() << endl;
  }

  // очистка памяти
  delete[] coreSamples;
  delete[] inputFiles;
  return 0;
}