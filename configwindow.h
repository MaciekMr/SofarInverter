#ifndef CONFIGWINDOW_H
#define CONFIGWINDOW_H

#include <QDialog>
#include <stdlib.h>
#include <QDialogButtonBox>
#include <QTabWidget>
#include <QLineEdit>
#include <QGroupBox>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>
#include "boost/archive/text_iarchive.hpp"
#include "boost/archive/text_oarchive.hpp"
#include "configmodel.h"

using std::string;
using boost::archive::text_iarchive;
using boost::archive::text_oarchive;


struct controlls{

    QDialogButtonBox *buttonBox;
    QPushButton      *buttonNew;
    QTabWidget       *tabWidget;
    QWidget          *tab;
    QLineEdit        *ip_address;
    QGroupBox        *groupBox;
    QLineEdit        *port_number;
    QGroupBox        *groupBox_2;
    QWidget          *tab_2;
    QLabel           *label;
    QLabel           *label_2;
    configurations   *conf;
    QComboBox        *confname;
    QLabel           *label_3;
    QLineEdit        *lineEdit_3;
    QLineEdit        *lineEdit_4;
    QLineEdit        *lineEdit_5;
    QLabel           *label_4;
    QLabel           *label_5;
    QLabel           *label_6;
    QLineEdit        *lineEdit_6;
    QLabel           *label_7;
};


class ConfigWindow : public QDialog, ConfigModel, controlls
{

    Q_OBJECT

protected:


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

private:
    void setconfigs();
public:
    ConfigWindow(QWidget *parent);
    void setupUi();
    void retranslateUi();
    void loadconfig();

public slots:
    void accept();
    void reject();
    void new_config();
};

#endif // CONFIGWINDOW_H
