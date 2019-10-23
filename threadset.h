#ifndef THREADSET_H
#define THREADSET_H

#include <thread>
#include <functional>
#include <map>

using std::thread;
using std::map;

/*******************************************
 *
 * example https://stackoverflow.com/questions/7909719/c0x-stdfunction-as-a-method-argument
 *
 * https://oopscenities.net/2012/02/24/c11-stdfunction-and-stdbind/
 *
 * https://stackoverflow.com/questions/22916784/how-should-i-define-a-stdfunction-variable-with-default-arguments
 *
 * *****************************************/

enum state{enable, disable};

class Thread
{
private:
    state _state;
protected:
    thread * thread_ptr;
public:
    //template <typename ... Params>
    //Thread(std::function<void (Params && ... p)> task, Params && p ); //Constructor with pointer to method

    template< class Function, class... Args >
    explicit Thread(Function&& f, Args&&... args ){

         _state = disable;
        //thread_ptr = new thread (task);
        thread_ptr = new std::thread(f, args...);
    }


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
