#ifndef WAV_PARSER_I
#define WAV_PARSER_I
#include "../utils/wav_data_structure.h"
#include <fstream>
#include <string>
using namespace std;

class WAVFormatParserI {
public:
  // contract for reading WAV-file
  virtual int getHeader(string inputFile, ifstream &inputFileStream,
                        wavData *resultFile) = 0;

  virtual int getSample(string inputFile, ifstream &inputFileStream,
                        int startPosition, int sampleSize,
                        char *sampleBuffer) = 0;

  // contract for writing WAV-file
  virtual int setHeader(string outputFile, ofstream &outputFileStream,
                        wavData *sourceFile) = 0;

  virtual int addSample(string outputFile, ofstream &outputFileStream,
                        int sampleSize, char *sampleBuffer) = 0;
  virtual int updateHeader(string outputFile, wavData *updatedHeader) = 0;
};
#endif