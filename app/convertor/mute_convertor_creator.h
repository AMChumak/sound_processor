#ifndef MUTE_CONVERTOR_CREATOR_INTERFACE_HEADER
#define MUTE_CONVERTOR_CREATOR_INTERFACE_HEADER
#include "convertor_I.h"
#include "convertor_creator_I.h"

class muteConvertorCreator : public convertorCreatorI {
public:
  virtual convertorI *createConvertor() override;
};

#endif