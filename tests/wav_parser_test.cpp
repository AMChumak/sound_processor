#include "../utils/wav_data_structure.h"
#include "wav_advanced_parser.h"
#include "gtest/gtest.h"
#include <fstream>
#include <iostream>

namespace {
class WAVParserTest : public testing::Test {
public:
  WAVAdvancedParser parser;
  ifstream inputFileStream;
  ofstream outputFileStream;
  string file;
  wavData testHeader;

protected:
  void SetUp() override { parser = WAVAdvancedParser(); }

  void TearDown() override {}
};
} // namespace

TEST_F(WAVParserTest, correct_file_test) {
  inputFileStream.open("../tests/test_files/birth.wav", fstream::in);
  int fileLength = parser.getHeader("../tests/test_files/birth.wav",
                                    inputFileStream, &testHeader);
  inputFileStream.close();
  // cout << fileLength << endl;
  ASSERT_EQ(testHeader.sampleRate, 44100);
}

TEST_F(WAVParserTest, creating_header_test) {
  inputFileStream.open("../tests/test_files/birth.wav", fstream::in);
  int fileLength = parser.getHeader("../tests/test_files/birth.wav",
                                    inputFileStream, &testHeader);
  inputFileStream.close();
  /*//cout << "chunk size:" << testHeader.chunkSize << endl
       << "subChunk 1:" << testHeader.subChunk1Size << endl
       << "subChunk2 " << testHeader.subChunk2Size << endl;*/
  testHeader.chunkSize -= testHeader.subChunk2Size;
  testHeader.subChunk2Size = 0;
  outputFileStream.open("test_result.wav", fstream::out);
  parser.setHeader("test_result.wav", outputFileStream, &testHeader);
  outputFileStream.close();
  inputFileStream.open("./test_result.wav", fstream::in);
  fileLength =
      parser.getHeader("./test_result.wav", inputFileStream, &testHeader);
  inputFileStream.close();
  ASSERT_EQ(testHeader.sampleRate, 44100);
}

TEST_F(WAVParserTest, get_sample_test) {
  inputFileStream.open("../tests/test_files/gal.wav", fstream::in);
  char testSample[2] = {101, 3};
  int fileLength = parser.getHeader("../tests/test_files/gal.wav",
                                    inputFileStream, &testHeader);
  parser.getSample("../tests/test_files/gal.wav", inputFileStream, fileLength,
                   2, testSample);
  inputFileStream.close();
  ASSERT_EQ(testSample[0], 0);
}

TEST_F(WAVParserTest, set_sample_test) {
  // copy Header from gal.wav to test_result.wav
  inputFileStream.open("../tests/test_files/gal.wav", fstream::in);
  int fileLength = parser.getHeader("../tests/test_files/gal.wav",
                                    inputFileStream, &testHeader);
  inputFileStream.close();
  testHeader.chunkSize = 44;
  testHeader.subChunk2Size = 0;
  outputFileStream.open("test_result.wav", fstream::out);
  parser.setHeader("test_result.wav", outputFileStream, &testHeader);

  // test of add sample
  char testSample[2] = {2, 3};
  parser.addSample("./test_result.wav", outputFileStream, 2, testSample);
  outputFileStream.close();

  inputFileStream.open("./test_result.wav", fstream::in);
  fileLength =
      parser.getHeader("./test_result.wav", inputFileStream, &testHeader);
  parser.getSample("./test_result.wav", inputFileStream, fileLength, 2,
                   testSample);
  inputFileStream.close();
  ASSERT_EQ(testSample[1], 3);
}

TEST_F(WAVParserTest, update_header_test) {
  // copy Header from gal.wav to test_result.wav
  inputFileStream.open("../tests/test_files/gal.wav", fstream::in);
  int fileLength = parser.getHeader("../tests/test_files/gal.wav",
                                    inputFileStream, &testHeader);
  inputFileStream.close();
  testHeader.chunkSize = 44;
  testHeader.subChunk2Size = 0;
  outputFileStream.open("test_result.wav", fstream::out);
  parser.setHeader("test_result.wav", outputFileStream, &testHeader);

  // add  1 sample same that add 2 bytes in data part of file
  char testSample[2] = {2, 3};
  parser.addSample("./test_result.wav", outputFileStream, 2, testSample);
  testHeader.subChunk2Size = 2;
  // test update of Header
  parser.updateHeader("test_result.wav", &testHeader);
  outputFileStream.close();

  testHeader.subChunk2Size = 0;
  inputFileStream.open("./test_result.wav", fstream::in);
  fileLength =
      parser.getHeader("./test_result.wav", inputFileStream, &testHeader);
  inputFileStream.close();
  ASSERT_EQ(testHeader.subChunk2Size, 2);
}