#include "configwindow.h"
#include <QCoreApplication>
#include <QMessageBox>
#include "boost/filesystem.hpp"
#include <boost/serialization/map.hpp>
#include <boost/filesystem/fstream.hpp>
#include "boost/archive/text_iarchive.hpp"
#include "boost/archive/text_oarchive.hpp"
#include <iostream>
#include "configmodel.h"



using boost::filesystem::ifstream;
using boost::filesystem::ofstream;
using boost::archive::text_iarchive;
using boost::archive::text_oarchive;



ConfigWindow::ConfigWindow(QWidget * parent):QDialog(parent){

    setupUi();
    conf = nullptr;

    //ConfigModel *conf = ConfigModel::getConfig();

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
    confname = new QComboBox(tab);
    confname->setObjectName(QString::fromUtf8("comboBox"));
    confname->setGeometry(QRect(20, 50, 261, 26));
    confname->setEditable(true);
    ip_address = new QLineEdit(tab);
    ip_address->setObjectName(QString::fromUtf8("lineEdit"));
    ip_address->setGeometry(QRect(20, 120, 161, 31));
    ip_address->setTabletTracking(true);
    ip_address->setFocusPolicy(Qt::ClickFocus);
    ip_address->setInputMask(tr("000.000.000.000; "));
    port_number = new QLineEdit(tab);
    port_number->setObjectName(QString::fromUtf8("lineEdit_2"));
    port_number->setGeometry(QRect(20, 190, 113, 26));
    label = new QLabel(tab);
    label->setObjectName(QString::fromUtf8("label"));
    label->setGeometry(QRect(20, 90, 101, 18));
    label_2 = new QLabel(tab);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    label_2->setGeometry(QRect(20, 160, 101, 18));
    label_3 = new QLabel(tab);
    label_3->setObjectName(QString::fromUtf8("label_3"));
    label_3->setGeometry(QRect(20, 20, 101, 18));
    buttonNew = new QPushButton(tab);
    buttonNew->setObjectName(QString::fromUtf8("buttonNew"));
    buttonNew->setGeometry(QRect(210, 120, 80, 26));
    tabWidget->addTab(tab, QString());
    tab_2 = new QWidget();
    tab_2->setObjectName(QString::fromUtf8("tab_2"));
    lineEdit_3 = new QLineEdit(tab_2);
    lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
    lineEdit_3->setGeometry(QRect(20, 40, 181, 26));
    lineEdit_4 = new QLineEdit(tab_2);
    lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
    lineEdit_4->setGeometry(QRect(20, 90, 181, 26));
    lineEdit_5 = new QLineEdit(tab_2);
    lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
    lineEdit_5->setGeometry(QRect(20, 140, 181, 26));
    label_4 = new QLabel(tab_2);
    label_4->setObjectName(QString::fromUtf8("label_4"));
    label_4->setGeometry(QRect(20, 20, 101, 18));
    label_5 = new QLabel(tab_2);
    label_5->setObjectName(QString::fromUtf8("label_5"));
    label_5->setGeometry(QRect(20, 70, 58, 18));
    label_6 = new QLabel(tab_2);
    label_6->setObjectName(QString::fromUtf8("label_6"));
    label_6->setGeometry(QRect(20, 120, 58, 18));
    lineEdit_6 = new QLineEdit(tab_2);
    lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
    lineEdit_6->setGeometry(QRect(20, 190, 181, 26));
    lineEdit_6->setEchoMode(QLineEdit::Password);
    label_7 = new QLabel(tab_2);
    label_7->setObjectName(QString::fromUtf8("label_7"));
    label_7->setGeometry(QRect(20, 170, 101, 18));
    tabWidget->addTab(tab_2, QString());
    tabWidget->addTab(tab_2, QString());

    retranslateUi();
    /* old way to connect
    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));  //QObject::connect
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
    */
    /**** c++11 way to use */
    connect(buttonBox, &QDialogButtonBox::accepted, this, &ConfigWindow::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &ConfigWindow::reject);
    connect(buttonNew, &QPushButton::clicked, this, &ConfigWindow::new_config);

    QObject::connect(confname, SIGNAL(currentIndexChanged(const int &)), this, SLOT(indexLoad(const int &)));
    QObject::connect(confname, SIGNAL(currentTextChanged(const QString &)), this, SLOT(changed(const QString &)));
    QObject::connect(ip_address, SIGNAL(textChanged(const QString &)), this, SLOT(changed(const QString &)));
    QObject::connect(port_number, SIGNAL(textEdited(const QString &)), this, SLOT(changed(const QString &)));


    tabWidget->setCurrentIndex(0);

    loadconfig();

    QMetaObject::connectSlotsByName(this);

    setconfigs();
} // setupUi

