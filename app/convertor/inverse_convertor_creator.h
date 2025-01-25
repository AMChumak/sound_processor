#ifndef REVERSE_CONVERTOR_CREATOR_INTERFACE_HEADER
#define REVERSE_CONVERTOR_CREATOR_INTERFACE_HEADER
#include "convertor_I.h"
#include "convertor_creator_I.h"

class inverseConvertorCreator : public convertorCreatorI {
public:
  virtual convertorI *createConvertor() override;
};

#endif