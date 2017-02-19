#include "mainwindow.hh"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   //connect the pushbutton's click with checkPassWord slot
    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(checkPassWord()));
    //open the file where users' login information exists
    usersArray = this->openUserDataFile();
    //connect the valid user signal to submit slot
    connect(this, SIGNAL(validUser()), this, SLOT(submit()));
    //set properties of password field
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);

}


MainWindow::~MainWindow()
{
    delete ui;
}
bool MainWindow::checkPassWord()
{
    // 1- import username& password
    userName = ui->lineEdit->text();
    passWord = ui->lineEdit_2->text();
    // 2- check the existance of provided information in the json file
    if(usersArray.contains(userName))
        if(usersArray.operator [](userName) == passWord)
        {
            emit(validUser());
            return true;
        }

    QMessageBox warningMessage;
    warningMessage.setText("wrong userName or password. Please try again");
    warningMessage.exec();
    return false;
}

QJsonObject MainWindow::openUserDataFile()
{
    QFile jsonFile(this->jsonFileName);
    jsonFile.open(QFile::ReadOnly);
    QJsonParseError jerror;
    QJsonDocument jdoc= QJsonDocument::fromJson(jsonFile.readAll(),&jerror);
    if(jerror.error != QJsonParseError::NoError)
    {
        QMessageBox warningMessage;
        warningMessage.setText("can not upload user's data. Please communicate with technical support");
        warningMessage.exec();
    }
    return jdoc.object();
}

void MainWindow::submit()
{
    wlcmpg *wlcm = new wlcmpg(userName);
    wlcm->show();
    this->close();
}
