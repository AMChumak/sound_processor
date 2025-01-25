#include "wav_files_condition_keeper.h"
#include "../exceptions/buisness_exception.h"
#include "wav_advanced_parser.h"
#include <fstream>
#include <iostream>
#include <memory>
using namespace std;

ConditionKeeper::ConditionKeeper(int countInputFiles, string *inputFiles,
                                 string outputFile) {
  countInputFiles_ = countInputFiles;
  inputFiles_ = inputFiles;
  outputFile_ = outputFile;
  inputHeaders_ = new wavData[countInputFiles];
  inputStartPositions_ = new int[countInputFiles];
  inputStreams_ = new ifstream[countInputFiles];

  parser_ = make_shared<WAVAdvancedParser>();
  ////cout << "test21" << endl;
  // для каждого файла читаем его хэдер и выставляем стартовую позицию
  for (int i = 0; i < countInputFiles; i++) {
    inputStreams_[i].open(inputFiles_[i], fstream::in);
    inputStartPositions_[i] =
        parser_->getHeader(inputFiles_[i], inputStreams_[i], inputHeaders_ + i);
    ////cout << "i: " << i << "| fmt: " << inputHeaders_[i].audioFormat
    //     << "| numch: " << inputHeaders_[i].numChannels << endl;
    if (inputHeaders_[i].audioFormat != 1 ||
        inputHeaders_[i].numChannels != 1) {
      throw SourceFileException("File has no PCM audio format", inputFiles_[i],
                                0);
    }
  }

  ////cout << "test22" << endl;
  // задаём заголовок для выходного файла
  outputHeader_ = inputHeaders_[0];
  outputHeader_.chunkSize = 44; // верно для всех pcm файлов вообще надо писать
                                // -= outputHeader_.subChunk2Size;
  outputHeader_.subChunk2Size = 0;
  // cout << "test23" << endl;
  //  задаём стартовую позицию для выходного файла
  outputStream_.open(outputFile, fstream::out);
  outputStartPosition_ =
      parser_->setHeader(outputFile_, outputStream_, &outputHeader_);
  if (inputStreams_[0]) {
    // cout << "inputStreams_[0] is ok in constructor" << endl;
  }
  // cout << inputFiles_[0] << endl;
}

ConditionKeeper::ConditionKeeper() {
  inputFiles_ = nullptr;
  inputHeaders_ = nullptr;
  inputStartPositions_ = nullptr;
  outputStartPosition_ = 0;
}
ConditionKeeper::ConditionKeeper(const ConditionKeeper &copySource) {
  // cout << "Hello in copy Constructor" << endl;
  countInputFiles_ = copySource.countInputFiles_;
  parser_ = copySource.parser_;
  int countFiles = copySource.inputFiles_->size();
  inputFiles_ = copySource.inputFiles_;
  inputStreams_ = copySource.inputStreams_;
  outputFile_ = copySource.outputFile_;
  outputHeader_ = copySource.outputHeader_;
  outputStream_.close();
  outputStream_.open(outputFile_, fstream::out);
  inputHeaders_ = new wavData[countFiles];
  inputStartPositions_ = new int[countFiles];
  for (int i = 0; i < countFiles; i++) {
    inputHeaders_[i] = copySource.inputHeaders_[i];
    inputStartPositions_[i] = copySource.inputStartPositions_[i];
  }
}
ConditionKeeper::ConditionKeeper(const ConditionKeeper &&moveSource) {
  // cout << "Hello in move Constructor" << endl;
  countInputFiles_ = moveSource.countInputFiles_;
  parser_ = moveSource.parser_;
  int countFiles = moveSource.inputFiles_->size();
  inputFiles_ = moveSource.inputFiles_;
  inputStreams_ = moveSource.inputStreams_;
  outputFile_ = moveSource.outputFile_;
  outputHeader_ = moveSource.outputHeader_;
  outputStream_.close();
  outputStream_.open(outputFile_, fstream::out);
  inputHeaders_ = new wavData[countFiles];
  inputStartPositions_ = new int[countFiles];
  for (int i = 0; i < countFiles; i++) {
    inputHeaders_[i] = moveSource.inputHeaders_[i];
    inputStartPositions_[i] = moveSource.inputStartPositions_[i];
  }
}

ConditionKeeper &ConditionKeeper::operator=(const ConditionKeeper &copySource) {
  // cout << "Yes copy" << endl;
  if (*this == copySource)
    return *this;
  // free old data
  parser_ = copySource.parser_;
  delete[] inputHeaders_;
  inputHeaders_ = nullptr;
  delete[] inputStartPositions_;
  inputStartPositions_ = nullptr;

  countInputFiles_ = copySource.countInputFiles_;
  int countFiles = copySource.inputFiles_->size();
  inputFiles_ = copySource.inputFiles_;
  outputFile_ = copySource.outputFile_;
  outputStream_.close();
  outputStream_.open(outputFile_, fstream::out);
  outputHeader_ = copySource.outputHeader_;
  inputStreams_ = copySource.inputStreams_;
  inputHeaders_ = new wavData[countFiles];
  inputStartPositions_ = new int[countFiles];
  for (int i = 0; i < countFiles; i++) {
    inputHeaders_[i] = copySource.inputHeaders_[i];
    inputStartPositions_[i] = copySource.inputStartPositions_[i];
  }
  return *this;
}

