#include "simple_config_parser.h"
#include "../exceptions/buisness_exception.h"
#include "../utils/convertor_types.h"
#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
using namespace std;

// Конструктор
simpleConfigParser::simpleConfigParser(string configFile) {
  this->configFile = configFile;
}

template <class resultType>
int getSafeFromStringStream(stringstream *stream, resultType *data,
                            resultType defaultValue);

// getCommandOccurence method reads config file beginning at startPosition and
// filters commands by time. It sets nextCommand. if it find neccessary command
// it will return 1, else it will return 0
// error return code is -1
int simpleConfigParser::getCommandForOccurrence(int *startPosition,
                                                int sampleSecondNumber,
                                                commandStruct *nextCommand) {
  // переменные для будущего анализа
  int startInterval = -2, finishInterval = -2, goalSecond = sampleSecondNumber,
      currentFileNumber = -1;
  char checkCharBuffer[100] = {0};
  string stringBuffer = checkCharBuffer;
  ifstream inputFileStream;
  // //cout << "test config 1" << endl;
  //  открываем файл и смещаемся на начальную позицию
  inputFileStream.open(configFile, fstream::in);
  inputFileStream.seekg(*startPosition, ios_base::beg);

  // инициализирую дефолтные значения на случай если они не указаны в команде
  nextCommand->startSecond = 0;
  nextCommand->commandType = ProcessorCommands::LAST;
  // //cout << "test config 2 cycle begins" << endl;
  //  идём по командам и выбираем первую подходящую по времени
  while (!inputFileStream.eof()) {
    currentFileNumber = -1;
    stringstream checkStringStream;
    startInterval = -2, finishInterval = -2, goalSecond = sampleSecondNumber,
    currentFileNumber = -1;
    for (int k = 0; k < 100; k++)
      checkCharBuffer[k] = 0;
    stringBuffer = checkCharBuffer;
    try {
      int beginOfCurrentLine = inputFileStream.tellg();
      getline(inputFileStream, stringBuffer);
      // проверка на конец файла
      if (stringBuffer[0] == 0) {
        return 0;
      }
      checkStringStream << stringBuffer;
      /*cout << "Start position is " << *startPosition << "current string is "
           << stringBuffer << endl;*/
      string commandType = "";
      checkStringStream >> commandType;
      // cout << "commandType is " << commandType << endl;
      //  //cout << "test config 3 get stringStream" << endl;
      //   считываем все аргументы в переменные, заодно проверяем их количество
      string currentArgument;
      startInterval = -2;
      finishInterval = -2;
      if (goalSecond >= 10) {
        // cout << "test config 4 proccesing arguments begins" << endl;
        // cout << "current string is \"" << stringBuffer << "\"" << endl;
      }
      while (!checkStringStream.eof()) {
        getSafeFromStringStream(&checkStringStream, &currentArgument,
                                static_cast<string>("0"));
        // cout << "current argument is " << currentArgument << endl;
        if (currentArgument[0] ==
            '$') { // проверяем, что это номер файла или время
          currentArgument = currentArgument.substr(1, currentArgument.length() -
                                                          1); // убираем $
          if (currentFileNumber == -1) {
            currentFileNumber = stoi(currentArgument);
          } else {
            // cout << "Too many" << endl;
            throw ConfigException("Too many arguments of type $x", commandType,
                                  beginOfCurrentLine);
          }
        } else {
          // если ещё не заполнен стартовый момент работы конвертора, то
          // заполняю его, иначе финиш
          if (startInterval == -2) {
            startInterval = stoi(currentArgument);
            if (startInterval < 0) {
              startInterval = 0;
            }
          } else if (finishInterval == -2) {
            finishInterval = stoi(currentArgument);
            if (startInterval < 0) {
              finishInterval = -1;
            }
          } else {
            // cout << "yes it is" << endl;
            throw ConfigException("Too many arguments of type timestep",
                                  commandType, beginOfCurrentLine);
          }
        }
      }
      // //cout << "test config 5 check time" << endl;
      //  проверяем какие данные удалось считать и достаточно ли этого
      if (startInterval == -2) {
        startInterval = 0;
      }
      if (finishInterval == -2) {
        finishInterval = -1;
      }

      // проверяем подходят ли эти временные рамки, если да, то возвращаем
      // команду
      // //cout << "test config 6 start filling answer" << endl;
      if (startInterval <= goalSecond &&
          (goalSecond < finishInterval || finishInterval == -1)) {
        // проверяем подходит ли нам этот тип
        // cout << "current type ------------- " << commandType << endl;
        nextCommand->commandType = ProcessorCommands::LAST;
        for (int i = 0; i < CountCommands; i++) {
          if (commandType == ConsoleProcessorCommands[i]) {
            nextCommand->commandType = ProcessorCommands(i);
          }
        }
        if (nextCommand->commandType == ProcessorCommands::LAST) {
          throw ConfigException("Incorrect convertor type, available type",
                                commandType, beginOfCurrentLine);
        }
        // //cout << "test config 7 filling in process" << endl;
        //  заполняем данные о команде
        if (currentFileNumber != -1) {
          if (nextCommand->fileNumbers == nullptr) {
            // cout << "incorrect command structure. It has nullptr in "
            // "fileNumbres array"<< endl;
            return 0;
          }
          nextCommand->fileNumbers[0] = currentFileNumber;
          nextCommand->countFiles = 1;
        } else {
          nextCommand->countFiles = 0;
        }
        nextCommand->startSecond = startInterval;
        // //cout << "test config 8" << endl;
        //  смещаемся до текущей позиции для следующего вхождения и закрываем
        //  файл, код возврата - успех
        *startPosition = inputFileStream.tellg();
        inputFileStream.close();
        // cout << "Result: type - " << nextCommand->commandType
        //      << " countFiles - " << nextCommand->countFiles << endl;
        return 1;
      }
    } catch (ProcessorException &exception) {
      // cout << " hello from Africa" << endl;
      //  cout << exception.what() << endl;
    }
  }
  return 0;
}

// getSafeFromStringStream checks stringstream before getting data from there.
// If incorrect stream sets defaultValue returns 0 if all is OK, else -1
template <class resultType>
int getSafeFromStringStream(stringstream *stream, resultType *data,
                            resultType defaultValue) {
  if (*stream) {
    (*stream) >> *data;
    return 0;
  } else {
    *data = defaultValue;
    return -1;
  }
}
