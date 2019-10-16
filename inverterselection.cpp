#include "inverterselection.h"
#include <QPixmap>
#include "configmodel.h"

InverterSelection::InverterSelection(QWidget *parent) :
    QDialog(parent)
{
    setupUi();

    widlist = new widgetlist();
}

InverterSelection::~InverterSelection()
{
    delete widlist;
}

void InverterSelection::setupUi()
{
    if (this->objectName().isEmpty())
        this->setObjectName(QString::fromUtf8("InverterSelection"));
    this->resize(400, 300);
    buttonBox = new QDialogButtonBox(this);
    buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
    buttonBox->setGeometry(QRect(30, 240, 341, 32));
    buttonBox->setOrientation(Qt::Horizontal);
    buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
    listView = new QListWidget(this);
    listView->setObjectName(QString::fromUtf8("listWidget"));
    listView->setGeometry(QRect(10, 10, 256, 192));
    listView->setSelectionMode(QAbstractItemView::MultiSelection);

    retranslateUi();
    QObject::connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    QObject::connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

    QMetaObject::connectSlotsByName(this);
} // setupUi



void InverterSelection::retranslateUi()
{
    this->setWindowTitle(QCoreApplication::translate("InverterSelection", "Dialog", nullptr));
} // retranslateUi


void InverterSelection::addelement(){

    ConfigModel *conf = ConfigModel::getConfig();

    int i = conf->getelementcount();

    for(const auto & [id, name] : *conf->getheaders()){

        std::cout<<"header:"<<name<<std::endl;
        QListWidgetItem *lwi = new QListWidgetItem(listView);
        widlist->push_back(lwi);
        QPixmap qpm(inverter_ico);
        QIcon qi(qpm);
        lwi->setIcon(qi);
        lwi->setText(QString::fromStdString(name + std::to_string(id)));
        listView->addItem(lwi);

        //confname->addItem(QString::fromStdString(name));
    }

}


void InverterSelection::on_listView_clicked(const QModelIndex &index)
{

}

void InverterSelection::on_listView_doubleClicked(const QModelIndex &index)
{

}

void InverterSelection::on_listView_activated(const QModelIndex &index)
{

}

void InverterSelection::accept(){

    //For all items in listView
    //get the id and start thread
    //add a thread with config

    QList lst = listView->selectedItems();
    std::cout<< lst.count() << "selected" <<std::endl;

    if(lst.count() > 0){

        for(const auto & item : lst){

            std::cout << item->text().toStdString() << std::endl;
            //Start worker with given id

        }

    }


    QDialog::accept();
}
