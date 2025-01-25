#ifndef CONVERTOR_CREATOR_INTERFACE_HEADER
#define CONVERTOR_CREATOR_INTERFACE_HEADER
#include "convertor_I.h"

class convertorCreatorI {
public:
  virtual convertorI *createConvertor() = 0;
};

#endif