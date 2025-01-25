#include "mute_convertor_creator.h"
#include "mute_convertor.h"

convertorI *muteConvertorCreator::createConvertor() {
  return new muteConvertor();
}