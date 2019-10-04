#include "xml_parser.h"

XML_PARSER::XML_PARSER()
{

}




void XML_PARSER::traverse_xml(string filename){

    ifstream ifs(filename);
    read_xml(ifs, pt);

    // traverse pt
    //Sked ans;
    BOOST_FOREACH( ptree::value_type const& node, pt.get_child( CONFIG_PATH ) )
    {
        ptree subtree = node.second;

        std::cout << node.first << std::endl;

        write_xml(std::cout, subtree);
        std::cout << std::endl;

        //Looking only for "SECTION" inside "CONFIGS"
        if( node.first == SECTION_PATH )
        {
            showchildelements(subtree);

            std::cout << std::endl;
        }

    }
}



void XML_PARSER::showchildelements(ptree _pt, string _label){

    std::cout << _pt.size() << std::endl;

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

        }else{
            //used if <xmlattr> is attached to label
            BOOST_FOREACH( ptree::value_type const& v2, _pt.get_child( "" ) )
            {

                string label2 = v2.first;
                ptree test = v2.second;

                std::string value3 = _pt.get<std::string>( label2 );
                std::cout << label2 << ":  "  << value3 << std::endl;
            }
        }
    }
}
