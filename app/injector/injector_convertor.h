#ifndef INJECTOR_CONVERTOR_CREATOR
#define INJECTOR_CONVERTOR_CREATOR
#include "../convertor/convertor_I.h"
#include "../utils/convertor_types.h"

class injectorConvertorCreator {
public:
  convertorI *makeInjectionCreator(ProcessorCommands convertorType);
};

#endif