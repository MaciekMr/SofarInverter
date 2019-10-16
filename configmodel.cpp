#include <QMessageBox>
#include "configmodel.h"


ConfigModel * ConfigModel::pointer;

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
    std::cout<<"sect:"<<section<<" name:"<<name<<std::endl;
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

        ptree * section = &proptree.add_child(CREATE_PATH(CONFIG_PATH,SECTION_PATH), ptree());

        section->add(CREATE_PATH(XML_ATTR,ID), count);
        //section->add(CREATE_PATH(PARAMETERS,INV_NAME), ent1.first);


        for(auto const &ent2: *ent1.second){
            param.clear();
            param.append(CREATE_PATH(PARAMETERS,ent2.first));
            //owner.add_child(param, ent2.second);
            //owner.add(param, ent2.second);
            section->add(param, ent2.second);
            std::cout<<ent2.first<<":"<<param<<"->"<<ent2.second<<std::endl;
        }
    }
    write_xml(ar,proptree,pretty);
    //write_xml(nullptr, proptree);
}

void ConfigModel::load(ifstream &ar){

    proptree.clear();
    load_xml(ar);

}


void ConfigModel::load(){

    path myFile = CONF_FILE;
    //Check the existence of file
    if (exists(myFile)){

        ifstream ifs(myFile);
        try {
            load(ifs);

        } catch (ptree_error) {

            //TODO
            //Log error to file
        }

        //Load to controls
        //TODO:

    }
}

bool ConfigModel::addparameter(string part, string parameter, string value){

    std::cout<<part<<":"<<parameter<<"->"<<value<<std::endl;
    addparameter<string>(part, parameter, value);
    return true;
}

int ConfigModel::getelementcount(){

    return(config->size());
}

const header_list * ConfigModel::getheaders(){

    header_list * hdr = new header_list();

    for (const auto& [name, params] : *config) {
        for (const auto& [map_hdr, map_value] : *params){
            std::cout << "Planet " << name << ":\n" << map_hdr << "\n\n";
            if(map_hdr == INV_NAME){
                hdr->push_back(std::make_pair(std::stoi(name), map_value));
                break;
            }
        }
    }

    return (hdr);
}
