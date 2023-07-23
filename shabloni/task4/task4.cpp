#include <iostream>
#include <fstream>




class Printable
{
public:
    virtual ~Printable() = default;

//    virtual std::string printAsHTML() const = 0;
//    virtual std::string printAsText() const = 0;
//    virtual std::string printAsJSON() const = 0;

    virtual std::string preparation(const std::string& data) const = 0;
};

//class Data : public Printable
//{
//public:
//    enum class Format
//    {
//        kText,
//        kHTML,
//        kJSON
//    };
//
//    Data(std::string data, Format format)
//        : data_(std::move(data)), format_(format) {}
//
//    std::string printAsHTML() const override
//    {
//        if (format_ != Format::kHTML) {
//            throw std::runtime_error("Invalid format!");
//        }
//        return "<html>" + data_ + "<html/>";
//    }
//    std::string printAsText() const override
//    {
//        if (format_ != Format::kText) {
//            throw std::runtime_error("Invalid format!");
//        }
//        return data_;
//    }
//    std::string printAsJSON() const override
//    {
//        if (format_ != Format::kJSON) {
//            throw std::runtime_error("Invalid format!");
//        }
//        return "{ \"data\": \"" + data_ + "\"}";
//    }
//
//private:
//    std::string data_;
//    Format format_;
//};

class PrintableHTML : public Printable {
public:
    std::string preparation(const std::string& data)  const override {
        return "<html>" + data + "<html/>";
    };
};

class PrintableText : public Printable {
public:
    std::string preparation(const std::string& data)  const override {
        return data;
    };
};

class PrintableJSON : public Printable {
public:
    std::string preparation(const std::string& data)  const override {
        return "{ \"data\": \"" + data + "\"}";
    };
};


//void saveTo(std::ofstream& file, const Printable& printable, Data::Format format)
//{
//    switch (format)
//    {
//    case Data::Format::kText:
//        file << printable.printAsText();
//        break;
//    case Data::Format::kJSON:
//        file << printable.printAsJSON();
//        break;
//    case Data::Format::kHTML:
//        file << printable.printAsHTML();
//        break;
//    }
//}
//
//void saveToAsHTML(std::ofstream& file, const Printable& printable) {
//    saveTo(file, printable, Data::Format::kHTML);
//}
//
//void saveToAsJSON(std::ofstream& file, const Printable& printable) {
//    saveTo(file, printable, Data::Format::kJSON);
//}
//
//void saveToAsText(std::ofstream& file, const Printable& printable) {
//    saveTo(file, printable, Data::Format::kText);
//}

std::ostream& saveTextForPrinting(std::ostream& output, const std::string& data, const Printable& printable)
{
    output << printable.preparation(data);
    return output;
}

int main()
{
    PrintableHTML pHTML;
    PrintableText pTEXT;
    PrintableJSON pJSON;

    std::string text = "Hello, world!";
  
    saveTextForPrinting(std::cout, text, pHTML);
    std::cout << std::endl;
    saveTextForPrinting(std::cout, text, pTEXT);
    std::cout << std::endl;
    saveTextForPrinting(std::cout, text, pJSON);
}
