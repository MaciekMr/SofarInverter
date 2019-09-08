#ifndef CONFIGWINDOW_H
#define CONFIGWINDOW_H

#include <QDialog>
#include <stdlib.h>
#include <QDialogButtonBox>
#include <QTabWidget>
#include <QLineEdit>
#include <QGroupBox>
#include <QLabel>
#include "boost/archive/text_iarchive.hpp"
#include "boost/archive/text_oarchive.hpp"

using std::string;
using boost::archive::text_iarchive;
using boost::archive::text_oarchive;

class ConfigWindow : public QDialog
{

    class configuration{
    protected:
        string          ip_addr;
        unsigned short  port_no;
    public:
        void set_ip(string ip);
        void set_port(unsigned short port);
        string get_ip();
        unsigned short get_port();
        void serialize(text_oarchive &, const unsigned int);
        void serialize(text_iarchive &, const unsigned int);
    };

protected:
    QDialogButtonBox *buttonBox;
    QTabWidget  *tabWidget;
    QWidget     *tab;
    QLineEdit   *ip_address;
    QGroupBox   *groupBox;
    QLineEdit   *port_number;
    QGroupBox   *groupBox_2;
    QWidget     *tab_2;
    QLabel *label;
    QLabel *label_2;
    configuration *conf;
public:
    ConfigWindow(QWidget *parent);
    void setupUi();
    void retranslateUi();

private slots:
    void accept();
    void reject();
};

#endif // CONFIGWINDOW_H
