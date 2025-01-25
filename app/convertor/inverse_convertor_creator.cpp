#include "inverse_convertor_creator.h"
#include "inverse_convertor.h"

convertorI *inverseConvertorCreator::createConvertor() {
  return new inverseConvertor();
}