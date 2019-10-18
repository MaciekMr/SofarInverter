#include "mainmenu.h"
#include "configwindow.h"
#include "mainwindow.h"
#include "logwindow.h"
#include "datacollector.h"
#include "inverterselection.h"

MainMenu::MainMenu(QMainWindow *parent) : parent(parent)
{
    //menuBar = new QMenuBar();
    //createActions();
}


void MainMenu::createActions(){

    //Add first menu
    newfileAct = new QAction(tr("New"), this);
    newfileAct->setShortcuts(QKeySequence::New);
    newfileAct->setStatusTip(tr("Create a new configuration"));
    QObject::connect(newfileAct, &QAction::triggered, this, &MainMenu::newFile);

    connectAct = new QAction(tr("Connect"), this);
    connectAct->setStatusTip(tr("Create a new configuration"));
    QObject::connect(connectAct, &QAction::triggered, this, &MainMenu::connect);

    fileMenu = menuBar->addMenu(tr("&File"));
    //fileMenu->addAction(newfileAct);
    fileMenu->addAction(connectAct);

}
void MainMenu::createMenus(){

}

void MainMenu::newFile(){

    /*QMessageBox msg;
    msg.setText(tr("Info new"));
    msg.exec();*/

    ConfigWindow *config;
    config = new ConfigWindow( this);
    config->show();


}
void MainMenu::connect(){

    QObject * obj = DataCollector::getDataCollector()->findView("logwindow");
    ((LogWindow *)obj)->appendPlainText(tr("Connection to:"));

    //Select the configuration to run
    InverterSelection *invselect = new InverterSelection(this);
    invselect->addelement();
    invselect->show();
    //We need to do following steps:
    //1. Establish timer
    //2. Connect timer with simple thread (to ensure the refresh is happened every second
    //3. Get data from socket
    //4. Put data to text collector (data)
    //5. Sync data with window
    //6. Load data into list of data (records)
    //7. Store data into database


}

void MainMenu::disconnect(){

}
void MainMenu::exit(){

}

void MainMenu::contextMenuEvent(QContextMenuEvent *event){

}
