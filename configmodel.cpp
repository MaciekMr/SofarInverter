#include "configmodel.h"

ConfigModel::ConfigModel()
{
    config = new configurations();
}


void ConfigModel::test(){


    string st("12");

    this->addparameter<string>("section1","port",st);
    string i = findparameter<string>("section1","port");
    printf("vaule %s",i.c_str());

}

template<class T>
T ConfigModel::findparameter(string section, string name){

    configurations::iterator it;
    it = config->find(section);

    if(it!=config->end()){
        //ok, found section
        parameterlist *parlist = it->second;
        //find parameter in map
        parameterlist::iterator parit = parlist->find(name);
        if(parit!=parlist->end()){

            return(parit->second);
        }else{
            return(NULL);
        }
    }else{
        //not found
    }

    return(NULL);
}

template<class T>
void ConfigModel::addparameter(string section, string name, T value){

    //find parameters for given section
    configurations::iterator it;
    parameterlist * par;
    it = config->find(section);
    if(it != config->end()){

        par = it->second;
        //param.second = reinterpret_cast<T*>(value);
        //par->push_back(param);
        //par->insert(pair<string, T*>(name, reinterpret_cast<T*>(value)));

    }else{

        //section is not set
        //we need to add section
        par = new parameterlist();
        config->insert(pair<string, parameterlist*>(section, par));
    }

    //par->insert(pair<string, T>(name, reinterpret_cast<T>(value)));
    par->insert(pair<string, T>(name, value));
}


ConfigModel * ConfigModel::getConfig(){

    if(!pointer)
        pointer = new ConfigModel();
    return(pointer);
}

void ConfigModel::save(std::ofstream &ar){

    //string str("ssss");
    text_oarchive ta(ar);
    for(auto const &ent1 : *config){

        //store section
        ta << (std::string)ent1.first;

        for(auto const &ent2: *ent1.second){

            ta << ent2.first;
            ta << ent2.second;
        }
    }

}

void ConfigModel::load(std::ifstream &ar){

    text_iarchive ta(ar);
    std::string str("");
    ta >> str;

    const char * txt = str.c_str();
}


ConfigModel * ConfigModel::pointer;
