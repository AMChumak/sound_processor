#ifndef MUTE_CONVERTOR_HEADER
#define MUTE_CONVERTOR_HEADER
#include "convertor_I.h"

class muteConvertor : public convertorI {
public:
  virtual bool checkCountArguments(int countArguments) override;
  virtual int getOffset() override;
  virtual void convertSample(char **samples, int sampleSize) override;
  virtual const char *what() override;
};

#endif