#ifndef INVERTER_H
#define INVERTER_H
#include <QObject>
#include <QTimer>
#include <stdio.h>
#include "connector.h"

using std::string;



/****************************************************
 *
 * class Inverter
 *
 * present a single converter to connect to
 * Using worker to establish connection to inverter
 * It collect data from inverter every given period
 * (set by timer)
 *
 * **************************************************/



class Inverter: public QObject
{

Q_OBJECT
private:
    string m_address;
    string m_port;
    QTimer *timer;
    Worker *worker;
    void update();

public:
    Inverter();
    ~Inverter();
    void setup(string inv_id);
};

#endif // INVERTER_H
