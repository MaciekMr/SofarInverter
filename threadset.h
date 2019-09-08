#ifndef THREADSET_H
#define THREADSET_H

#include <thread>
#include <functional>
#include <map>

using std::thread;
using std::map;

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

typedef map<int, Thread *> thread_map;

class ThreadSet
{
private:
    thread_map threads;
public:
    ThreadSet();
    ~ThreadSet();

    void addthread();

};

#endif // THREADSET_H
