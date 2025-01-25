#include "buisness_exception.h"

#include <string>
using namespace std;

ConfigException::ConfigException(string message, string convertorType,
                                 const int currentPosition)
    : ProcessorException(message.c_str()) {
  message_ = "On " + to_string(currentPosition) +
             " position in  config file: " + message + " | convertor type is " +
             convertorType;
}

SourceFileException::SourceFileException(string message, string filename,
                                         const int currentPosition)
    : ProcessorException(message.c_str()) {
  message_ = "In file " + filename + " on position " +
             to_string(currentPosition) + ": " + message;
}
