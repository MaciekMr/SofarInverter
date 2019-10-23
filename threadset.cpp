#include "threadset.h"

using std::thread;

/*
 * template <class T>
 * Thread::Thread(std::function<void (Params && ... p)> task, Params && p )
 */

Thread::~Thread(){

    thread_ptr->detach();
    delete(thread_ptr);
    thread_ptr = nullptr;
}


void Thread::run(){

    _state = enable;
}

void Thread::stop(){

    _state = disable;
}

ThreadSet::ThreadSet(){

}

ThreadSet::~ThreadSet(){


}
