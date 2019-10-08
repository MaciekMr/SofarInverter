#ifndef XML_PARSER_H
#define XML_PARSER_H


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
#include <boost/optional/optional.hpp>
#include <boost/foreach.hpp>
#include <QCoreApplication>
#include "definitions.h"


#include <map>
#include <list>

using std::pair;
using std::string;
using std::map;
using std::list;
using std::cout;
using boost::optional;
using boost::archive::text_oarchive;
using boost::archive::text_iarchive;
using boost::filesystem::ifstream;
using boost::filesystem::ofstream;
using boost::property_tree::ptree;
using boost::property_tree::xml_parser::write_xml;


typedef map<string, string> parameterlist;
typedef map<string, parameterlist *> configurations;

static auto pretty = boost::property_tree::xml_writer_make_settings<std::string>(' ', 4);

class xmlparser
{
private:
    ptree  pt;
    configurations * _conf;
    string          _filename;
    string          _id; //related to CONFIG ID
protected:
    void showchildelements(ptree pt, string _label = "");
    ifstream *_ifs;
public:
    xmlparser();
    ~xmlparser();
    void traverse_xml();
    int load_xml(string filename);
    int load_xml(ifstream &ifs);
    virtual int getelementcount();
    virtual bool addparameter(string part, string parameter, string value);

};

#endif // XML_PARSER_H
