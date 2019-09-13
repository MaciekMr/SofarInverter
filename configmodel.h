#ifndef CONFIGMODEL_H
#define CONFIGMODEL_H

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/serialization/map.hpp>
#include <boost/serialization/string.hpp>
#include <boost/serialization/list.hpp>
#include <boost/filesystem/fstream.hpp>
#include <map>
#include <list>

using std::pair;
using std::string;
using std::map;
using std::list;
using boost::archive::text_oarchive;
using boost::archive::text_iarchive;
using boost::filesystem::ifstream;
using boost::filesystem::ofstream;

//parameter name, value
//template <typename T>
//typedef pair<string, T*> parameter<T>;

#define IP "IP"
#define PORT "PORT"


template <class T>
class _pair:pair<string,T*>{

private:

public:


};


//typedef pair<string, string> parameter;
//configuration name, list of paramteres
typedef map<string, string> parameterlist;
typedef map<string, parameterlist *> configurations;

class ConfigModel
{
private:
    friend class boost::serialization::access;
protected:
    static ConfigModel *pointer;
    configurations     *config;
public:
    ConfigModel();
    //find a paramtere from given config

    template<class T>
    T findparameter(string, string);
    //add paramter to given config
    template<class T>
    void addparameter(string, string, T);
    void test();

    void save(std::ofstream &ar);
    void load(std::ifstream &ar);

    template <typename Archive>
    void serialize(Archive &ar, const unsigned int version){

        //ar & config;
        /*
        for(auto const &ent1 : *config) {
            // ent1.first is the first key
            ar & ent1.first;
            for(auto const &ent2 : *ent1.second) {
                // ent2.first is the second key
                // ent2.second is the data
                ar & ent2.first;
                ar & ent2.second;
            }
        }
        */
    }

    static ConfigModel * getConfig();
};

#endif // CONFIGMODEL_H
