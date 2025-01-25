#ifndef EXCEPTIONS_HEADER
#define EXCEPTIONS_HEADER
#include <exception>
#include <iostream>
#include <string>

using namespace std;

class ProcessorException : public exception {
private:
  const char *message_;

public:
  ProcessorException(const char *message) { message_ = message; }
  ProcessorException(const ProcessorException &copySource) {
    message_ = copySource.message_;
  }
  ProcessorException(const ProcessorException &&moveSource) {
    message_ = moveSource.message_;
  }
  ProcessorException &operator=(const ProcessorException &copySource) {
    message_ = copySource.message_;
    return *this;
  }
  ProcessorException &operator=(const ProcessorException &&moveSource) {
    message_ = moveSource.message_;
    return *this;
  }

  virtual const char *what() const noexcept override { return message_; }
};

class ConfigException : public ProcessorException {
private:
  string message_;

public:
  ConfigException(string message, string convertorType,
                  const int currentPosition);
  ConfigException(const ConfigException &copySource)
      : ProcessorException(copySource) {
    message_ = copySource.message_;
  }
  ConfigException(const ConfigException &&moveSource)
      : ProcessorException(moveSource) {
    message_ = moveSource.message_;
  }
  ConfigException &operator=(const ConfigException &copySource) {
    message_ = copySource.message_;
    return *this;
  }
  ConfigException &operator=(const ConfigException &&moveSource) {
    message_ = moveSource.message_;
    return *this;
  }
  

  virtual const char *what() const noexcept override {
    return message_.c_str();
  };
};

class SourceFileException : public ProcessorException {
private:
  string message_;

public:
  SourceFileException(string message, string filename,
                      const int currentPosition);
  SourceFileException(const SourceFileException &copySource)
      : ProcessorException(copySource) {
    message_ = copySource.message_;
    cout << "A" << endl;
  }
  SourceFileException(const SourceFileException &&moveSource)
      : ProcessorException(moveSource) {
    message_ = moveSource.message_;
    cout << "B " << moveSource.message_ << endl;
  }
  SourceFileException &operator=(const SourceFileException &copySource) {
    message_ = copySource.message_;
    cout << "C" << endl;
    return *this;
  }
  SourceFileException &operator=(const SourceFileException &&moveSource) {
    message_ = moveSource.message_;
    cout << "D" << endl;
    return *this;
  }
  virtual const char *what() const noexcept override {
    return message_.c_str();
  };
};

#endif