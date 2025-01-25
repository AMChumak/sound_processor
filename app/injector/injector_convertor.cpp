#include "injector_convertor.h"
#include "../convertor/inverse_convertor_creator.h"
#include "../convertor/mix_convertor_creator.h"
#include "../convertor/mute_convertor_creator.h"
#include <iostream>

// Основной метод инжектора: выбирает фабрику и создаёт конвекртор, в случае
// ошибки возвращает nullptr
convertorI *injectorConvertorCreator::makeInjectionCreator(
    ProcessorCommands convertorType) {
  switch (convertorType) {
  case 0: {
    muteConvertorCreator creator;
    return creator.createConvertor();
    break;
  }
  case 1: {
    mixConvertorCreator creator;
    return creator.createConvertor();
    break;
  }
  case 2: {
    inverseConvertorCreator creator;
    return creator.createConvertor();
    break;
  }
  default:
    return nullptr;
    break;
  }
}