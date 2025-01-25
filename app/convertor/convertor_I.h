#ifndef CONVERTOR_INTERFACE_HEADER
#define CONVERTOR_INTERFACE_HEADER

class convertorI {
public:
  virtual bool checkCountArguments(int countArguments) = 0;
  virtual int getOffset() = 0; // cчитаем, что 0 - без смещения, 1 - смещение до
                               // начала файла
  virtual void convertSample(char **samples, int sampleSize) = 0;
  virtual const char *what() = 0;
};

#endif