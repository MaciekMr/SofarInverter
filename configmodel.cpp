#include <QMessageBox>
#include "configmodel.h"

ConfigModel::ConfigModel()
{
    config = new configurations();
}


void ConfigModel::test(){


    string st("12");

    this->addparameter<string>("section1","port",st);
    string i = findparameter<string>("section1","port");
    printf("value %s",i.c_str());

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

    /*
    string st("<");
    st.append(SECTION);
    st.append(">");

    string end("<");
    end.append(PARAMETER);
    end.append(">");
    */
    string param("");
    /*
    text_oarchive ta(ar);
    for(auto const &ent1 : *config){

        //store section
        ta << st;
        ta << ent1.first;

        for(auto const &ent2: *ent1.second){

            ta << end;
            ta << ent2.first;
            ta << ent2.second;
        }
    }
    */
    proptree.clear();
    int count = 0;
    //Create XML config file
    //proptree.add("CONFIGURATION")
    for(auto const &ent1 : *config){
        count ++;

        ptree * section = &proptree.add_child("main.SECTION", ptree());

        section->add("<xmlattr>.id", count);
        section->add("INVERTER_NAME", ent1.first);


        for(auto const &ent2: *ent1.second){

            param.assign("PARAMETERS.");
            param.append(ent2.first);
            //owner.add_child(param, ent2.second);
            //owner.add(param, ent2.second);
            section->add(param, ent2.second);
        }
    }
    write_xml(ar,proptree,pretty);
    //write_xml(nullptr, proptree);
}

void ConfigModel::load(std::ifstream &ar){

    /*
    text_iarchive ta(ar);
    istring = ("");
    std::string _section("");
    std::string _param_name("");
    std::string _param_val("");
    //ta >> istring;

    while(ar.peek() != EOF ){

         ta >> istring;
         QMessageBox msg(QMessageBox::Icon::Information, "Info", QString(istring.c_str()));
         msg.exec();

         if(istring.compare("<SECTION>")){

             printf("SECTION");
             ta >> _section;

        }
        if(istring.compare("<PARAMETER>")){

            printf("PARAMETER");
            ta >> _param_name;
            ta >> _param_val;
        }

    }

    */
    proptree.clear();
    read_xml(ar, proptree);

    /*
    ptree& sec1 = proptree.get_child("main.SECTION");
    int      id = sec1.get<int>("<xmlattr>.id");
    string name = sec1.get<std::string>("INVERTER_NAME");
    */
    BOOST_FOREACH( boost::property_tree::ptree::value_type const& node, proptree.get_child( "main" ) )
    {
        boost::property_tree::ptree subtree = node.second;

        if( node.first == "SECTION" )
        {
            //node.second keeps the <xmlattr>
            //int id = node.second.get<int>("<xmlattr>");

            //string name = node.second.get<string>("INVERTER_NAME");
            BOOST_FOREACH( boost::property_tree::ptree::value_type const& v, subtree.get_child( "SECTION" ) )
            {
                std::string label = v.first;

                if ( label != "<xmlattr>" )
                {
                    std::string value = subtree.get<std::string>( label );
                    std::cout << label << ":  " << value << std::endl;
                }
            }
            std::cout << std::endl;
        }
    }
    //get inverter name



    //QMessageBox()

}


ConfigModel * ConfigModel::pointer;
