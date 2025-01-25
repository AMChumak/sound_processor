#ifndef CONVERTOR_TYPES_HEADER
#define CONVERTOR_TYPES_HEADER
#include <string>
using namespace std;

enum ProcessorCommands { MUTE = 0, MIX = 1, INVERSE = 2, LAST = 3 };

const int CountCommands = 3;

const string ConsoleProcessorCommands[3] = {"mute", "mix", "inverse"};

#endif