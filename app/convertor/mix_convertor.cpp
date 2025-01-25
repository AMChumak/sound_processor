#include "mix_convertor.h"

// convertSample takes first sample value and second sample value summs these
// and put in first sample
// sampleSize in bytes
void mixConvertor::convertSample(char **samples, int sampleSize) {
  if (sampleSize == 2) {
    short result = *(reinterpret_cast<short *>(samples[0])) / 2 +
                   *(reinterpret_cast<short *>(samples[1])) / 2;
    *(reinterpret_cast<short *>(samples[0])) = result;
  }
}

const char *mixConvertor::what() {
  return "Mix convertor mixes intervals. Command is \"mute $num start\", "
         "where num "
         "is the number of the auxiliary file and start is the beginning of "
         "mixed interval";
}

bool mixConvertor::checkCountArguments(int countArguments) {
  return countArguments = 1;
}
int mixConvertor::getOffset() { return 1; }