ConditionKeeper &
ConditionKeeper::operator=(const ConditionKeeper &&moveSource) {
  // cout << "Yes move" << endl;
  //  free old data
  delete[] inputHeaders_;
  inputHeaders_ = nullptr;
  // cout << "I am alive after delete headers" << endl;
  delete[] inputStartPositions_;
  inputStartPositions_ = nullptr;
  // cout << "I am alive after delete startPositions" << endl;
  // cout << "I am alive after delete inputStreams" << endl;

  countInputFiles_ = moveSource.countInputFiles_;
  parser_ = moveSource.parser_;
  int countFiles = moveSource.inputFiles_->size();
  inputFiles_ = moveSource.inputFiles_;
  inputStreams_ = moveSource.inputStreams_;
  outputFile_ = moveSource.outputFile_;
  outputHeader_ = moveSource.outputHeader_;
  outputStream_.close();
  outputStream_.open(outputFile_, fstream::out);
  inputHeaders_ = new wavData[countFiles];
  inputStartPositions_ = new int[countFiles];
  for (int i = 0; i < countFiles; i++) {
    inputHeaders_[i] = moveSource.inputHeaders_[i];
    inputStartPositions_[i] = moveSource.inputStartPositions_[i];
  }
  return *this;
}

ConditionKeeper::~ConditionKeeper() noexcept {
  // cout << "Hello in destructor" << endl;
  delete[] inputHeaders_;
  delete[] inputStartPositions_;
}

// сравнение
bool ConditionKeeper::operator==(const ConditionKeeper &a) {
  if (a.inputFiles_ != inputFiles_)
    return false;
  if (a.outputFile_ != outputFile_)
    return false;
  for (int i = 0; i < a.inputFiles_->size(); i++) {
    if (inputHeaders_[i].chunkSize != a.inputHeaders_[i].chunkSize) {
      return false;
    }
    if (inputHeaders_[i].audioFormat != a.inputHeaders_[i].audioFormat) {
      return false;
    }
    if (inputHeaders_[i].bitsPerSample != a.inputHeaders_[i].bitsPerSample) {
      return false;
    }
    if (inputHeaders_[i].subChunk1Size != a.inputHeaders_[i].subChunk1Size) {
      return false;
    }
    if (inputHeaders_[i].subChunk2Size != a.inputHeaders_[i].subChunk2Size) {
      return false;
    }
    if (inputHeaders_[i].extraParamSize != a.inputHeaders_[i].extraParamSize) {
      return false;
    }
    if (inputHeaders_[i].numChannels != a.inputHeaders_[i].numChannels) {
      return false;
    }
    if (inputHeaders_[i].blockAlign != a.inputHeaders_[i].blockAlign) {
      return false;
    }
    if (inputHeaders_[i].byteRate != a.inputHeaders_[i].byteRate) {
      return false;
    }
    if (inputHeaders_[i].sampleRate != a.inputHeaders_[i].sampleRate) {
      return false;
    }
    if (inputStartPositions_[i] != a.inputStartPositions_[i]) {
      return false;
    }
  }
  return true;
}

int ConditionKeeper::getSample(int fileNumber, int sampleNumber, char *sample) {
  // cout << inputFiles_[0] << endl;
  // cout << inputStartPositions_[0] << endl;
  if (inputStreams_[0]) {
    // cout << "inputStream[0] in GETSAMPLE is OK" << endl;
  }
  // cout << inputHeaders_[0].bitsPerSample << endl;

  parser_->getSample("mock.wav", inputStreams_[fileNumber],
                     inputStartPositions_[fileNumber] +
                         sampleNumber *
                             inputHeaders_[fileNumber].bitsPerSample / 8,
                     inputHeaders_[fileNumber].bitsPerSample / 8, sample);

  return 1;
}

int ConditionKeeper::setSample(char *sample) {
  // cout << "OUTPUT HEADER INFO 1: "
  //<< "chunk size is: " << outputHeader_.chunkSize
  //<< " | data subchunk size is: " << outputHeader_.subChunk2Size << endl;
  outputHeader_.chunkSize += outputHeader_.bitsPerSample / 8;
  outputHeader_.subChunk2Size += outputHeader_.bitsPerSample / 8;
  // cout << "OUTPUT HEADER INFO 2: "
  //<< "chunk size is: " << outputHeader_.chunkSize
  //<< " | data subchunk size is: " << outputHeader_.subChunk2Size << endl;
  return parser_->addSample(outputFile_, outputStream_,
                            outputHeader_.bitsPerSample / 8, sample);
}

// end processing
int ConditionKeeper::endProcessing() {
  // cout << "Hello in end proccesing" << endl;
  for (int i = 0; i < countInputFiles_; i++) {
    inputStreams_[i].close();
  }
  // cout << "I am alive still in end processing" << endl;
  outputStream_.close();
  return parser_->updateHeader(outputFile_, &outputHeader_);
}

bool ConditionKeeper::isLessOrEqualFileSize(int fileNumber, int sampleNumber) {
  // cout << "FILE SIZE IS "
  //<< inputHeaders_[fileNumber].subChunk2Size /
  //        (inputHeaders_[fileNumber].bitsPerSample / 8)
  //<< endl;
  // cout << "current number is " << sampleNumber << endl;
  return (sampleNumber <= inputHeaders_[fileNumber].subChunk2Size /
                              (inputHeaders_[fileNumber].bitsPerSample / 8));
}

int ConditionKeeper::getSecondNumber(int fileNumber, int sampleNumber) {
  return sampleNumber / inputHeaders_[fileNumber].sampleRate;
}

int ConditionKeeper::getSampleNumber(int fileNumber, int secondNumber) {
  return secondNumber * inputHeaders_[fileNumber].sampleRate;
}

int ConditionKeeper::getSampleSize(int fileNumber) {
  return inputHeaders_[fileNumber].bitsPerSample / 8;
}