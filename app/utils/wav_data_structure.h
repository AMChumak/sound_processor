#ifndef WAV_DATA_STRUCTURE_HEADER
#define WAV_DATA_STRUCTURE_HEADER

typedef struct WAVDataStruct {
  int chunkSize;
  int subChunk1Size;
  short audioFormat;
  short numChannels;
  int sampleRate;
  int byteRate;
  short blockAlign;
  short bitsPerSample;
  int extraParamSize;
  char *extraParams;
  int subChunk2Size;
} wavData;

#endif