#include "configmodel.h"

ConfigModel::ConfigModel()
{
    config = new configurations();
}


void ConfigModel::test(){


    string *st = new string("12");

    this->addparameter<string>("section1","port",st);
    string *i = findparameter<string>("section1","port");
    printf("vaule %s",i);

}

template<class T>
T* ConfigModel::findparameter(string section, string name){

    configurations::iterator it;
    it = config->find(section);

    if(it!=config->end()){
        //ok, found section
        parameterlist *parlist = it->second;
        //find parameter in map
        parameterlist::iterator parit = parlist->find(name);
        if(parit!=parlist->end()){

            return(reinterpret_cast<T*>(parit->second));
        }else{
            return(NULL);
        }
    }else{
        //not found
    }

    return(NULL);
}

template<class T>
void ConfigModel::addparameter(string section, string name, T* value){

    //find parameters for given section
    configurations::iterator it;
    parameterlist * par;
    it = config->find(section);
    if(it != config->end()){

        par = it->second;
        //param.second = reinterpret_cast<T*>(value);
        //par->push_back(param);
        par->insert(pair<string, T*>(name, reinterpret_cast<T*>(value)));

    }else{

        //section is not set
        //we need to add section
        par = new parameterlist();
        config->insert(pair<string, parameterlist*>(section, par));
    }

    par->insert(pair<string, T*>(name, reinterpret_cast<T*>(value)));
}


ConfigModel * ConfigModel::getConfig(){

    if(!pointer)
        pointer = new ConfigModel();
    return(pointer);
}

ConfigModel * ConfigModel::pointer;
