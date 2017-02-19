#include "wlcmpg.hh"


wlcmpg::wlcmpg(QString userName, QWidget *parent) :
    userName(userName),
    QMainWindow(parent),
    ui(new Ui::wlcmpg)
{
    ui->setupUi(this);
    ui->textBrowser->setText("welcome "+userName);
    ui->textBrowser->setAlignment(Qt::AlignCenter);

}

wlcmpg::~wlcmpg()
{
    delete ui;
}


