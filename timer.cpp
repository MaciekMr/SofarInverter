#include <stdio.h>
#include "timer.h"

Timer::Timer()
{
    slot_id = 0;
}

Timer::~Timer(){

}

void Timer::addslot(slot sl){

    slot_tm.insert(sl);
}


int Timer::addslot(void * functor){

    slot_id++;
    slot sl(slot_id, functor);
    addslot(sl);

    return (slot_id);
}

void Timer::configure(){


}
