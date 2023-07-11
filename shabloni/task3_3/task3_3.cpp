#include <iostream>
#include <fstream>

enum Type {
    FATAL,
    ERROR,
    WARNING,
    UNKNOWN
};

class LogMessage {
private:
    Type _type;
    std::string _message;
    LogMessage*  _nextLogMessage;
public:
    LogMessage(Type type, std::string message) : _message(message), _type(type) {
        _nextLogMessage = nullptr;
    }
    Type get_type() const { return _type; }
    const std::string& get_message() const { return _message; }
    void addNextLogMessage(LogMessage*  nextLogMessage) {
        this->_nextLogMessage = nextLogMessage;
    }
    LogMessage* GetNextLog() {
        return _nextLogMessage;
    }
    virtual void Execute(Type type, std::string message) = 0;
};

class LogFatalMsg : public LogMessage {
public:
    LogFatalMsg(std::string message) : LogMessage(FATAL, message) {}
    void Execute(Type type, std::string message) {
        if (this->get_type() == FATAL) {
            throw "Фатальная ошибка";
        }
        if (this->GetNextLog() != nullptr) {
            this->GetNextLog()->Execute(type, message);
        }
    };
};

class LogErrorMsg : public LogMessage {
public:
    LogErrorMsg(std::string message) : LogMessage(ERROR, message) {}
    void Execute(Type type, std::string message) {
        if (this->get_type() == ERROR) {
            std::ofstream out_file;
            out_file.open("log.txt", std::ios::app);
            if (out_file.is_open())
            {
                out_file << message << std::endl;
            }
            out_file.close();
        }
        if (this->GetNextLog() != nullptr) {
            this->GetNextLog()->Execute(type, message);
        }
    };
};

class LogWarningMsg : public LogMessage {
public:
    LogWarningMsg(std::string message) : LogMessage(WARNING, message) {}
    void Execute(Type type, std::string message) {
        if (this->get_type() == ERROR) {
            std::cout << message << std::endl;
        }
        if (this->GetNextLog() != nullptr) {
            this->GetNextLog()->Execute(type, message);
        }
    };
};

class LogUnknownMsg : public LogMessage {
public:
    LogUnknownMsg(std::string message) : LogMessage(UNKNOWN, message) {};
    void Execute(Type type, std::string message) {
        if (this->get_type() == FATAL) {
            throw "Неизвестное сообщение";
        }
        if (this->GetNextLog() != nullptr) {
            this->GetNextLog()->Execute(type, message);
        }
    };
};

int main()
{
    
}
