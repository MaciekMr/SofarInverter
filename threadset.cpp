#include "threadset.h"

using std::thread;

/*
 * template <class T>
  Thread::Thread(std::function<void (Params && ... p)> task, Params && p )
  */

template< class Function, class... Args >
Thread( Function&& f, Args&&... args ){

    thread_ptr = new thread (task);
}

Thread::~Thread(){

    thread_ptr->detach();
    delete(thread_ptr);
    thread_ptr = nullptr;
}


ThreadSet::ThreadSet(){


}
