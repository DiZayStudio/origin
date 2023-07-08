#include <iostream>
#include <string>
#include <vector>

class Application {
public:
    void addObserver(Observer* ptr) {
        observers_.push_back(ptr);
    }
    void warning(const std::string& message) const {
        for (auto observer : observers_) {
            observer->onWarning(message);
        }
    }
    void error(const std::string& message) const;
    void fatalError(const std::string& message) const;
private:
    std::vector<Observer*> observers_;
};

class Observer {
public:
    virtual void onWarning(const std::string& message) {}
    virtual void onError(const std::string& message) {}
    virtual void onFatalError(const std::string& message) {}
};



int main()
{
    std::cout << "Hello World!\n";
}
