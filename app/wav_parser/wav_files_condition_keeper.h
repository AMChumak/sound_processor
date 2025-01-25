#ifndef WAV_FILES_CONDITION_KEEPER_HEADER
#define WAV_FILES_CONDITION_KEEPER_HEADER
#include "../utils/wav_data_structure.h"
#include "wav_parser_I.h"
#include <fstream>
#include <memory>
#include <string>
using namespace std;

class ConditionKeeper {
private:
  // количество файлов
  int countInputFiles_;
  // множество названий входных файлов
  string *inputFiles_;
  // множество хэдеров
  wavData *inputHeaders_;
  // множество начальных позиций для входных файлов
  int *inputStartPositions_;
  // множество входных потоков
  ifstream *inputStreams_;
  // название выходного файла
  string outputFile_;
  // хэдер выходного файла
  wavData outputHeader_;
  // стартовая позиция для выходного файла
  int outputStartPosition_;
  // выходной поток
  ofstream outputStream_;
  // парсер
  shared_ptr<WAVFormatParserI> parser_;

public:
  // Метод инициализации
  ConditionKeeper(int countInputFiles, string *inputFiles, string outputFile);
  ConditionKeeper();
  ConditionKeeper(const ConditionKeeper &copySource);
  ConditionKeeper(const ConditionKeeper &&moveSource);
  ConditionKeeper &operator=(const ConditionKeeper &copySource);
  ConditionKeeper &operator=(const ConditionKeeper &&moveSource);
  // Деструктор
  ~ConditionKeeper() noexcept;
  // оператор сравнения
  bool operator==(const ConditionKeeper &a);

  // метод взятия сэмпла
  int getSample(int fileNumber, int sampleNumber, char *sample);
  // метод написания сэмпла
  int setSample(char *sample);

  int endProcessing();

  // метод проверки, что сэмпл еще попадает во входной файл
  bool isLessOrEqualFileSize(int fileNumber, int sampleNumber);
  // метод возвращающий номер секунлы, которой принадлежит сэмпл с данным
  // номером в данном файле
  int getSecondNumber(int fileNumber, int sampleNumber);
  // метод взятия первого номера сэмпла данной секунды в данном файле
  int getSampleNumber(int fileNumber, int secondNumber);
  // метод взятия размера одного сэмпла в байтах для нужного файла
  int getSampleSize(int fileNumber);
};

#endif