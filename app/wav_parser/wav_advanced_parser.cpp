#include "wav_advanced_parser.h"
#include "../exceptions/buisness_exception.h"
#include <cstring>
#include <fstream>
#include <ios>
#include <iostream>
#include <string>
using namespace std;

// function for avoid nullptr safety
// return  count of readed data
int safetyRead(ifstream *stream, int length, char *buffer) {
  if (buffer == nullptr) {
    stream->seekg(length, ios_base::cur);
    return 0;
  } else {
    stream->read(reinterpret_cast<char *>(buffer), length);
    return 1;
  }
}

// This function reads first and second subchunks without Data segment. It sets
// information from subhunks 1 and 2 and checks format of the file. Functions
// returns position of start of data segment in file
// returns -1 if error occur
int WAVAdvancedParser::getHeader(string inputFile, ifstream &inputFileStream,
                                 wavData *resultFile) {
  char checkbuffer[5] = {0};
  short audioFormat = -1;

  // check file path
  if (!inputFileStream) {
    throw SourceFileException("incorrect file name", inputFile, 0);
    // throw incorrect file path
    return -1;
  }

  // check RIFF
  inputFileStream.read(checkbuffer, 4);
  if (strcmp(checkbuffer, "RIFF") != 0) {
    throw SourceFileException("incorrect file format, no RIFF", inputFile, 0);
    // throw incorrect file format (no RIFF)
    return -1;
  }

  // get chunk size
  if (resultFile != nullptr) {
    inputFileStream.read(reinterpret_cast<char *>(&resultFile->chunkSize), 4);
  }

  // check WAVE format
  inputFileStream.read(checkbuffer, 4);
  if (strcmp(checkbuffer, "WAVE") != 0) {
    throw SourceFileException("incorrect file format, no WAVE", inputFile, 8);
    // throw incorrect file format (no WAVE)
    return -1;
  }

  // check fmt ID
  inputFileStream.read(checkbuffer, 4);
  if (strcmp(checkbuffer, "fmt ") != 0) {
    // throw incorrect file format (no WAVE)
    throw SourceFileException("incorrect file format, no str fmt", inputFile,
                              12);
    return -1;
  }

  // get format subchunk size
  if (resultFile != nullptr) {
    if (!safetyRead(&inputFileStream, 4,
                    reinterpret_cast<char *>(&resultFile->subChunk1Size)))
      throw SourceFileException("file has no subchunk size", inputFile,
                                (int)inputFileStream.tellg() - 4);
  }
  // get audio format
  if (resultFile != nullptr) {
    if (!safetyRead(&inputFileStream, 2,
                    reinterpret_cast<char *>(&resultFile->audioFormat)))
      throw SourceFileException("file has no audio format", inputFile,
                                (int)inputFileStream.tellg() - 2);
    audioFormat = resultFile->audioFormat;
  }
  // get number of channels
  if (resultFile != nullptr) {
    if (!safetyRead(&inputFileStream, 2,
                    reinterpret_cast<char *>(&resultFile->numChannels)))
      throw SourceFileException("file has no number of channels", inputFile,
                                (int)inputFileStream.tellg() - 2);
  }
  // get sample rate
  if (resultFile != nullptr) {
    if (!safetyRead(&inputFileStream, 4,
                    reinterpret_cast<char *>(&resultFile->sampleRate)))
      throw SourceFileException("file has no sample rate", inputFile,
                                (int)inputFileStream.tellg() - 4);
  }
  // get byte rate
  if (resultFile != nullptr) {
    if (!safetyRead(&inputFileStream, 4,
                    reinterpret_cast<char *>(&resultFile->byteRate)))
      throw SourceFileException("file has no byte rate", inputFile,
                                (int)inputFileStream.tellg() - 4);
  }
  // get block align
  if (resultFile != nullptr) {
    if (!safetyRead(&inputFileStream, 2,
                    reinterpret_cast<char *>(&resultFile->blockAlign)))
      throw SourceFileException("file has no block align", inputFile,
                                (int)inputFileStream.tellg() - 2);
  }
  // get bits per sample
  if (resultFile != nullptr) {
    if (!safetyRead(&inputFileStream, 2,
                    reinterpret_cast<char *>(&resultFile->bitsPerSample)))
      throw SourceFileException("file has no bits per sample", inputFile,
                                (int)inputFileStream.tellg() - 2);
  }
  // get extra parameters
  if (audioFormat != -1 &&
      audioFormat !=
          1) { // проверка на то определён ли тип и не равен ли он 1, если тип
               // определён, то ссылка в аргументе функции явноw не нулевая
    // inputFileStream.read(reinterpret_cast<char *>(extraParamSize), 2);
    safetyRead(&inputFileStream, 2,
               reinterpret_cast<char *>(&resultFile->extraParamSize));
    char *dataBuffer = new char[resultFile->extraParamSize];
    if (resultFile->extraParams != nullptr) {
      safetyRead(&inputFileStream, resultFile->extraParamSize,
                 reinterpret_cast<char *>(dataBuffer));
      resultFile->extraParams = dataBuffer;
    }
  } else if (audioFormat != -1) {
    resultFile->extraParamSize = 0;
    resultFile->extraParams = nullptr;
  }

  // check subchunk data ID
  inputFileStream.read(checkbuffer, 4);
  if (strcmp(checkbuffer, "data") != 0) {
    throw SourceFileException(
        "incorrect format of file, it has no data section", inputFile,
        (int)inputFileStream.tellg() - 4);
    // throw incorrect file format (no data)
    return -1;
  }
  // get data subchunk size
  if (resultFile != nullptr) {
    if (!safetyRead(&inputFileStream, 4,
                    reinterpret_cast<char *>(&resultFile->subChunk2Size)))
      throw SourceFileException("file has no size of data subchunk", inputFile,
                                (int)inputFileStream.tellg() - 4);
  }
  // close file and return position of data segment start
  int currentPosition = inputFileStream.tellg();
  return currentPosition;
}

