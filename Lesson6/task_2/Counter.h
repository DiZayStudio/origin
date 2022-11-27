#pragma once

class Counter {
private:
    int count;

public:
    Counter();
    Counter(int count);
    void inc();
    void dec();
    int get_count();
};