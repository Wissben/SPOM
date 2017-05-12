#include "tutorial.h"
#include "ui_tutorial.h"
#include <QLabel>
#include <QDebug>
#include <QThread>

Tutorial::Tutorial(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tutorial)
{
    this->setFixedSize(1368,680);
    ui->setupUi(this);
    frames.push_back(QPixmap("Resources/Tutorial/Step1.png"));

    ui->first->setVisible(true);
    ui->first->setPixmap(frames.at(0));
    labels.push_back(ui->first);


    frames.push_back(QPixmap("Resources/Tutorial/Step2.png"));
    ui->second->setVisible(false);
    ui->second->setPixmap(frames.at(1));
    labels.push_back(ui->second);


    frames.push_back(QPixmap("Resources/Tutorial/Step3.png"));
    ui->third->setVisible(false);
    ui->third->setPixmap(frames.at(2));
    labels.push_back(ui->third);

    index = 0;

}

Tutorial::~Tutorial()
{
    delete ui;
}

void Tutorial::on_pushButton_2_clicked()
{
    index++;
    if(index>=frames.size())
        index=frames.size()-1;
    for (unsigned int i = 0; i < frames.size(); ++i)
    {
       if(i!=index)
           (labels.at(i))->setVisible(false);
    }
    (labels.at(index))->setVisible(true);
    (labels.at(index))->setPixmap(frames.at(index));
    //qDebug() << labels.at(index);


}

void Tutorial::on_pushButton_clicked()
{
    index--;
    if(index<=0)
        index=0;
    for (unsigned int i = 0; i < frames.size(); ++i)
    {
       if(i!=index)
           (labels.at(i))->setVisible(false);
    }
    (labels.at(index))->setVisible(true);
    (labels.at(index))->setPixmap(frames.at(index));
    //qDebug() << labels.at(index);
}