void ConfigWindow::retranslateUi()
{
    this->setWindowTitle(QCoreApplication::translate("ConfigDialog", "Configuration", nullptr));
    label->setText(QCoreApplication::translate("ConfigDialog", "IP address", nullptr));
    label_2->setText(QCoreApplication::translate("ConfigDialog", "Port number", nullptr));
    label_3->setText(QCoreApplication::translate("ConfigDialog", "Name", nullptr));
    buttonNew->setText(QCoreApplication::translate("ConfigDialog", "New ...", nullptr));
    lineEdit_3->setInputMask(QCoreApplication::translate("ConfigDialog", "000.000.000.000;_", nullptr));
    label_4->setText(QCoreApplication::translate("ConfigDialog", "DB IP address", nullptr));
    label_5->setText(QCoreApplication::translate("ConfigDialog", "DB name", nullptr));
    label_6->setText(QCoreApplication::translate("ConfigDialog", "DB User", nullptr));
    label_7->setText(QCoreApplication::translate("ConfigDialog", "DB password", nullptr));
    tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("ConfigDialog", "Connection", nullptr));
    tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("ConfigDialog", "Tab 2", nullptr));
} // retranslateUi


void ConfigWindow::accept(){

    /*if(!conf)
        conf = new configuration();
    QMessageBox msg;
    msg.setText(tr("Are you sure?"));
    msg.exec();*/

    string ip(ip_address->text().toStdString());
    string port(port_number->text().toStdString());
    string inverter(confname->currentText().toStdString());

    ConfigModel *conf = ConfigModel::getConfig();
    int id = conf->getelementcount() + 1;
    string _local_id = std::to_string(id);
    conf->addparameter<std::string>(_local_id, INV_NAME, inverter);
    conf->addparameter<std::string>(_local_id, IP, ip);
    conf->addparameter<std::string>(_local_id, PORT, port);

    //Save configuration

    //folder ./config/

    path myFile = CONF_FILE;

    //Check the existence of file
    if (exists(myFile)){

        ofstream ofs(myFile/*.native()*/);
        conf->save(ofs);



        //ta >> conf; // foo is empty until now, it's fed by myFile
        //std::cout << "Read " << conf.size() << " entries from " << myFile << "\n";
    }else{

        //CREATE THE DIRECTORY
        boost::filesystem::create_directory("./configuration");
        //Create file
        ofstream ofs(myFile.c_str()/*.native()*/);
        //save data
        if(ofs.is_open()){

            conf->save(ofs);

        }else{

               std::cerr<<"Failed to open file : "<<errno<<std::endl;
        }
    }
    QDialog::accept();
}

void ConfigWindow::loadconfig(){


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

void ConfigWindow::new_config(){

    QMessageBox info;
    info.setText(tr("Are you sure?"));
    info.exec();

}


void ConfigWindow::setconfigs(){

    ConfigModel *conf = ConfigModel::getConfig();

    int i = conf->getelementcount();

    for(const auto & [id, name] : *conf->getheaders()){

        std::cout<<"header:"<<name<<std::endl;
        confname->addItem(QString::fromStdString(name));
    }

}


void ConfigWindow::changed(const QString &_t){

    std::cout<<"Text changed!"<<_t.toStdString()<<std::endl;
}

void ConfigWindow::indexLoad(const int & _index){

    //Get the current index and load the IP and PORT
    ConfigModel *conf = ConfigModel::getConfig();
    //Config index is started from 1 where conmbobox started from 0
    string ip   = conf->findparameter<string>(std::to_string(_index + 1), IP);
    string port = conf->findparameter<string>(std::to_string(_index + 1), PORT);

    //Set the values to the fields
    ip_address->setText(QString::fromStdString(ip));
    port_number->setText(QString::fromStdString(port));

}
