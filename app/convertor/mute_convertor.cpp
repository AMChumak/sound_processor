#include "mute_convertor.h"

// converSample mutes samples. It change sample's value on 0.
// sample size - size in bytes
void muteConvertor::convertSample(char **samples, int sampleSize) {

  char *currentSample = samples[0];
  for (int j = 0; j < sampleSize; j++) {
    currentSample[j] = 0;
  }
}

const char *muteConvertor::what() {
  return "Mute convertor mutes the interval. Command is \"mute m n\", where m "
         "is the beginning of the interval and n is the ending of the interval";
}

bool muteConvertor::checkCountArguments(int countArguments) {
  return countArguments == 0;
}
int muteConvertor::getOffset() { return 0; }