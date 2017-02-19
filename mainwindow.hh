#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <QMainWindow>
#include <QFile>
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonParseError>
#include "wlcmpg.hh"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    bool checkPassWord();
    void submit();
signals:
    virtual void validUser();

private:
    Ui::MainWindow *ui;
    QString userName;
    QString passWord;
    bool checkPassWord(QString);
    QJsonObject openUserDataFile();
    const QString jsonFileName = "users.json";
    QJsonObject usersArray;
};

#endif // MAINWINDOW_HH
