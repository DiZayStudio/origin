#include <iostream>
#include <fstream>


class LogCommand {
public:
    virtual ~LogCommand() = default;
    virtual void print(const std::string& message) = 0;
};

class LogCommandCMD : LogCommand {

public:
    void print(const std::string& message) override {
        std::cout << message << std::endl;
    }
};

class LogCommandFile : LogCommand {
private:
    std::ofstream out_file;
public:
    void print(const std::string& message) override {

        out_file.open("log.txt", std::ios::app);
        if (out_file.is_open())
        {
            out_file << message << std::endl;
        }
        out_file.close();
    }
};

void print(LogCommand& log) {

};


int main()
{
    LogCommandCMD logCMD;
    LogCommandFile logFile;

    logCMD.print("Message");
    logFile.print("Message");
}

