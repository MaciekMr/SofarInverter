#include "inverter.h"
#include "configmodel.h"
#include "datacollector.h"
#include <threadset.h>
#include <connector.h>

Inverter::Inverter()
{
    timer = new QTimer(this);
}

Inverter::~Inverter(){

    if(timer->isActive())
        timer->stop();
    delete(timer);
}

void Inverter::setup(){

    //1. Set up the connection
    // - get configuration
    ConfigModel *conf = ConfigModel::getConfig();

    m_address.append(*conf->findparameter<string>("1","address"));
    m_port.append(*conf->findparameter<string>("1","port"));

    // - get the pointer to logger

    DataCollector *datacollector = DataCollector::getDataCollector();

    auto object = datacollector->findModel("logwindow");

    // - set the timer
    connect(timer, &QTimer::timeout, this, &Inverter::update);
    timer->start(1000);
}


/***********************************
 * Method to use every second by QTimer
 * the interrupt runs the single run thread
 * where the connection is established
 * and data is collected
 *
 *
 * *********************************/

void Inverter::update(){

    //cretate thread

    //Thread *inverter_thread = new Thread(Worker::client_connect());


    //Get the record

    //Update the logmodel by a new record

    //store record to database

    //end thread
}
