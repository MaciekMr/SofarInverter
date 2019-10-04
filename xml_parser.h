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

static auto pretty = boost::property_tree::xml_writer_make_settings<std::string>(' ', 4);

class XML_PARSER
{
private:
    ptree  pt;
protected:
    void showchildelements(ptree pt, string _label = "");
public:
    XML_PARSER();
    void traverse_xml(string filename);

};

#endif // XML_PARSER_H
