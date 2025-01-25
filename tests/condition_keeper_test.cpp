#include "wav_files_condition_keeper.h"
#include "gtest/gtest.h"
#include <fstream>
#include <ios>

namespace {
class ConditionKeeperTest : public testing::Test {
public:
  ConditionKeeper keeper;

protected:
  void SetUp() override {
    static string inputFiles[2] = {"../tests/test_files/gal.wav",
                                   "../tests/test_files/birth.wav"};
    keeper = ConditionKeeper(2, inputFiles, "keeper_test_result.wav");
    cout << "HEY" << endl;
  }

  void TearDown() override {}
};
} // namespace

TEST_F(ConditionKeeperTest, get_sample_test) {
  char testSample[2] = {12, 3};
  keeper.getSample(0, 0, testSample);
  cout << "I am alive!" << endl;
  ASSERT_EQ(testSample[0], 0);
}

TEST_F(ConditionKeeperTest, set_sample_test) {
  char testSample[2] = {12, 3}, testSet[2] = {15, 0};
  keeper.setSample(testSample);
  keeper.endProcessing();
  testSample[0] = 2;
  testSample[1] = 2;
  ifstream testFileStream;
  testFileStream.open("keeper_test_result.wav", fstream::in);
  testFileStream.seekg(44, std::ios_base::beg);
  testFileStream.read(testSet, 1);
  ASSERT_EQ((int)testSet[0], 12);
}