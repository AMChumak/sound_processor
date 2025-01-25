#include "mix_convertor_creator.h"
#include "mix_convertor.h"

convertorI *mixConvertorCreator::createConvertor() {
  return new mixConvertor();
}