#include <iostream>

enum Type {
    WARNING,
    ERROR,
    FATAL,
    UNKNOWN
};

class LogMessage {
private:
    Type _type;
    std::string _message;
  //  LogMessage& nextLogMessage;
public:
    LogMessage(Type type, std::string message) : _message(message), _type(type) {}
    Type get_type() const { return _type; }
    const std::string& get_message() const { return _message; }
};



class LogUnknownMsg : public LogMessage {
public:
    LogUnknownMsg(std::string message) : LogMessage(UNKNOWN, message) {}
};

class LogWarningMsg : public LogMessage {
public:
    LogWarningMsg(std::string message) : LogMessage(WARNING, message) {}
};

class LogErrorMsg : public LogMessage {
public:
    LogErrorMsg(std::string message) : LogMessage(ERROR, message) {}
};

class LogFatalMsg : public LogMessage {
public:
    LogFatalMsg(std::string message) : LogMessage(FATAL, message) {}
};

int main()
{
    std::cout << "Hello World!\n";
}
