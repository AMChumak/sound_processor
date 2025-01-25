#include "inverse_convertor.h"

// convertSample gets last second sample makes it more quite and add to first
// sample sample size in bytes
void inverseConvertor::convertSample(char **samples, int sampleSize) {
  for (int j = 0; j < sampleSize; ++j) {
    (samples[0])[j] = 0.5 * ((samples[0])[j]);
  }
}

const char *inverseConvertor::what() {
  return "Inverse convertor makes inversion on the interval. Command is "
         "\"inverse m n\", "
         "where m "
         "is the beginning of the interval and n is the ending of the interval";
}

bool inverseConvertor::checkCountArguments(int countArguments) {
  return countArguments = 0;
}
int inverseConvertor::getOffset() { return 0; }