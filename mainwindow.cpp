#include "mainwindow.h"
#include "datacollector.h"
#include "QtWidgets/QMainWindow"
#include "QtWidgets/QLabel"
#include "QtWidgets/QVBoxLayout"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setupUI(parent);
}


void MainWindow::setupUI(QWidget *MainWindow){


    mainMenu = new MainMenu(this);

    localmenuBar = this->menuBar();

    fileMenu = localmenuBar->addMenu(tr("&File"));

    newfileAct = new QAction(tr("&New"), fileMenu);

    fileMenu->addAction(newfileAct);

    newfileAct->setShortcuts(QKeySequence::New);
    newfileAct->setStatusTip(tr("Create a new file"));

    connect(newfileAct, &QAction::triggered, mainMenu, &MainMenu::newFile);

    connectAct = new QAction(tr("Connect"), this);
    connectAct->setStatusTip(tr("Create a new configuration"));

    connect(connectAct, &QAction::triggered, mainMenu, &MainMenu::connect);

    fileMenu->addAction(connectAct);

    QWidget *widget = new QWidget(this);
    setCentralWidget(widget);
    //! [0]


    //TextBox

    QVBoxLayout *layout = new QVBoxLayout;
    layout->setContentsMargins(5, 5, 5, 5);

    logWindow = new LogWindow(widget);
    logWindow->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    logWindow->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    DataCollector *dt = DataCollector::getDataCollector();
    dt->addView(logWindow, "logwindow");
    layout->addWidget(logWindow);
    layout->setAlignment(logWindow, Qt::AlignTop);

    widget->setLayout(layout);

    this->resize(800, 600);

}

QWidget * MainWindow::getLoggerWindow(){

    return(logWindow);
}


