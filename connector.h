#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <QObject>
#include <boost/fusion/include/pair.hpp>
#include <boost/fusion/include/list.hpp>
#include <map>
#include "threadset.h"
#include "configwindow.h"

//using boost::fusion::pair;
//using boost::fusion::list;

using std::map;

class Worker;

typedef std::pair<string *, string *>  target;
typedef std::pair<unsigned short, target> server_point;
typedef std::pair<Worker *, int *> client_thread;
typedef boost::fusion::list<client_thread *, int> workers;



/*************************************************
 * class Worker
 *
 * Single connect thread, connected to single inverter
 * the status is refreshed by given interval, connected to
 * timer. Each worker class will be triggered by timer
 *
 * When the data is collected (raw data) it will be transfered to
 * decoding class.
 * Worker has a status connected = true. If connected to inverter.
 * If connected = false, the worker will try to reconnect
 * Worker will try to collect data in one shot
 *
 * Used by Inverter class
 *
 * ************************************************/

class Worker:private Thread
{
private:
    bool connected;
    string address;
    string port;
    int    worker_id;

public:
    Worker(int id); //config id
    int client_connect();
    int client_disconnect();
    [[ noreturn ]]
    void comm();
    int getid();
public slots:
    void update();
};


/********************************************
 *
 * class Connector
 * keeps the pointers to all workers (threads)
 * it is static class
 * We can close any thread at any time by id
 *
 * ********************************************/

typedef map<int, Worker*> workermap;

class Connector:private ThreadSet
{
private:
    static Connector * _connector;
    workermap * workers;
public:
    Connector();
    ~Connector();
    static const Connector * getConnector();
    void addWorker(Worker *) const;
    void killWorker(int id);
    void runWorker(int id);

};

#endif // CONNECTOR_H
