#include <iostream>
#include <Wt/Dbo/Dbo.h>
#include <Wt/Dbo/backend/Postgres.h>
#include <Windows.h>
#include <corecrt_wstring.h>

#pragma execution_character_set("utf-8")

const std::string CONNECTION_STR = "host=localhost port=5432 dbname=postgres user=postgres password=12345678";

class Book;
class Stock;
class Sale;

class Publisher
{
public:
    std::string name;
    Wt::Dbo::collection<Wt::Dbo::ptr<Book>> books;
    template<typename Action>
    void persist(Action& a)
    {
        Wt::Dbo::field(a, name, "name");
        Wt::Dbo::hasMany(a, books, Wt::Dbo::ManyToOne, "publisher");
    }
};

class Book
{
public:
    std::string title;
    Wt::Dbo::ptr<Publisher> publisher;
    Wt::Dbo::collection<Wt::Dbo::ptr<Stock>> stocks;

    template<typename Action>
    void persist(Action& a)
    {
        Wt::Dbo::field(a, title, "title");
        Wt::Dbo::belongsTo(a, publisher, "publisher");
        Wt::Dbo::hasMany(a, stocks, Wt::Dbo::ManyToOne, "book");
    }
};

class Shop
{
public:
    std::string name;
    Wt::Dbo::collection<Wt::Dbo::ptr<Stock>> stocks;

    template<typename Action>
    void persist(Action& a)
    {
        Wt::Dbo::field(a, name, "name");
        Wt::Dbo::hasMany(a, stocks, Wt::Dbo::ManyToOne, "shop");
    }
};

class Stock
{
public:
    int count;
    Wt::Dbo::ptr<Shop> shop;
    Wt::Dbo::ptr<Book> book;
    Wt::Dbo::collection<Wt::Dbo::ptr<Sale>> sales;

    template<typename Action>
    void persist(Action& a)
    {
        Wt::Dbo::field(a, count, "count");
        Wt::Dbo::belongsTo(a, shop, "shop");
        Wt::Dbo::belongsTo(a, book, "book");
        Wt::Dbo::hasMany(a, sales, Wt::Dbo::ManyToOne, "stock");
    }
};

class Sale
{
public:
    int count;
    std::string date;
    Wt::Dbo::ptr<Stock> stock;
    int price;

    template<typename Action>
    void persist(Action& a)
    {
        Wt::Dbo::field(a, count, "count");
        Wt::Dbo::field(a, date, "date");
        Wt::Dbo::belongsTo(a, stock, "stock");
        Wt::Dbo::field(a, price, "price");
    }
};


