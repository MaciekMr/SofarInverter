#include "configwindow.h"
#include <QCoreApplication>
#include <QMessageBox>
#include "boost/filesystem.hpp"
#include <boost/serialization/map.hpp>
#include <boost/filesystem/fstream.hpp>
#include "boost/archive/text_iarchive.hpp"
#include "boost/archive/text_oarchive.hpp"
#include <iostream>

using boost::filesystem::path;
using boost::filesystem::ifstream;
using boost::filesystem::ofstream;
using boost::archive::text_iarchive;
using boost::archive::text_oarchive;



ConfigWindow::ConfigWindow(QWidget * parent){

    setupUi();
}

void ConfigWindow::configuration::set_ip(string ip){

    ip_addr = ip;
}

string ConfigWindow::configuration::get_ip(){

    return(ip_addr);
}

void ConfigWindow::configuration::set_port(unsigned short port){

    port_no = port;
}

unsigned short ConfigWindow::configuration::get_port(){

    return(port_no);
}


void ConfigWindow::setupUi()
{
    if (this->objectName().isEmpty())
        this->setObjectName(QString::fromUtf8("ConfigDialog"));
    this->resize(691, 404);
    this->setSizeGripEnabled(false);
    this->setModal(false);
    buttonBox = new QDialogButtonBox(this);
    buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
    buttonBox->setGeometry(QRect(340, 350, 341, 32));
    buttonBox->setOrientation(Qt::Horizontal);
    buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
    tabWidget = new QTabWidget(this);
    tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
    tabWidget->setGeometry(QRect(10, 60, 671, 281));
    tabWidget->setMouseTracking(false);
    tabWidget->setFocusPolicy(Qt::ClickFocus);
    tab = new QWidget();
    tab->setObjectName(QString::fromUtf8("tab"));
    ip_address = new QLineEdit(tab);
    ip_address->setObjectName(QString::fromUtf8("lineEdit"));
    ip_address->setGeometry(QRect(20, 60, 311, 31));
    ip_address->setTabletTracking(true);
    ip_address->setFocusPolicy(Qt::ClickFocus);
    ip_address->setInputMask(tr("000.000.000.000; "));
    port_number = new QLineEdit(tab);
    port_number->setObjectName(QString::fromUtf8("lineEdit_2"));
    port_number->setGeometry(QRect(20, 130, 113, 26));
    label = new QLabel(tab);
    label->setObjectName(QString::fromUtf8("label"));
    label->setGeometry(QRect(20, 30, 101, 18));
    label_2 = new QLabel(tab);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    label_2->setGeometry(QRect(20, 100, 101, 18));
    tabWidget->addTab(tab, QString());
    tab_2 = new QWidget();
    tab_2->setObjectName(QString::fromUtf8("tab_2"));
    tabWidget->addTab(tab_2, QString());

    retranslateUi();
    QObject::connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    QObject::connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

    tabWidget->setCurrentIndex(0);


    QMetaObject::connectSlotsByName(this);
} // setupUi

void ConfigWindow::retranslateUi()
{
    this->setWindowTitle(QCoreApplication::translate("ConfigDialog", "Configuration", nullptr));
    label->setText(QCoreApplication::translate("ConfigDialog", "IP address", nullptr));
    label_2->setText(QCoreApplication::translate("ConfigDialog", "Port number", nullptr));
    tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("ConfigDialog", "Connection", nullptr));
    tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("ConfigDialog", "Tab 2", nullptr));
} // retranslateUi


void ConfigWindow::accept(){

    if(!conf)
        conf = new configuration();
    /*QMessageBox msg;
    msg.setText(tr("Are you sure?"));
    msg.exec();*/
    //Save configuration
    conf->set_ip(ip_address->text().toStdString());
    //folder ./config/

    conf->set_ip(ip_address->text().toStdString());
    conf->set_port(port_number->text().toInt());

    path myFile = "./configuration/config.dat";
    if (exists(myFile))
       {
           ifstream ifs(myFile/*.native()*/);
           text_iarchive ta(ifs);

           ta >> conf; // foo is empty until now, it's fed by myFile

           //std::cout << "Read " << conf.size() << " entries from " << myFile << "\n";
       } else {

           //CHECK THE DIRECTORY
            boost::filesystem::create_directory("./configuration");

            std::ofstream ofs(myFile.c_str()/*.native()*/);


           if(ofs.is_open()){

            text_oarchive ta(ofs);

            ta << conf; // foo is empty until now, it's fed by myFile
           }else{

               std::cerr<<"Failed to open file : "<<errno<<std::endl;
           }

       }



    QDialog::accept();

}


void ConfigWindow::configuration::serialize(text_oarchive & ar, const unsigned int){

    ar & ip_addr & port_no;
}

void ConfigWindow::configuration::serialize(text_iarchive & ar, const unsigned int){

    ar & ip_addr & port_no;
}


void ConfigWindow::reject(){

    QDialog::reject();
}
