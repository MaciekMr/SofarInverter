#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QLabel>
#include <QMenuBar>
#include <QMessageBox>

class MainMenu : public QWidget
{
    Q_OBJECT
protected:
    const QMainWindow *parent;
    #ifndef QT_NO_CONTEXTMENU
     void contextMenuEvent(QContextMenuEvent *event) override;
    #endif // QT_NO_CONTEXTMENU



     QMenu          *fileMenu;
     QMenu          *helpMenu;
     QActionGroup   *alignmentGroup;
     QAction        *newfileAct;
     QAction        *connectAct;
     QAction        *disconnectAct;
     QAction        *exitAction;
     QAction        *abourAct;
     QLabel         *infoLabel;
     QMenuBar       *menuBar;

public:
    explicit MainMenu(QMainWindow *parent);// = nullptr);
    void createActions();
    void createMenus();


signals:

public slots:
     void newFile();
     void connect();
     void disconnect();
     void exit();

public slots:


};

#endif // MAINMENU_H
