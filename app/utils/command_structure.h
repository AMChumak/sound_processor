#ifndef COMMAND_STRUCTURE_HEADER
#define COMMAND_STRUCTURE_HEADER
#include "convertor_types.h"

typedef struct processorCommandStruct {
  ProcessorCommands commandType;
  int countFiles;
  int *fileNumbers;
  int startSecond;
} commandStruct;

#endif