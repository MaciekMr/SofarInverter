#include "inverter.h"
#include "configmodel.h"
#include "datacollector.h"
#include <threadset.h>
#include <connector.h>

Inverter::Inverter()
{
    timer = new QTimer(this);
    worker = nullptr; //new Worker(new server_point);
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

    m_address.append(conf->findparameter<string>("1","address"));
    m_port.append(conf->findparameter<string>("1","port"));

    //set the server_point
    target _target(&m_address, &m_port);
    //Create Worker
    worker = new Worker(new server_point(1, _target));

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
    //Thread inverter_thread(std::function<Worker>Worker::client_connect, worker);
    Thread inverter_thread(&Worker::client_connect, worker);

    //Get the record


    //Update the logmodel by a new record


    //store record to database

    //end thread
}
