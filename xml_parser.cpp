#include "xml_parser.h"

xmlparser::xmlparser()
{
    _id = "0";
}

xmlparser::~xmlparser(){

    delete(_ifs);
}



void xmlparser::traverse_xml(){

    read_xml(*_ifs, pt);
    //traverse pt
    //Sked ans;
    BOOST_FOREACH( ptree::value_type const& node, pt.get_child( CONFIG_PATH ) )
    {
        ptree subtree = node.second;

        //std::cout << node.first << std::endl;

        write_xml(std::cout, subtree);
        //std::cout << std::endl;

        //Looking only for "SECTION" inside "CONFIGS"
        if( node.first == SECTION_PATH )
        {
            //extract single configuration
            showchildelements(subtree);

            //std::cout << std::endl;
        }

    }
}



void xmlparser::showchildelements(ptree _pt, string _label){

    //std::cout << _pt.size() << std::endl;
    //Check if the tree has a children
    if(!_pt.empty() && _label != XML_ATTR){


        BOOST_FOREACH( ptree::value_type const& v2, _pt.get_child( "" ) )
        {
            //loop thru the all nodes in the tree
            std::cout << v2.first << std::endl;
            ptree subtree = v2.second;
            showchildelements(subtree, v2.first);
        }

    }else{

        if(_pt.empty()){
            //Return only a pair <name, value>
            std::cout << "label:" << _label << "->" << _pt.data() << std::endl;
            addparameter(_id, _label, _pt.data());

        }else{
            //used if <xmlattr> is attached to label
            BOOST_FOREACH( ptree::value_type const& v2, _pt.get_child( "" ) )
            {

                string label2 = v2.first;
                ptree test = v2.second;

                std::string value3 = _pt.get<std::string>( label2 );
                std::cout << label2 << ":  "  << value3 << std::endl;

                //Set the config ID
                _id = value3;
            }
        }
    }
}
int xmlparser::load_xml(ifstream &ifs){

    _ifs = &ifs;
    traverse_xml();
}

int xmlparser::load_xml(string filename){

    //conf has to passed from configurations
    _filename = filename;
    _ifs = new ifstream(_filename);
    traverse_xml();
}

int xmlparser::getelementcount(){

    int id = std::stoi(_id);//pt.count(CREATE_PATH(CONFIG_PATH, SECTION_PATH));
    return (id);
}


bool xmlparser::addparameter(string part, string parameter, string value){

    std::cout << "part:" << part << " prameter:" << parameter << " value:" << value << std::endl;

    return true;
}
