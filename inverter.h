#ifndef INVERTER_H
#define INVERTER_H
#include <QObject>
#include <QTimer>
#include <stdio.h>

using std::string;

class Inverter: public QObject
{

Q_OBJECT
private:
    string m_address;
    string m_port;
    QTimer *timer;

    void update();

public:
    Inverter();
    ~Inverter();
    void setup();
};

#endif // INVERTER_H
