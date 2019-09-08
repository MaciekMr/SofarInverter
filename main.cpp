#include <QApplication>
#include <mainwindow.h>
#include "configmodel.h"
#include "threadset.h"

void test(){

    for (int var = 0; var < 1000; ++var) {
        printf("val:%d \n",var);
    }
}

int main(int argc, char *argv[])
{

    Thread td(std::function<void(void)> test);

    QApplication a(argc, argv);
    /*

    ConfigModel *conf = ConfigModel::getConfig();

    conf->test();



    MainWindow *mw = new MainWindow();

    mw->show();
    */

    return a.exec();
}
