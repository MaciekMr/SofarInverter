#include "datacollector.h"

DataCollector::DataCollector()
{
    model = new mapmodel();
}


DataCollector::~DataCollector(){

}

void * DataCollector::findObject(string name){


}

void DataCollector::addObject(QObject * obj1, QObject * obj2, string name){

    //element     * view = new element(obj1, name);
    //element     * data = new element(obj2, name);
    dataview    * dtvw = new dataview(obj1, obj2);
    //modelview   * mdl  = new modelview(view, data);

    model->insert(pair<string, dataview *>(name, dtvw));

}

QObject * DataCollector::findView(string name){

    mapmodel::iterator it;
    it = model->find(name);
    if(it != model->end()){
        return(it->second->second);
    }else{
        return NULL;
    }
}

QObject * DataCollector::findModel(string name){

    mapmodel::iterator it;
    it = model->find(name);
    if(it != model->end()){
        return(it->second->first);
    }else{
        return NULL;
    }
}

void DataCollector::addModel(QObject * obj, string name){

    mapmodel::iterator it;
    it = model->find(name);
    if(it != model->end()){
        dataview * dv = it->second;
        dv->second = obj;
    }else{
      //Create new record
        addObject(obj, NULL, name);
    }

}

void DataCollector::addView(QObject * obj, string name){

    mapmodel::iterator it;
    it = model->find(name);
    if(it != model->end()){
        dataview * dv = it->second;
        dv->second = obj;
    }else{
      //Create new record
        addObject(NULL, obj, name);
    }
}


DataCollector * DataCollector::getDataCollector(){

    if(!_pointer)
        _pointer = new DataCollector();
    return(_pointer);
}

DataCollector * DataCollector::_pointer;