int main(){
SetConsoleCP(CP_UTF8);
SetConsoleOutputCP(CP_UTF8);
setvbuf(stdout, nullptr, _IOFBF, 1000);

try {
    auto postgres = std::make_unique<Wt::Dbo::backend::Postgres>(CONNECTION_STR);

    Wt::Dbo::Session session;
    session.setConnection(std::move(postgres));
    session.mapClass<Book>("book");
    session.mapClass<Publisher>("publisher");
    session.mapClass<Shop>("shop");
    session.mapClass<Stock>("stock");
    session.mapClass<Sale>("sale");

    try
    {
        session.createTables();
        Wt::Dbo::Transaction transaction{ session };

        std::unique_ptr<Publisher> p1 = std::make_unique<Publisher>();
        p1->name = "Drofa";
        std::unique_ptr<Book> b1 = std::make_unique<Book>();
        b1->title = "Отцы и дети";
        std::unique_ptr<Shop> s1 = std::make_unique<Shop>();
        s1->name = "Labirint";
        std::unique_ptr<Stock> st1 = std::make_unique<Stock>();
        st1->count = 100;
        std::unique_ptr<Sale> sl1 = std::make_unique<Sale>();
        sl1->count = 10;
        sl1->date = "2023-05-09";
        sl1->price = 525;

        auto publisher_added = session.add(std::move(p1));
        auto book_added = session.add(std::move(b1));
        auto shop_added = session.add(std::move(s1));
        auto stock_added = session.add(std::move(st1));
        auto sale_added = session.add(std::move(sl1));

        book_added.modify()->publisher = publisher_added;
        stock_added.modify()->book = book_added;
        shop_added.modify()->stocks.insert(stock_added);
        sale_added.modify()->stock = stock_added;
        transaction.commit();

        b1 = std::make_unique<Book>();
        b1->title = "Мастер и маргарита";
        st1 = std::make_unique<Stock>();
        st1->count = 2000;
        sl1 = std::make_unique<Sale>();
        sl1->count = 40;
        sl1->date = "2023-05-14";
        sl1->price = 685;

        book_added = session.add(std::move(b1));
        stock_added = session.add(std::move(st1));
        sale_added = session.add(std::move(sl1));

        book_added.modify()->publisher = publisher_added;
        stock_added.modify()->book = book_added;
        shop_added.modify()->stocks.insert(stock_added);
        sale_added.modify()->stock = stock_added;
        transaction.commit();

        p1 = std::make_unique<Publisher>();
        p1->name = "Drofa";
        b1 = std::make_unique<Book>();
        b1->title = "Преступление и наказание";
        st1 = std::make_unique<Stock>();
        st1->count = 200;
        sl1 = std::make_unique<Sale>();
        sl1->count = 50;
        sl1->date = "2023-05-11";
        sl1->price = 386;

        book_added = session.add(std::move(b1));
        stock_added = session.add(std::move(st1));
        sale_added = session.add(std::move(sl1));

        book_added.modify()->publisher = publisher_added;
        stock_added.modify()->book = book_added;
        shop_added.modify()->stocks.insert(stock_added);
        sale_added.modify()->stock = stock_added;
        transaction.commit();


        p1 = std::make_unique<Publisher>();
        p1->name = "Просвящение";
        b1 = std::make_unique<Book>();
        b1->title = "Мастер и маргарита";
        s1 = std::make_unique<Shop>();
        s1->name = "Chitay gorod";
        st1 = std::make_unique<Stock>();
        st1->count = 1000;

        sl1 = std::make_unique<Sale>();
        sl1->count = 60;
        sl1->date = "2023-05-12";
        sl1->price = 285;

        publisher_added = session.add(std::move(p1));
        book_added = session.add(std::move(b1));
        shop_added = session.add(std::move(s1));
        stock_added = session.add(std::move(st1));
        sale_added = session.add(std::move(sl1));

        book_added.modify()->publisher = publisher_added;
        stock_added.modify()->book = book_added;
        shop_added.modify()->stocks.insert(stock_added);
        sale_added.modify()->stock = stock_added;
        transaction.commit();

    }
    catch (const Wt::Dbo::Exception& e)
    {
        std::cout << "Не удалось создать таблицы: " << e.what() << std::endl;
    }

    std::cout << "Введите издательство: ";
    std::string publisherName;

    std::cin >> publisherName;

    Wt::Dbo::Transaction t1{ session };

    Wt::Dbo::ptr<Publisher> publisher = session.find<Publisher>().where("name = ?").bind(publisherName).limit(1);

    if (publisher)
    {
        std::cout << "Издательство: " << publisher->name << std::endl;

        Wt::Dbo::collection<Wt::Dbo::ptr<Book>> books = publisher->books;

        std::vector<Wt::Dbo::ptr<Stock>> stocks;
        for (auto book : books)
        {
            std::cout << "Книга: " << book->title;
            std::for_each(book->stocks.begin(), book->stocks.end(), [&stocks](Wt::Dbo::ptr<Stock> s) {
                std::cout << " в магазине: " << s->shop->name << std::endl;
            });
        }
    }
    else
    {
        std::cout << "Издательство не найдено" << std::endl;
    }

    t1.commit();
}
catch (const Wt::Dbo::Exception& e)
{
    std::cout << e.what() << std::endl;
}

return 0;
}

