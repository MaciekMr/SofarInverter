#ifndef DATACOLLECTOR_H
#define DATACOLLECTOR_H

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <QObject>



using std::string;
using std::pair;
using std::list;
using std::map;

typedef pair<QObject *, string> element;
typedef pair<element *, element *> modelview;

typedef pair<QObject *, QObject*> dataview;

typedef map<string, dataview *> mapmodel;
//typedef map<modelview *, string> mapmodel;

typedef list<modelview *>   elementlist;

class DataCollector
{
private:
    static DataCollector * _pointer;
    DataCollector();
protected:
    mapmodel * model;
public:
    ~DataCollector();
    void * findObject(string name);
    QObject * findView(string name);
    QObject * findModel(string name);
    void addObject(QObject *, QObject *, string);
    void addModel(QObject *, string);
    void addView(QObject *, string);

    static DataCollector * getDataCollector();
};

#endif // DATACOLLECTOR_H
