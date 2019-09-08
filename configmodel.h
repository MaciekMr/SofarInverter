#ifndef CONFIGMODEL_H
#define CONFIGMODEL_H

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <map>
#include <list>

using std::pair;
using std::string;
using std::map;
using std::list;

//parameter name, value
//template <typename T>
//typedef pair<string, T*> parameter<T>;


template <class T>
class _pair:pair<string,T*>{

private:

public:


};


//typedef pair<string, string> parameter;
//configuration name, list of paramteres
typedef map<string, string*> parameterlist;
typedef map<string, parameterlist *> configurations;

class ConfigModel
{
protected:
    static ConfigModel *pointer;
    configurations * config;
public:
    ConfigModel();
    //find a paramtere from given config

    template<class T>
    T* findparameter(string, string);
    //add paramter to given config
    template<class T>
    void addparameter(string, string, T*);
    void test();

    static ConfigModel * getConfig();
};

#endif // CONFIGMODEL_H
