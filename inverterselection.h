#ifndef INVERTERSELECTION_H
#define INVERTERSELECTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QListView>
#include <QtWidgets/QListWidget>
#include <QDialog>
#include <list>



/* XPM */
static char *inverter_ico[] = {  \
    /* columns rows colors chars-per-pixel */  \
    "16 16 11 1 ",  \
    "c #020200000101",  \
    ". c #030300000101",    \
    "X c #030301010101",    \
    "o c#020200000202", \
    "O c #030300000202",    \
    "+ c #020201010202",    \
    "@ c#030301010202", \
    "# c #030301010303",    \
    "$ c #040401010202",    \
    "% c #040402020303",    \
    "& c None", \
    /* pixels */    \
    "&&&&&&&&&&O@ &&&", \
    "@@o&&&&&&$@@&&&&", \
    "&@@X&&&&o@@&&&&&", \
    "&X@@&&&&#%@&&&& ", \
    "&&o$.&&&X%@&&&@@", \
    "&&&&X.&&@%%@@@@.", \
    "&&&&&X.&O@%%%@$&", \
    "&&&&&&X.&oOX#o&&", \
    "&&&&&o&X.&&&&&&&", \
    "&&&&@@o&$%%#&&&&", \
    "&&&@%%@&$%%%+&&&", \
    "&&@%%%@&X%%%@$&&", \
    "&@%%%@&&&#%%%@+&", \
    "@%%%@&&&&&#@%%@&", \
    "+@%@&&&&&&&+@%@&", \
    "&@@&&&&&&&&&X@O&"};




namespace Ui {
class InverterSelection;
}

using std::list;

typedef list<QListWidgetItem *> widgetlist;

class InverterSelection : public QDialog
{
    Q_OBJECT
    QDialogButtonBox *buttonBox;
    QListWidget      *listView;
    widgetlist       *widlist;
    void setupUi();
    void retranslateUi();
public:
    explicit InverterSelection(QWidget *parent = nullptr);
    ~InverterSelection();
    void addelement();
private slots:
    void on_listView_clicked(const QModelIndex &index);
    void on_listView_doubleClicked(const QModelIndex &index);
    void on_listView_activated(const QModelIndex &index);
    void accept();
private:

};

#endif // INVERTERSELECTION_H
