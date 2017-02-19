#ifndef WLCMPG_HH
#define WLCMPG_HH

#include <QMainWindow>
#include "ui_wlcmpg.h"


class wlcmpg: public QMainWindow
{
    Q_OBJECT
public:
    explicit wlcmpg(QString userName, QWidget *parent = 0);
    ~wlcmpg();
private:
    Ui::wlcmpg *ui;
    QString userName;
};


#endif // WLCMPG_HH
