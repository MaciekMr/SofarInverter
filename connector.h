#ifndef CONNECTOR_H
#define CONNECTOR_H

#include <QObject>
#include <boost/fusion/include/pair.hpp>
#include <boost/fusion/include/list.hpp>
#include "configwindow.h"

//using boost::fusion::pair;
//using boost::fusion::list;


class worker;

typedef std::pair<string *, string *>  target;
typedef std::pair<unsigned short, target> server_point;
typedef std::pair<worker *, int *> client_thread;
typedef boost::fusion::list<client_thread *, int> workers;


class Worker{

private:
    bool connected;
    string address;
    string port;
    int    worker_id;

public:
    Worker(server_point *);
    int client_connect();
    int client_disconnect();
public slots:
    void update();
};

class Connector
{
private:

public:
    Connector();
};

#endif // CONNECTOR_H