// getSample function gets sample in sampleBuffer
// sampleSize in bytes
// returns count of successfully taken samples
int WAVAdvancedParser::getSample(string inputFile, ifstream &inputFileStream,
                                 int startPosition, int sampleSize,
                                 char *sampleBuffer) {
  ////cout << "Hey I am still alive" << endl;
  // go on start of sample
  inputFileStream.seekg(startPosition, ios_base::beg);

  // check end of file
  if (inputFileStream.eof()) {
    return 0;
  }

  // get sample
  // inputFileStream.read(sampleBuffer, sampleSize);
  safetyRead(&inputFileStream, sampleSize, sampleBuffer);

  return 1;
}

// setHeader function writes info to header
// returns length of file by bytes
int WAVAdvancedParser::setHeader(string outputFile, ofstream &outputFileStream,
                                 wavData *sourceFile) {
  // write RIFF chunk descriptor
  outputFileStream.write("RIFF", 4);
  outputFileStream.write(reinterpret_cast<const char *>(&sourceFile->chunkSize),
                         4);
  outputFileStream.write("WAVE", 4);

  // write info in format subchunk
  outputFileStream.write("fmt ", 4);

  outputFileStream.write(
      reinterpret_cast<const char *>(&sourceFile->subChunk1Size), 4);
  outputFileStream.write(
      reinterpret_cast<const char *>(&sourceFile->audioFormat), 2);
  outputFileStream.write(
      reinterpret_cast<const char *>(&sourceFile->numChannels), 2);
  outputFileStream.write(
      reinterpret_cast<const char *>(&sourceFile->sampleRate), 4);
  outputFileStream.write(reinterpret_cast<const char *>(&sourceFile->byteRate),
                         4);
  outputFileStream.write(
      reinterpret_cast<const char *>(&sourceFile->blockAlign), 2);
  outputFileStream.write(
      reinterpret_cast<const char *>(&sourceFile->bitsPerSample), 2);

  if (sourceFile->audioFormat != 1) {
    outputFileStream.write(
        reinterpret_cast<const char *>(&sourceFile->extraParamSize), 4);
    outputFileStream.write(sourceFile->extraParams, sourceFile->extraParamSize);
  }
  outputFileStream.write("data", 4);
  outputFileStream.write(
      reinterpret_cast<const char *>(&sourceFile->subChunk2Size), 4);

  return outputFileStream.tellp();
}

// addSample function adds new sample from sampleBuffer to file and increase all
// sizes. It returns count of successfully added samples.
int WAVAdvancedParser::addSample(string outputFile, ofstream &outputFileStream,
                                 int sampleSize, char *sampleBuffer) {
  int chunkSize = 0, fmtSubChunkSize = 0, dataSubChunkSize = 0;

  ////cout << "CHAR in addSample: " << (int)sampleBuffer[0] << " "<<
  ///(int)sampleBuffer[1] << endl;

  // go to the end and add new sample
  outputFileStream.seekp(0, ios_base::end);
  outputFileStream.write(reinterpret_cast<const char *>(sampleBuffer),
                         sampleSize);
  return 1;
}

int WAVAdvancedParser::updateHeader(string outputFile, wavData *updatedHeader) {
  int chunkSize = 0, fmtSubChunkSize = 0, dataSubChunkSize = 0;
  ifstream inputFileStream;
  inputFileStream.open(outputFile, fstream::in);
  inputFileStream.seekg(4, ios_base::cur);
  inputFileStream.read(reinterpret_cast<char *>(&chunkSize), 4);
  inputFileStream.seekg(8, ios_base::cur);
  inputFileStream.read(reinterpret_cast<char *>(&fmtSubChunkSize), 4);
  inputFileStream.seekg(fmtSubChunkSize + 4, ios_base::cur);
  inputFileStream.read(reinterpret_cast<char *>(&dataSubChunkSize), 4);
  inputFileStream.close();
  // increase sizes
  ofstream outputFileStream;
  outputFileStream.open(outputFile, fstream::in | fstream::ate);
  outputFileStream.seekp(4, ios_base::beg);
  chunkSize = updatedHeader->chunkSize;
  outputFileStream.write(reinterpret_cast<const char *>(&chunkSize), 4);

  outputFileStream.seekp(8 + 4 + fmtSubChunkSize + 4, ios_base::cur);
  dataSubChunkSize = updatedHeader->subChunk2Size;
  outputFileStream.write(reinterpret_cast<const char *>(&dataSubChunkSize), 4);
  outputFileStream.close();
  return 1;
}