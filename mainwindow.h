#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include "QtWidgets/QLabel"
#include <QObject>
#include "logwindow.h"
#include "mainmenu.h"


#define WIDTH  1018
#define HIGHT   722

class MainWindow : public QMainWindow
{
    Q_OBJECT
protected:
    QWidget    * centralWidget;
    LogWindow  * logWindow;
    MainMenu   * mainMenu;
    QLabel     * infoLabel;
    QMenuBar   * localmenuBar;

    QMenu      * fileMenu;
    QAction    * newfileAct;
    QAction    * connectAct;

    void createActions();
    void createMenus();
public:
    explicit MainWindow(QWidget *parent = nullptr);
    void setupUI(QWidget *);
    QWidget * getLoggerWindow();

signals:

public slots:
};

#endif // MAINWINDOW_H
