#include "processor.h"
#include "../exceptions/buisness_exception.h"
#include <exception>
#include <iostream>
#include <memory>
using namespace std;

processor::processor(ConfigParserI *newConfigParser, ConditionKeeper *newKeeper,
                     injectorConvertorCreator *newInjector) {

  configParser = newConfigParser;
  wavKeeper = newKeeper;
  injector = newInjector;
}

int processor::processWAVFile() {
  // окупируем место в памяти под сэмплы
  shared_ptr<char *[]> samples = shared_ptr<char *[]>(new char *[4]);
  for (int i = 0; i < 4; i++) {
    samples.get()[i] = new char[32];
  }
  // //cout << "test main 1" << endl;
  //  переменная для конвертора
  convertorI *currentConvertor;
  // объявление переменной структуры команды
  int *commandFileNumbers = new int[4];
  commandStruct currentCommand = {ProcessorCommands::MUTE, 0,
                                  commandFileNumbers};
  // переменная - итератор для конфиг парсера
  int currentStartPositionConfigFile = 0;

  // основной алгоритм заключается в том что мы идём по сэмплам а внутри
  // основного цикла идём по всем конверторам, также применяем ленивое чтение
  // сэмплов после чего при помощи инжектора создаём конвертор и применяем его
  // //cout << "test main 2" << endl;

  for (int currentSampleNumber = 0;
       wavKeeper->isLessOrEqualFileSize(0, currentSampleNumber);
       ++currentSampleNumber) {
    // берём сэмпл из первого файла
    wavKeeper->getSample(0, currentSampleNumber, samples.get()[0]);
    // идём по конфигу пока читаются новые подходящие команды
    // //cout << "test main 3 currentSampleNumber = " << currentSampleNumber <<
    // endl;
    while (configParser->getCommandForOccurrence(
        &currentStartPositionConfigFile,
        wavKeeper->getSecondNumber(0, currentSampleNumber), &currentCommand)) {
      /*cout << "test main 4 new command getted " << currentCommand.commandType
           << endl;*/
      //    флаг перехода на следующую итерацию
      bool flagContinue = 0;
      // создаём конвертор
      currentConvertor =
          injector->makeInjectionCreator(currentCommand.commandType);
      // //cout << "test main 5 injector " << endl;
      if (currentConvertor == nullptr) {
        // cout << "convertor pointer is null pointer" << endl;
      }
      /*cout << "type of convertor is " << currentCommand.commandType
           << " count files: " << currentCommand.countFiles << endl;*/
      // проверяем что всё нормально и аргументы подходят для конвертора
      if (currentConvertor->checkCountArguments(currentCommand.countFiles)) {
        // готовим аргументы
        for (int currentAuxiliarySampleNumber = 0;
             currentAuxiliarySampleNumber < currentCommand.countFiles;
             currentAuxiliarySampleNumber++) {

          // проверяем помещается ли сэмпл который мы берём в файл по номеру
          // если да, то загружаем его в массив, иначе прерываем всю команду и
          // идём дальше
          // //cout << "test main 6 starts check samples " << endl;
          switch (currentConvertor->getOffset()) {
          case 0: {
            // cout << "Hello from offset " << currentCommand.commandType <<
            // endl;
            if (wavKeeper->isLessOrEqualFileSize(
                    currentCommand.fileNumbers[currentAuxiliarySampleNumber],
                    currentSampleNumber)) {
              try {
                wavKeeper->getSample(
                    currentCommand.fileNumbers[currentAuxiliarySampleNumber],
                    currentSampleNumber,
                    samples.get()[currentAuxiliarySampleNumber + 1]);
                break;
              } catch (SourceFileException &exception) {
                // cout << exception.what() << endl;
                flagContinue = 1;
              } catch (exception &exception) {
                // cout << exception.what() << endl;
                return -1;
              }
            } else {
              flagContinue = 1;
              break;
            }
          }
          case 1: {
            // cout << "Hello from offset " << currentCommand.commandType <<
            // endl;
            if (wavKeeper->isLessOrEqualFileSize(
                    currentCommand.fileNumbers[currentAuxiliarySampleNumber],
                    currentSampleNumber - wavKeeper->getSampleNumber(
                                              0, currentCommand.startSecond))) {
              try {
                wavKeeper->getSample(
                    currentCommand.fileNumbers[currentAuxiliarySampleNumber],
                    currentSampleNumber - wavKeeper->getSampleNumber(
                                              0, currentCommand.startSecond),
                    samples.get()[currentAuxiliarySampleNumber + 1]);
                break;
              } catch (SourceFileException &exception) {
                // cout << exception.what() << endl;
                flagContinue = 1;
              } catch (exception &exception) {
                // cout << exception.what() << endl;
                return -1;
              }
            } else {
              flagContinue = 1;
              break;
            }
          }
          default: {
            flagContinue = 1;
            break;
          }
          }
          if (flagContinue)
            break;
        }
        if (flagContinue)
          continue;
      }
      // //cout << "test main 7 converting starts " << endl;
      //  Теперь, когда файлы подготовлены запускаем конвертор
      currentConvertor->convertSample(samples.get(),
                                      wavKeeper->getSampleSize(0));
      // //cout << "test main 8 converting ends" << endl;
    }
    // //cout << "test main 9 set sample starts " << endl;
    //  После проходу по всем инструкциям сэмпл записывается в выходной файл
    wavKeeper->setSample(samples.get()[0]);
    // сбрасываем счётчик инструкций до нуля
    currentStartPositionConfigFile = 0;
    // //cout << "test main 10 set sample ends " << endl;
  }
  wavKeeper->endProcessing();
  return 0;
}
// Function get help prints available convertors and their descriptions
void processor::getHelp() {
  // cout << "There are available convertors:" << endl;
  convertorI *currentConvertor;
  for (int i = 0; i < CountCommands; i++) {
    currentConvertor = injector->makeInjectionCreator(ProcessorCommands(i + 1));
    // cout << currentConvertor->what() << endl;
  }
}