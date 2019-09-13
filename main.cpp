#include <QApplication>
#include <mainwindow.h>
#include "configmodel.h"
#include "threadset.h"
#include "inverter.h"

void test(){

    for (int var = 0; var < 1000; ++var) {
        printf("val:%d \n",var);
    }
}

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
   // Inverter inv;
   // inv.setup();

    /*
    ConfigModel *conf = ConfigModel::getConfig();
    conf->test();
    */
    MainWindow *mw = new MainWindow();
    mw->show();


    return a.exec();
}
