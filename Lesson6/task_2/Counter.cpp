#include "Counter.h"


    Counter::Counter() {
        this->count = 1;
    }
    Counter::Counter(int count) {
        this->count = count;
    }

    void Counter::inc() {
        count++;
    }
    void Counter::dec() {
        count--;
    }
    int Counter::get_count() {
        return count;
    }
