#ifndef WELCOME_H
#define WELCOME_H

#include <QWidget>
#include "chooser.h"
#include <QString>
#include "tutorial.h"
namespace Ui {
class Welcome;
}

class Welcome : public QWidget
{
    Q_OBJECT

public:
    explicit Welcome(QWidget *parent = 0);
    ~Welcome();

public slots:
    void on_pushButton_3_clicked();
    void hideThisWidget();

public:
    Ui::Welcome *ui;
    Chooser x;
    Tutorial t;
private slots:
    void on_about_clicked(bool checked);
    void on_pushButton_clicked();

    void on_help_clicked();

public:
    void paintEvent(QPaintEvent *e);
    bool paint;
    QString aboutText;
};

#endif // WELCOME_H
