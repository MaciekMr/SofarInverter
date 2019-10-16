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
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/exceptions.hpp>
#include <boost/filesystem.hpp>
#include <boost/foreach.hpp>
#include "definitions.h"
#include "xml_parser.h"
#include <map>
#include <list>

using std::pair;
using std::string;
using std::map;
using std::list;
using std::cout;

using boost::filesystem::path;
using boost::archive::text_oarchive;
using boost::archive::text_iarchive;
using boost::filesystem::ifstream;
using boost::filesystem::ofstream;
using boost::property_tree::ptree;
using boost::property_tree::ptree_error;
using boost::property_tree::xml_parser::write_xml;

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
typedef pair<int,string> header;
typedef list<header> header_list;


class ConfigModel: private xmlparser
{
private:
    friend class boost::serialization::access;

protected:
    static ConfigModel *pointer;
    configurations     *config;
    std::string        istring;
    ptree              proptree;

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
    void load(ifstream &ifs);
    void load();

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
    bool addparameter(string part, string parameter, string value);
    int getelementcount();



    static ConfigModel * getConfig();
    const header_list * getheaders();

};

#endif // CONFIGMODEL_H
