#ifndef THREADSET_H
#define THREADSET_H

#include <thread>
#include <functional>

using std::thread;

class Thread{

private:
    thread * thread_ptr;
public:
    template <class T>
    Thread(std::function<T> *); //Constructor with pointer to method
    ~Thread();
    void run();
    void stop();
    void pause();

};


class ThreadSet
{
public:
    ThreadSet();
};

#endif // THREADSET_H
