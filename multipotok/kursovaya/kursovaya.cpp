// Курсовой проект «Потокобезопасная очередь»
// Пул потоков на базе потокобезопасной очереди.
//
// Что нужно сделать :
// Создать потокобезопасную очередь, хранящую функции, предназначенные для исполнения.
// На основе данной очереди реализовать пул потоков.Данный пул состоит из фиксированного числа рабочих потоков
// (равного количеству аппаратных ядер).Когда у программы появляется какая - то работа,
// она вызывает функцию, которая помещает эту работу в очередь.Рабочий поток забирает работу из очереди, 
// выполняет указанную в ней задачу, после чего проверяет, есть ли в очереди другие работы.
//
// Реализуемые классы :
// 1. Класс thread_pool, представляющий собой реализацию пула потоков.
// Минимально требуемые поля класса thread_pool :
//
// вектор потоков, инициализируемых в конструкторе класса и уничтожаемых в деструкторе;
// потокобезопасная очередь задач для хранения очереди работ;
// остальные поля на усмотрение разработчка.
// Минимально требуемые методы класса thread_pool :
//
// метод work – выбирает из очереди очередную задачи и исполняет ее.Данный метод передается конструктору потоков для исполнения.
// метод submit – помещает в очередь очередную задачу.В качестве принимаемого аргумента метод 
// может принимать или объект шаблона std::function, или объект шаблона package_task.
// Остальные методы на усмотрение разработчика.
// 2. Шаблонный класс safe_queue, представляющий собой реализацию очереди,
// безопасной относительно одновременного доступа из нескольких потоков.
// Минимально требуемые поля класса safe_queue :
//
// очередь std::queue для хранения задач;
// std::mutex для реализации блокировки;
// std::condtional_variables для уведомлений.
// Минимально требуемые методы класса safe_queue :
//
// метод push – записывает в начало очереди новую задачу.При этом захватывает мьютекс,
// а после окончания операции нотифицируется условная переменная.
// метод pop – находится в ожидании, пока не придут уведомление на условную переменную.
// При нотификации условной переменной данные считываются из очереди.
// Остальные методы на усмотрение разработчика.
// 
// Алгоритм работы
// Объявить объект класса thread_pool.
// Описать несколько тестовых функций, выводящих в консоль свое имя.
// Раз в секунду класть в пул одновременно 2 функции и проверять их исполнение.

#include <mutex>
#include <condition_variable>
#include <thread>
#include <chrono>
#include <queue>
#include <iostream>
#include <functional>



class Thread_pool {
private:
    std::vector<std::thread> threads;

    std::queue<std::function<void()>> work_queue;
    bool done = false;

public:
    Thread_pool();
    ~Thread_pool();

    void Work();
    void Submit();

};

//Thread_pool::Thread_pool() {
//    std::thread add1(addF1);
//    std::thread add2(addF2);
//}
//
//void Thread_pool::Submit()
//{
//    for (size_t i = 0; i < 5; i++)
//    {
//        std::this_thread::sleep_for(0.5s);
//        work_queue.push(F1);
//    }
//    done = true;
//}
//
//template<class T>
//class Safe_queue {
//    std::condtional_variables;
//    std::queue<std::function<void()>> work_queue;
//    std::mutex m;
//
//    void push();
//    void pop();
//};
//
//
//void Safe_queue::push() {
//    std::this_thread::sleep_for(0.5s);
//    work_queue.push(F1);
//}
//void Safe_queue::pop() {
//
//}
//
//void F1()
//{
//    std::this_thread::sleep_for(20ms);
//    std::cout << "функция F1" << std::endl;
//}
//void F2()
//{
//    std::this_thread::sleep_for(20ms);
//    std::cout << "функция F2" << std::endl;
//}
//
//
//void Thread_pool::Work()
//{
//    m.lock();
//    std::cout << "id:" << std::this_thread::get_id() << std::endl;
//    m.unlock();
//    while (!done)
//    {
//        std::function<void()> task;
//        if (!work_queue.empty())
//        {
//            task = work_queue.front();
//            task();
//            work_queue.pop();
//        }
//        else
//        {
//            std::this_thread::yield();
//        }
//    }
//}


int main()
{
    const int pool_size = std::thread::hardware_concurrency() - 2;

    std::thread add1(addF1);
    std::thread add2(addF2);

    //for (size_t i = 0; i < pool_size; i++)
    //{
    //    threads.push_back(std::thread(work));
    //}

    for (size_t i = 0; i < pool_size; i++)
    {
        if (threads[i].joinable())
        {
            threads[i].join();
        }
    }
    add1.join();
    add2.join();
    return 0;
}