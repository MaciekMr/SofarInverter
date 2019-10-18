#ifndef SINGLETON_H
#define SINGLETON_H


class singleton
{
private:
    static singleton * pointer;
public:
    singleton();
    const singleton * getClass(){
        if(!pointer)
            pointer = new singleton();
        return(pointer);
    }

};

#endif // SINGLETON_H
