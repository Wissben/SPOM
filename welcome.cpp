#include "welcome.h"
#include "ui_welcome.h"
#include "opencv2/opencv.hpp"
#include <qmessagebox.h>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/core/core_c.h"
#include "opencv2/core/core.hpp"
#include "opencv2/flann/miniflann.hpp"
#include "opencv2/imgproc/imgproc_c.h"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/ml/ml.hpp"
#include "opencv2/highgui/highgui_c.h"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdint.h>
#include "opencv2/videoio.hpp"
#include <QFileDialog>
#include <QSpinBox>
#include <QShortcut>
#include "chooser.h"
#include <QGraphicsEffect>
#include <QPropertyAnimation>
#include <QThread>
#include <QMediaPlayer>
#include <QDebug>
#include <QSound>
Welcome::Welcome(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Welcome)
{
    ui->setupUi(this);
    this->setGeometry(QRect(408,20,480,640));
    this->setFixedSize(480,640);
    this->setWindowTitle("");
    paint = false;
    ui->aboutText->setVisible(false);
    ui->aboutText->setOpenExternalLinks(true);
    aboutText=" \n\nS.P.O.M(Ségmentation de Plusieurs Objets en Mouvement)"
               "M.M.O.S(Multiple Moving Objects Segmentation)"
"               Cette application a été réalisé par le binôme Bougemgouas Hinda et Benhaddad Wissam dans le cadre de la réalisation du projet de fine de cycle de License"
"               qui a pour but de présenter plusieurs méthodes ( 5 au total) afin de réaliser une segmentation de séquences d'images vidéos présentant plusieurs objets en mouvement"
"               Cette application reste en moins dans sa version initiale donc peut présenter quelques lacunes et bugs mineurs mais reste fonctionnelle au minimum a 90% comme il est demandé"
""
"               Les outils utilisé pour la réalisation de cette application sont : "
"               -Qt qui est une API orientée objet et développée en C++ par Qt Development Frameworks, filiale de Digia. Qt offre des composants d'interface graphique (widgets), d'accès aux données, de connexions réseaux, de gestion des fils d'exécution, d'analyse XML, etc."
"               par certains aspects, elle ressemble à un framework lorsqu'on l'utilise pour concevoir des interfaces graphiques ou que l'on conçoit l'architecture de son application en utilisant les mécanismes des signaux et slots par exemple."
"               more "
"               -C++ est un langage de programmation compilé, permettant la programmation sous de multiples paradigmes comme la programmation procédurale, la programmation orientée objet et la programmation générique. Le langage C++ n'appartient à personne et par conséquent n'importe qui peut l'utiliser sans besoin d'une autorisation ou obligation de payer pour avoir le droit d'utilisation. C++ est l'un des langages de programmation les plus populaires, avec une grande variété de plates-formes matérielles et de systèmes d'exploitation."
"               more"
"               -OpenCV (pour Open Computer Vision) est une bibliothèque graphique libre, initialement développée par Intel, spécialisée dans le traitement d'images en temps réel. La société de robotique Willow Garage et la société ItSeez se sont succédé au support de cette bibliothèque, Depuis 2016 et le rachat de ItSeez par Intel, le support est de nouveau assuré par Intel."
"               more"
""
"               Cette application est OpenSource et est donc disponible au grand publique pour d'eventuelles contributions dans le but d'améliorer ce projet."
"               LienGitHUbHere"
""
"               Made with <3 by Wiss/Hinda";
    ui->aboutText->setAlignment(Qt::AlignCenter);
    aboutText="hh";
    ui->aboutText->setAlignment(Qt::AlignCenter);
    //QPixmap bkgnd("Resources/backgrouds/Plandetravail1VGA.png");
      //      bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
        //    QPalette palette;
          //  palette.setBrush(QPalette::Background, bkgnd);
            //this->setPalette(palette);

             ui->about->setVisible(false);
             ui->about->setEnabled(false);

             ui->pushButton->setVisible(false);
             ui->pushButton->setEnabled(false);

             ui->pushButton_3->setVisible(false);
             ui->pushButton_3->setEnabled(false);

             ui->help->setVisible(false);
             ui->help->setEnabled(false);
            // w is your widget
            QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect(this);
            ui->label->setGraphicsEffect(eff);
            QPropertyAnimation *a = new QPropertyAnimation(eff,"opacity");
           // PLay the sound

            QMediaPlayer *player = new QMediaPlayer;
            player->setMedia(QUrl::fromLocalFile("Resources/Sounds/soo.mp3"));
            player->setVolume(100);
            player->play();
           // end
            a->setDuration(1500);
            a->setStartValue(0);
            a->setEndValue(1);
            a->setEasingCurve(QEasingCurve::InBack);
            a->start(QPropertyAnimation::DeleteWhenStopped);
            QThread::sleep(2);
            //fading away
//            ui->label->setGraphicsEffect(eff);
//            a->setDuration(2000);
//            a->setStartValue(1);
//            a->setEndValue(0);
//            a->setEasingCurve(QEasingCurve::OutBack);
//            a->start(QPropertyAnimation::DeleteWhenStopped);
            connect(a,SIGNAL(finished()),this,SLOT(hideThisWidget()));
            //connect(ui->help,SIGNAL(clicked(bool)),ui->about,SLOT(click()));
            // now implement a slot called hideThisWidget() to do
            // things like hide any background dimmer, etc.

//            ui->about->setVisible(true);
//            ui->about->setEnabled(true);

//            ui->pushButton->setVisible(true);
//            ui->pushButton->setEnabled(true);

//            ui->pushButton_3->setVisible(true);
//            ui->pushButton_3->setEnabled(true);

}
void Welcome::hideThisWidget()
{
                ui->about->setVisible(true);
                ui->about->setEnabled(true);

                ui->pushButton->setVisible(true);
                ui->pushButton->setEnabled(true);

                ui->pushButton_3->setVisible(true);
                ui->pushButton_3->setEnabled(true);

                ui->help->setVisible(true);
                ui->help->setEnabled(true);
}

Welcome::~Welcome()
{
    delete ui;
}

void Welcome::on_pushButton_3_clicked()
{

    x.show();
}

void Welcome::on_about_clicked(bool checked)
{
    paint = !paint;
    if(paint)
    {
        ui->aboutText->setVisible(true);
        ui->aboutText->raise();
        ui->aboutText->setEnabled(true);
        ui->aboutText->setText(aboutText);
    }
    else
    {
        ui->aboutText->setVisible(false);
        ui->aboutText->lower();
        ui->aboutText->setEnabled(false);
    }

}

void Welcome::on_pushButton_clicked()
{
    exit(EXIT_SUCCESS);
}

void Welcome::paintEvent(QPaintEvent *e)
{
}

void Welcome::on_help_clicked()
{
 t.show();
}
