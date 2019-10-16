#include "inverter.h"
#include "configmodel.h"
#include "datacollector.h"
#include <threadset.h>
#include <connector.h>
#include "definitions.h"

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

/******************************
 * inv_id - id of configuration of inverter
 *
 * get inverter parameters, ip and port
 * and fire the worker
 *
 * Set up the timer to update data from inverter
 *
 ***********************************/

void Inverter::setup(string inv_id){

    //1. Set up the connection
    // - get configuration
    ConfigModel *conf = ConfigModel::getConfig();

    m_address.append(conf->findparameter<string>(inv_id,IP));
    m_port.append(conf->findparameter<string>(inv_id,PORT));

    //set the server_point
    target _target(&m_address, &m_port);
    //Create Worker
    worker = new Worker(new server_point(1, _target));

    // - get the pointer to logger

    DataCollector *datacollector = DataCollector::getDataCollector();

    auto object = datacollector->findModel("logwindow");

    //Start the worker thread
    Thread inverter_thread(&Worker::client_connect, worker);
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
 * Worker will be unbreakable connected to inverter
 * this method will:
 * 1. Check the connectivity of worker (if unconnected, reconnect)
 * 2. Get the current data from worker
 * 3. Send data to data storage (file, db, xml, etc.)
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
