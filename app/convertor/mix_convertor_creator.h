#ifndef MIX_CONVERTOR_CREATOR_INTERFACE_HEADER
#define MIX_CONVERTOR_CREATOR_INTERFACE_HEADER
#include "convertor_I.h"
#include "convertor_creator_I.h"

class mixConvertorCreator : public convertorCreatorI {
public:
  virtual convertorI *createConvertor() override;
};

#endif