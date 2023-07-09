#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class Observer {
public:
    virtual void onWarning(const std::string& message) { }
    virtual void onError(const std::string& message) { }
    virtual void onFatalError(const std::string& message) { }
};

class Application {
public:
    void addObserver(const std::weak_ptr<Observer> &obs) {
        observers_.push_back(obs);
    }
    void warning(const std::string& message) const {
        for (auto observer : observers_) {
            if (auto strong_ptr = observer.lock()) {
                strong_ptr->onWarning(message);
            }
        }
    }
    void error(const std::string& message) const {
        for (auto observer : observers_) {
            if (auto strong_ptr = observer.lock()) {
                strong_ptr->onError(message);
            }
        }
    }
    void fatalError(const std::string& message) const {
        for (auto observer : observers_) {
            if (auto strong_ptr = observer.lock()) {
                strong_ptr->onFatalError(message);
            }
        }
    }
private:
    std::vector<std::weak_ptr<Observer>> observers_;
};

class ObserverWarning : Observer {
public:
    void onWarning(const std::string& message) {
        std::cout << message << std::endl;
    }
};

class ObserverError : Observer {
public:
    void onError(const std::string& message) {
        std::ofstream out_file;
        out_file.open("log.txt", std::ios::app);
        if (out_file.is_open())
        {
            out_file << message << std::endl;
        }
        out_file.close();
    }
};

class ObserverFatalError : Observer {
public:
    void onFatalError(const std::string& message) {
        std::cout << message << std::endl;
        std::ofstream out_file;
        out_file.open("log.txt", std::ios::app);
        if (out_file.is_open())
        {
            out_file << message << std::endl;
        }
        out_file.close();
    }
};

int main()
{
 
    Application app;
    {
        auto o_ptr = std::make_shared<Observer>();
        app.addObserver(o_ptr);
    }
    return 0;
};
