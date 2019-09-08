#ifndef INVERTER_H
#define INVERTER_H
#include <QObject>

#include <stdio.h>

using std::string;

class Inverter:QObject
{

Q_OBJECT
private:
    string m_address;
    string m_port;

public:
    Inverter();
    ~Inverter();
    void setup();
};

#endif // INVERTER_H
