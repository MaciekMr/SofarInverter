#include "threadset.h"

using std::thread;

template <class T>
Thread::Thread(std::function<T>  *ptr){

    thread_ptr = new thread (ptr);
}

Thread::~Thread(){

    thread_ptr->detach();
    delete(thread_ptr);
    thread_ptr = nullptr;
}


ThreadSet::ThreadSet(){


}
