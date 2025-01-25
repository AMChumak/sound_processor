#ifndef WAV_ADVANCED_PARSER
#define WAV_ADVANCED_PARSER
#include "wav_parser_I.h"
#include <fstream>

class WAVAdvancedParser : public WAVFormatParserI {
public:
  // contract for reading WAV-file

  virtual int getHeader(string inputFile, ifstream &inputFileStream,
                        wavData *resultFile) override;

  virtual int getSample(string inputFile, ifstream &inputFileStream,
                        int startPosition, int sampleSize,
                        char *sampleBuffer) override;

  // contract for writing WAV-file
  virtual int setHeader(string outputFile, ofstream &outputFileStream,
                        wavData *sourceFile) override;

  int addSample(string outputFile, ofstream &outputFileStream, int SampleSize,
                char *sampleBuffer) override;

  int updateHeader(string outputFile, wavData *updatedHeader) override;
};
#endif