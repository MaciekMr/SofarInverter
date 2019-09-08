#include "inverter.h"
#include "configmodel.h"
#include "datacollector.h"

Inverter::Inverter()
{

}

Inverter::~Inverter(){

}

void Inverter::setup(){

    //1. Set up the connection
    // - get configuration
    ConfigModel *conf = ConfigModel::getConfig();

    m_address.append(*conf->findparameter<string>("1","address"));
    m_port.append(*conf->findparameter<string>("1","port"));

    // - get the pointer to logger

    DataCollector *datacollector = DataCollector::getDataCollector();


}
