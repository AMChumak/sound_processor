#include "simple_config_parser.h"
#include "gtest/gtest.h"

namespace {
class ConfigParserTest : public testing::Test {
public:
  simpleConfigParser parser;

protected:
  void SetUp() override {
    static string configFile = "../tests/test_files/test_config.txt";
    parser = simpleConfigParser(configFile);
  }

  void TearDown() override {}
};
} // namespace

TEST_F(ConfigParserTest, take_command) {
  int startPosition = 0;
  int fileNumbers[2] = {0, 0};
  commandStruct currentCommand = {ProcessorCommands(1), 1, fileNumbers, 0};
  parser.getCommandForOccurrence(&startPosition, 25, &currentCommand);
  ASSERT_EQ(currentCommand.commandType, ProcessorCommands(1));
}
