/********************************************************************************
** Form generated from reading UI file 'chooser.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOOSER_H
#define UI_CHOOSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Chooser
{
public:
    QGridLayout *gridLayout_6;
    QTabWidget *tabWidget;
    QWidget *tabGradiantMorph;
    QPushButton *gradiantChooser;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QSlider *alphaChooserGrad;
    QLabel *labelGradAlpha;
    QLabel *labelGradAlphaValue;
    QLabel *grad_image_label_original;
    QLabel *grad_image_label_mask;
    QLabel *grad_image_label_foreground;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *begin;
    QPushButton *deccel;
    QPushButton *speedDown;
    QPushButton *control;
    QPushButton *speedUp;
    QPushButton *accel;
    QPushButton *end;
    QWidget *tabMoyArith;
    QPushButton *arithChooser;
    QProgressBar *backgroundProgressArith;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *begin_Arith;
    QPushButton *deccel_Arith;
    QPushButton *speedDown_Arith;
    QPushButton *controlArith;
    QPushButton *speedUp_Arith;
    QPushButton *accel_Arith;
    QPushButton *end_Arith;
    QLabel *arith_image_label_original;
    QLabel *arith_image_label_back;
    QLabel *label_7;
    QLabel *arith_image_label_foreground;
    QLabel *arith_image_label_mask;
    QLabel *label_10;
    QLabel *label_8;
    QLabel *label_9;
    QWidget *tabMoyRec;
    QPushButton *recChooser;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLabel *labelRecAlpha;
    QLabel *labelRecAlphaValue;
    QSlider *alphaChooserRec;
    QProgressBar *backgroundProgressRec;
    QLabel *rec_image_label_mask;
    QLabel *rec_image_label_back;
    QLabel *rec_image_label_foreground;
    QLabel *rec_image_label_original;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *begin_Rec;
    QPushButton *deccel_Rec;
    QPushButton *speedDown_Rec;
    QPushButton *controlRec;
    QPushButton *speedUp_Rec;
    QPushButton *accel_Rec;
    QPushButton *end_Rec;
    QWidget *tabMoySD;
    QPushButton *SDChooser;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QSpinBox *NChooser;
    QLabel *labelSDN;
    QLabel *SD_image_label_foreground;
    QLabel *SD_image_label_original;
    QLabel *SD_image_label_mask;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *begin_SD;
    QPushButton *deccel_SD;
    QPushButton *speedDown_SD;
    QPushButton *controlSD;
    QPushButton *speedUp_SD;
    QPushButton *accel_SD;
    QPushButton *end_SD;
    QWidget *tabSAP;
    QPushButton *SAPChooser;
    QWidget *gridLayoutWidget_4;
    QGridLayout *gridLayout_4;
    QSpinBox *multipleChooser;
    QSlider *alphaChooserSAP;
    QLabel *labelSAPMultiple;
    QLabel *labelSAPAlpha;
    QLabel *labelSAPAlphaValue;
    QProgressBar *backgroundProgressSAP;
    QLabel *SAP_image_label_foreground;
    QLabel *SAP_image_label_back;
    QLabel *SAP_image_label_mask;
    QLabel *SAP_image_label_original;
    QWidget *layoutWidget_4;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *begin_SAP;
    QPushButton *deccel_SAP;
    QPushButton *speedDown_SAP;
    QPushButton *controlSAP;
    QPushButton *speedUp_SAP;
    QPushButton *accel_SAP;
    QPushButton *end_SAP;

    void setupUi(QWidget *Chooser)
    {
        if (Chooser->objectName().isEmpty())
            Chooser->setObjectName(QStringLiteral("Chooser"));
        Chooser->resize(1300, 1000);
        gridLayout_6 = new QGridLayout(Chooser);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        tabWidget = new QTabWidget(Chooser);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setContextMenuPolicy(Qt::ActionsContextMenu);
        tabWidget->setTabsClosable(false);
        tabGradiantMorph = new QWidget();
        tabGradiantMorph->setObjectName(QStringLiteral("tabGradiantMorph"));
        tabGradiantMorph->setMouseTracking(false);
        gradiantChooser = new QPushButton(tabGradiantMorph);
        gradiantChooser->setObjectName(QStringLiteral("gradiantChooser"));
        gradiantChooser->setGeometry(QRect(110, 80, 141, 31));
        QIcon icon;
        icon.addFile(QStringLiteral("Resources/Multiple Choice-26.png"), QSize(), QIcon::Normal, QIcon::Off);
        gradiantChooser->setIcon(icon);
        gridLayoutWidget = new QWidget(tabGradiantMorph);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(100, 130, 160, 105));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        alphaChooserGrad = new QSlider(gridLayoutWidget);
        alphaChooserGrad->setObjectName(QStringLiteral("alphaChooserGrad"));
        alphaChooserGrad->setMaximum(1000);
        alphaChooserGrad->setValue(400);
        alphaChooserGrad->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(alphaChooserGrad, 1, 0, 1, 1);

        labelGradAlpha = new QLabel(gridLayoutWidget);
        labelGradAlpha->setObjectName(QStringLiteral("labelGradAlpha"));

        gridLayout->addWidget(labelGradAlpha, 3, 0, 1, 1, Qt::AlignHCenter);

        labelGradAlphaValue = new QLabel(gridLayoutWidget);
        labelGradAlphaValue->setObjectName(QStringLiteral("labelGradAlphaValue"));

        gridLayout->addWidget(labelGradAlphaValue, 0, 0, 1, 1, Qt::AlignHCenter);

        grad_image_label_original = new QLabel(tabGradiantMorph);
        grad_image_label_original->setObjectName(QStringLiteral("grad_image_label_original"));
        grad_image_label_original->setGeometry(QRect(390, 30, 320, 240));
        grad_image_label_original->setScaledContents(true);
        grad_image_label_original->setOpenExternalLinks(false);
        grad_image_label_mask = new QLabel(tabGradiantMorph);
        grad_image_label_mask->setObjectName(QStringLiteral("grad_image_label_mask"));
        grad_image_label_mask->setGeometry(QRect(760, 30, 320, 240));
        grad_image_label_mask->setScaledContents(true);
        grad_image_label_foreground = new QLabel(tabGradiantMorph);
        grad_image_label_foreground->setObjectName(QStringLiteral("grad_image_label_foreground"));
        grad_image_label_foreground->setGeometry(QRect(575, 350, 320, 240));
        grad_image_label_foreground->setScaledContents(true);
        label = new QLabel(tabGradiantMorph);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(500, 300, 101, 20));
        label_2 = new QLabel(tabGradiantMorph);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(840, 300, 161, 20));
        label_3 = new QLabel(tabGradiantMorph);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(700, 610, 81, 20));
        layoutWidget = new QWidget(tabGradiantMorph);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 263, 304, 34));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        begin = new QPushButton(layoutWidget);
        begin->setObjectName(QStringLiteral("begin"));
        QIcon icon1;
        icon1.addFile(QStringLiteral("Resources/MediaControl/Redo-26.png"), QSize(), QIcon::Normal, QIcon::Off);
        begin->setIcon(icon1);
        begin->setIconSize(QSize(26, 26));

        horizontalLayout->addWidget(begin);

        deccel = new QPushButton(layoutWidget);
        deccel->setObjectName(QStringLiteral("deccel"));
        QIcon icon2;
        icon2.addFile(QStringLiteral("Resources/MediaControl/Rewind-26.png"), QSize(), QIcon::Normal, QIcon::Off);
        deccel->setIcon(icon2);
        deccel->setIconSize(QSize(26, 26));

        horizontalLayout->addWidget(deccel);

        speedDown = new QPushButton(layoutWidget);
        speedDown->setObjectName(QStringLiteral("speedDown"));
        QIcon icon3;
        icon3.addFile(QStringLiteral("Resources/MediaControl/Back-26.png"), QSize(), QIcon::Normal, QIcon::Off);
        speedDown->setIcon(icon3);
        speedDown->setIconSize(QSize(26, 26));

        horizontalLayout->addWidget(speedDown);

        control = new QPushButton(layoutWidget);
        control->setObjectName(QStringLiteral("control"));
        QIcon icon4;
        icon4.addFile(QStringLiteral("Resources/MediaControl/Pause-26-Disabled.png"), QSize(), QIcon::Normal, QIcon::Off);
        control->setIcon(icon4);
        control->setIconSize(QSize(26, 26));

        horizontalLayout->addWidget(control);

        speedUp = new QPushButton(layoutWidget);
        speedUp->setObjectName(QStringLiteral("speedUp"));
        QIcon icon5;
        icon5.addFile(QStringLiteral("Resources/MediaControl/Forward-26.png"), QSize(), QIcon::Normal, QIcon::Off);
        speedUp->setIcon(icon5);
        speedUp->setIconSize(QSize(26, 26));

        horizontalLayout->addWidget(speedUp);

        accel = new QPushButton(layoutWidget);
        accel->setObjectName(QStringLiteral("accel"));
        QIcon icon6;
        icon6.addFile(QStringLiteral("Resources/MediaControl/Fast Forward-26.png"), QSize(), QIcon::Normal, QIcon::Off);
        accel->setIcon(icon6);
        accel->setIconSize(QSize(26, 26));

        horizontalLayout->addWidget(accel);

        end = new QPushButton(layoutWidget);
        end->setObjectName(QStringLiteral("end"));
        QIcon icon7;
        icon7.addFile(QStringLiteral("Resources/MediaControl/End-26.png"), QSize(), QIcon::Normal, QIcon::Off);
        end->setIcon(icon7);
        end->setIconSize(QSize(26, 26));

        horizontalLayout->addWidget(end);

        tabWidget->addTab(tabGradiantMorph, QString());
        tabMoyArith = new QWidget();
        tabMoyArith->setObjectName(QStringLiteral("tabMoyArith"));
        arithChooser = new QPushButton(tabMoyArith);
        arithChooser->setObjectName(QStringLiteral("arithChooser"));
        arithChooser->setGeometry(QRect(80, 110, 141, 31));
        arithChooser->setIcon(icon);
        backgroundProgressArith = new QProgressBar(tabMoyArith);
        backgroundProgressArith->setObjectName(QStringLiteral("backgroundProgressArith"));
        backgroundProgressArith->setGeometry(QRect(80, 180, 151, 23));
        backgroundProgressArith->setValue(0);
        layoutWidget1 = new QWidget(tabMoyArith);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 273, 304, 34));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        begin_Arith = new QPushButton(layoutWidget1);
        begin_Arith->setObjectName(QStringLiteral("begin_Arith"));
        begin_Arith->setIcon(icon1);
        begin_Arith->setIconSize(QSize(26, 26));

        horizontalLayout_2->addWidget(begin_Arith);

        deccel_Arith = new QPushButton(layoutWidget1);
        deccel_Arith->setObjectName(QStringLiteral("deccel_Arith"));
        deccel_Arith->setIcon(icon2);
        deccel_Arith->setIconSize(QSize(26, 26));

        horizontalLayout_2->addWidget(deccel_Arith);

        speedDown_Arith = new QPushButton(layoutWidget1);
        speedDown_Arith->setObjectName(QStringLiteral("speedDown_Arith"));
        speedDown_Arith->setIcon(icon3);
        speedDown_Arith->setIconSize(QSize(26, 26));

        horizontalLayout_2->addWidget(speedDown_Arith);

        controlArith = new QPushButton(layoutWidget1);
        controlArith->setObjectName(QStringLiteral("controlArith"));
        QIcon icon8;
        icon8.addFile(QStringLiteral("Resources/MediaControl/Pause-26.png"), QSize(), QIcon::Normal, QIcon::Off);
        controlArith->setIcon(icon8);
        controlArith->setIconSize(QSize(26, 26));

        horizontalLayout_2->addWidget(controlArith);

        speedUp_Arith = new QPushButton(layoutWidget1);
        speedUp_Arith->setObjectName(QStringLiteral("speedUp_Arith"));
        speedUp_Arith->setIcon(icon5);
        speedUp_Arith->setIconSize(QSize(26, 26));

        horizontalLayout_2->addWidget(speedUp_Arith);

        accel_Arith = new QPushButton(layoutWidget1);
        accel_Arith->setObjectName(QStringLiteral("accel_Arith"));
        accel_Arith->setIcon(icon6);
        accel_Arith->setIconSize(QSize(26, 26));

        horizontalLayout_2->addWidget(accel_Arith);

        end_Arith = new QPushButton(layoutWidget1);
        end_Arith->setObjectName(QStringLiteral("end_Arith"));
        end_Arith->setIcon(icon7);
        end_Arith->setIconSize(QSize(26, 26));

        horizontalLayout_2->addWidget(end_Arith);

        arith_image_label_original = new QLabel(tabMoyArith);
        arith_image_label_original->setObjectName(QStringLiteral("arith_image_label_original"));
        arith_image_label_original->setGeometry(QRect(420, 0, 320, 240));
        arith_image_label_original->setScaledContents(true);
        arith_image_label_original->setOpenExternalLinks(false);
        arith_image_label_back = new QLabel(tabMoyArith);
        arith_image_label_back->setObjectName(QStringLiteral("arith_image_label_back"));
        arith_image_label_back->setGeometry(QRect(790, 320, 320, 240));
        label_7 = new QLabel(tabMoyArith);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(525, 260, 111, 20));
        arith_image_label_foreground = new QLabel(tabMoyArith);
        arith_image_label_foreground->setObjectName(QStringLiteral("arith_image_label_foreground"));
        arith_image_label_foreground->setGeometry(QRect(420, 320, 320, 240));
        arith_image_label_mask = new QLabel(tabMoyArith);
        arith_image_label_mask->setObjectName(QStringLiteral("arith_image_label_mask"));
        arith_image_label_mask->setGeometry(QRect(790, 0, 320, 240));
        label_10 = new QLabel(tabMoyArith);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(920, 580, 65, 18));
        label_8 = new QLabel(tabMoyArith);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(870, 260, 161, 20));
        label_9 = new QLabel(tabMoyArith);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(550, 580, 65, 20));
        tabWidget->addTab(tabMoyArith, QString());
        tabMoyRec = new QWidget();
        tabMoyRec->setObjectName(QStringLiteral("tabMoyRec"));
        recChooser = new QPushButton(tabMoyRec);
        recChooser->setObjectName(QStringLiteral("recChooser"));
        recChooser->setGeometry(QRect(90, 80, 141, 31));
        recChooser->setIcon(icon);
        gridLayoutWidget_2 = new QWidget(tabMoyRec);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(80, 130, 160, 97));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        labelRecAlpha = new QLabel(gridLayoutWidget_2);
        labelRecAlpha->setObjectName(QStringLiteral("labelRecAlpha"));

        gridLayout_2->addWidget(labelRecAlpha, 2, 0, 1, 1, Qt::AlignHCenter);

        labelRecAlphaValue = new QLabel(gridLayoutWidget_2);
        labelRecAlphaValue->setObjectName(QStringLiteral("labelRecAlphaValue"));

        gridLayout_2->addWidget(labelRecAlphaValue, 0, 0, 1, 1, Qt::AlignHCenter);

        alphaChooserRec = new QSlider(gridLayoutWidget_2);
        alphaChooserRec->setObjectName(QStringLiteral("alphaChooserRec"));
        alphaChooserRec->setMaximum(1000);
        alphaChooserRec->setValue(5);
        alphaChooserRec->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(alphaChooserRec, 1, 0, 1, 1);

        backgroundProgressRec = new QProgressBar(gridLayoutWidget_2);
        backgroundProgressRec->setObjectName(QStringLiteral("backgroundProgressRec"));
        backgroundProgressRec->setValue(0);

        gridLayout_2->addWidget(backgroundProgressRec, 3, 0, 1, 1);

        rec_image_label_mask = new QLabel(tabMoyRec);
        rec_image_label_mask->setObjectName(QStringLiteral("rec_image_label_mask"));
        rec_image_label_mask->setGeometry(QRect(750, 40, 320, 240));
        rec_image_label_back = new QLabel(tabMoyRec);
        rec_image_label_back->setObjectName(QStringLiteral("rec_image_label_back"));
        rec_image_label_back->setGeometry(QRect(750, 310, 320, 240));
        rec_image_label_foreground = new QLabel(tabMoyRec);
        rec_image_label_foreground->setObjectName(QStringLiteral("rec_image_label_foreground"));
        rec_image_label_foreground->setGeometry(QRect(380, 310, 320, 240));
        rec_image_label_original = new QLabel(tabMoyRec);
        rec_image_label_original->setObjectName(QStringLiteral("rec_image_label_original"));
        rec_image_label_original->setGeometry(QRect(380, 40, 320, 240));
        rec_image_label_original->setScaledContents(true);
        rec_image_label_original->setOpenExternalLinks(false);
        layoutWidget_2 = new QWidget(tabMoyRec);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(20, 250, 301, 41));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        begin_Rec = new QPushButton(layoutWidget_2);
        begin_Rec->setObjectName(QStringLiteral("begin_Rec"));
        begin_Rec->setIcon(icon1);
        begin_Rec->setIconSize(QSize(26, 26));

        horizontalLayout_3->addWidget(begin_Rec);

        deccel_Rec = new QPushButton(layoutWidget_2);
        deccel_Rec->setObjectName(QStringLiteral("deccel_Rec"));
        deccel_Rec->setIcon(icon2);
        deccel_Rec->setIconSize(QSize(26, 26));

        horizontalLayout_3->addWidget(deccel_Rec);

        speedDown_Rec = new QPushButton(layoutWidget_2);
        speedDown_Rec->setObjectName(QStringLiteral("speedDown_Rec"));
        speedDown_Rec->setIcon(icon3);
        speedDown_Rec->setIconSize(QSize(26, 26));

        horizontalLayout_3->addWidget(speedDown_Rec);

        controlRec = new QPushButton(layoutWidget_2);
        controlRec->setObjectName(QStringLiteral("controlRec"));
        controlRec->setIcon(icon8);
        controlRec->setIconSize(QSize(26, 26));

        horizontalLayout_3->addWidget(controlRec);

        speedUp_Rec = new QPushButton(layoutWidget_2);
        speedUp_Rec->setObjectName(QStringLiteral("speedUp_Rec"));
        speedUp_Rec->setIcon(icon5);
        speedUp_Rec->setIconSize(QSize(26, 26));

        horizontalLayout_3->addWidget(speedUp_Rec);

        accel_Rec = new QPushButton(layoutWidget_2);
        accel_Rec->setObjectName(QStringLiteral("accel_Rec"));
        accel_Rec->setIcon(icon6);
        accel_Rec->setIconSize(QSize(26, 26));

        horizontalLayout_3->addWidget(accel_Rec);

        end_Rec = new QPushButton(layoutWidget_2);
        end_Rec->setObjectName(QStringLiteral("end_Rec"));
        end_Rec->setIcon(icon7);
        end_Rec->setIconSize(QSize(26, 26));

        horizontalLayout_3->addWidget(end_Rec);

        tabWidget->addTab(tabMoyRec, QString());
        tabMoySD = new QWidget();
        tabMoySD->setObjectName(QStringLiteral("tabMoySD"));
        SDChooser = new QPushButton(tabMoySD);
        SDChooser->setObjectName(QStringLiteral("SDChooser"));
        SDChooser->setGeometry(QRect(80, 110, 141, 31));
        SDChooser->setIcon(icon);
        gridLayoutWidget_3 = new QWidget(tabMoySD);
        gridLayoutWidget_3->setObjectName(QStringLiteral("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(70, 180, 160, 53));
        gridLayout_3 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        NChooser = new QSpinBox(gridLayoutWidget_3);
        NChooser->setObjectName(QStringLiteral("NChooser"));
        NChooser->setMinimum(1);
        NChooser->setMaximum(6);

        gridLayout_3->addWidget(NChooser, 0, 0, 1, 1);

        labelSDN = new QLabel(gridLayoutWidget_3);
        labelSDN->setObjectName(QStringLiteral("labelSDN"));

        gridLayout_3->addWidget(labelSDN, 1, 0, 1, 1, Qt::AlignHCenter);

        SD_image_label_foreground = new QLabel(tabMoySD);
        SD_image_label_foreground->setObjectName(QStringLiteral("SD_image_label_foreground"));
        SD_image_label_foreground->setGeometry(QRect(535, 350, 320, 240));
        SD_image_label_original = new QLabel(tabMoySD);
        SD_image_label_original->setObjectName(QStringLiteral("SD_image_label_original"));
        SD_image_label_original->setGeometry(QRect(350, 30, 320, 240));
        SD_image_label_original->setScaledContents(true);
        SD_image_label_original->setOpenExternalLinks(false);
        SD_image_label_mask = new QLabel(tabMoySD);
        SD_image_label_mask->setObjectName(QStringLiteral("SD_image_label_mask"));
        SD_image_label_mask->setGeometry(QRect(720, 30, 320, 240));
        label_4 = new QLabel(tabMoySD);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(460, 300, 101, 20));
        label_5 = new QLabel(tabMoySD);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(800, 300, 161, 20));
        label_6 = new QLabel(tabMoySD);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(660, 610, 81, 20));
        layoutWidget_3 = new QWidget(tabMoySD);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(10, 280, 311, 41));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        begin_SD = new QPushButton(layoutWidget_3);
        begin_SD->setObjectName(QStringLiteral("begin_SD"));
        begin_SD->setIcon(icon1);
        begin_SD->setIconSize(QSize(26, 26));

        horizontalLayout_4->addWidget(begin_SD);

        deccel_SD = new QPushButton(layoutWidget_3);
        deccel_SD->setObjectName(QStringLiteral("deccel_SD"));
        deccel_SD->setIcon(icon2);
        deccel_SD->setIconSize(QSize(26, 26));

        horizontalLayout_4->addWidget(deccel_SD);

        speedDown_SD = new QPushButton(layoutWidget_3);
        speedDown_SD->setObjectName(QStringLiteral("speedDown_SD"));
        speedDown_SD->setIcon(icon3);
        speedDown_SD->setIconSize(QSize(26, 26));

        horizontalLayout_4->addWidget(speedDown_SD);

        controlSD = new QPushButton(layoutWidget_3);
        controlSD->setObjectName(QStringLiteral("controlSD"));
        controlSD->setIcon(icon8);
        controlSD->setIconSize(QSize(26, 26));

        horizontalLayout_4->addWidget(controlSD);

        speedUp_SD = new QPushButton(layoutWidget_3);
        speedUp_SD->setObjectName(QStringLiteral("speedUp_SD"));
        speedUp_SD->setIcon(icon5);
        speedUp_SD->setIconSize(QSize(26, 26));

        horizontalLayout_4->addWidget(speedUp_SD);

        accel_SD = new QPushButton(layoutWidget_3);
        accel_SD->setObjectName(QStringLiteral("accel_SD"));
        accel_SD->setIcon(icon6);
        accel_SD->setIconSize(QSize(26, 26));

        horizontalLayout_4->addWidget(accel_SD);

        end_SD = new QPushButton(layoutWidget_3);
        end_SD->setObjectName(QStringLiteral("end_SD"));
        end_SD->setIcon(icon7);
        end_SD->setIconSize(QSize(26, 26));

        horizontalLayout_4->addWidget(end_SD);

        tabWidget->addTab(tabMoySD, QString());
        tabSAP = new QWidget();
        tabSAP->setObjectName(QStringLiteral("tabSAP"));
        SAPChooser = new QPushButton(tabSAP);
        SAPChooser->setObjectName(QStringLiteral("SAPChooser"));
        SAPChooser->setGeometry(QRect(100, 70, 141, 31));
        SAPChooser->setIcon(icon);
        gridLayoutWidget_4 = new QWidget(tabSAP);
        gridLayoutWidget_4->setObjectName(QStringLiteral("gridLayoutWidget_4"));
        gridLayoutWidget_4->setGeometry(QRect(90, 130, 160, 154));
        gridLayout_4 = new QGridLayout(gridLayoutWidget_4);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        multipleChooser = new QSpinBox(gridLayoutWidget_4);
        multipleChooser->setObjectName(QStringLiteral("multipleChooser"));
        multipleChooser->setMinimum(1);
        multipleChooser->setMaximum(8);
        multipleChooser->setValue(1);

        gridLayout_4->addWidget(multipleChooser, 4, 0, 1, 1);

        alphaChooserSAP = new QSlider(gridLayoutWidget_4);
        alphaChooserSAP->setObjectName(QStringLiteral("alphaChooserSAP"));
        alphaChooserSAP->setMaximum(1000);
        alphaChooserSAP->setOrientation(Qt::Horizontal);

        gridLayout_4->addWidget(alphaChooserSAP, 1, 0, 1, 1);

        labelSAPMultiple = new QLabel(gridLayoutWidget_4);
        labelSAPMultiple->setObjectName(QStringLiteral("labelSAPMultiple"));

        gridLayout_4->addWidget(labelSAPMultiple, 5, 0, 1, 1, Qt::AlignHCenter);

        labelSAPAlpha = new QLabel(gridLayoutWidget_4);
        labelSAPAlpha->setObjectName(QStringLiteral("labelSAPAlpha"));

        gridLayout_4->addWidget(labelSAPAlpha, 3, 0, 1, 1, Qt::AlignHCenter);

        labelSAPAlphaValue = new QLabel(gridLayoutWidget_4);
        labelSAPAlphaValue->setObjectName(QStringLiteral("labelSAPAlphaValue"));

        gridLayout_4->addWidget(labelSAPAlphaValue, 0, 0, 1, 1, Qt::AlignHCenter);

        backgroundProgressSAP = new QProgressBar(gridLayoutWidget_4);
        backgroundProgressSAP->setObjectName(QStringLiteral("backgroundProgressSAP"));
        backgroundProgressSAP->setValue(0);

        gridLayout_4->addWidget(backgroundProgressSAP, 6, 0, 1, 1);

        SAP_image_label_foreground = new QLabel(tabSAP);
        SAP_image_label_foreground->setObjectName(QStringLiteral("SAP_image_label_foreground"));
        SAP_image_label_foreground->setGeometry(QRect(400, 310, 320, 240));
        SAP_image_label_back = new QLabel(tabSAP);
        SAP_image_label_back->setObjectName(QStringLiteral("SAP_image_label_back"));
        SAP_image_label_back->setGeometry(QRect(770, 310, 320, 240));
        SAP_image_label_mask = new QLabel(tabSAP);
        SAP_image_label_mask->setObjectName(QStringLiteral("SAP_image_label_mask"));
        SAP_image_label_mask->setGeometry(QRect(770, 40, 320, 240));
        SAP_image_label_original = new QLabel(tabSAP);
        SAP_image_label_original->setObjectName(QStringLiteral("SAP_image_label_original"));
        SAP_image_label_original->setGeometry(QRect(400, 40, 320, 240));
        SAP_image_label_original->setScaledContents(true);
        SAP_image_label_original->setOpenExternalLinks(false);
        layoutWidget_4 = new QWidget(tabSAP);
        layoutWidget_4->setObjectName(QStringLiteral("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(10, 300, 311, 34));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget_4);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        begin_SAP = new QPushButton(layoutWidget_4);
        begin_SAP->setObjectName(QStringLiteral("begin_SAP"));
        begin_SAP->setIcon(icon1);
        begin_SAP->setIconSize(QSize(26, 26));

        horizontalLayout_5->addWidget(begin_SAP);

        deccel_SAP = new QPushButton(layoutWidget_4);
        deccel_SAP->setObjectName(QStringLiteral("deccel_SAP"));
        deccel_SAP->setIcon(icon2);
        deccel_SAP->setIconSize(QSize(26, 26));

        horizontalLayout_5->addWidget(deccel_SAP);

        speedDown_SAP = new QPushButton(layoutWidget_4);
        speedDown_SAP->setObjectName(QStringLiteral("speedDown_SAP"));
        speedDown_SAP->setIcon(icon3);
        speedDown_SAP->setIconSize(QSize(26, 26));

        horizontalLayout_5->addWidget(speedDown_SAP);

        controlSAP = new QPushButton(layoutWidget_4);
        controlSAP->setObjectName(QStringLiteral("controlSAP"));
        controlSAP->setIcon(icon8);
        controlSAP->setIconSize(QSize(26, 26));

        horizontalLayout_5->addWidget(controlSAP);

        speedUp_SAP = new QPushButton(layoutWidget_4);
        speedUp_SAP->setObjectName(QStringLiteral("speedUp_SAP"));
        speedUp_SAP->setIcon(icon5);
        speedUp_SAP->setIconSize(QSize(26, 26));

        horizontalLayout_5->addWidget(speedUp_SAP);

        accel_SAP = new QPushButton(layoutWidget_4);
        accel_SAP->setObjectName(QStringLiteral("accel_SAP"));
        accel_SAP->setIcon(icon6);
        accel_SAP->setIconSize(QSize(26, 26));

        horizontalLayout_5->addWidget(accel_SAP);

        end_SAP = new QPushButton(layoutWidget_4);
        end_SAP->setObjectName(QStringLiteral("end_SAP"));
        end_SAP->setIcon(icon7);
        end_SAP->setIconSize(QSize(26, 26));

        horizontalLayout_5->addWidget(end_SAP);

        tabWidget->addTab(tabSAP, QString());

        gridLayout_6->addWidget(tabWidget, 0, 1, 1, 1);


        retranslateUi(Chooser);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Chooser);
    } // setupUi

    void retranslateUi(QWidget *Chooser)
    {
        Chooser->setWindowTitle(QApplication::translate("Chooser", "Form", 0));
        gradiantChooser->setText(QApplication::translate("Chooser", " Choisir la video", 0));
        labelGradAlpha->setText(QApplication::translate("Chooser", "alpha", 0));
        labelGradAlphaValue->setText(QString());
        grad_image_label_original->setText(QString());
        grad_image_label_mask->setText(QString());
        grad_image_label_foreground->setText(QString());
        label->setText(QApplication::translate("Chooser", "Image originale", 0));
        label_2->setText(QApplication::translate("Chooser", "Masque de mouvemennt", 0));
        label_3->setText(QApplication::translate("Chooser", "Avant plan", 0));
        begin->setText(QString());
        deccel->setText(QString());
        speedDown->setText(QString());
        control->setText(QString());
        speedUp->setText(QString());
        accel->setText(QString());
        end->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tabGradiantMorph), QApplication::translate("Chooser", "Gradiant mophologique oublieux", 0));
        arithChooser->setText(QApplication::translate("Chooser", " Choisir la video", 0));
        begin_Arith->setText(QString());
        deccel_Arith->setText(QString());
        speedDown_Arith->setText(QString());
        controlArith->setText(QString());
        speedUp_Arith->setText(QString());
        accel_Arith->setText(QString());
        end_Arith->setText(QString());
        arith_image_label_original->setText(QString());
        arith_image_label_back->setText(QString());
        label_7->setText(QApplication::translate("Chooser", "Image originale", 0));
        arith_image_label_foreground->setText(QString());
        arith_image_label_mask->setText(QString());
        label_10->setText(QApplication::translate("Chooser", "TextLabel", 0));
        label_8->setText(QApplication::translate("Chooser", "Masque de mouvement", 0));
        label_9->setText(QApplication::translate("Chooser", "TextLabel", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabMoyArith), QApplication::translate("Chooser", "Moyenne arithm\303\251tique", 0));
        recChooser->setText(QApplication::translate("Chooser", " Choisir la video", 0));
        labelRecAlpha->setText(QApplication::translate("Chooser", "alpha", 0));
        labelRecAlphaValue->setText(QString());
        rec_image_label_mask->setText(QString());
        rec_image_label_back->setText(QString());
        rec_image_label_foreground->setText(QString());
        rec_image_label_original->setText(QString());
        begin_Rec->setText(QString());
        deccel_Rec->setText(QString());
        speedDown_Rec->setText(QString());
        controlRec->setText(QString());
        speedUp_Rec->setText(QString());
        accel_Rec->setText(QString());
        end_Rec->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tabMoyRec), QApplication::translate("Chooser", "Moyenne r\303\251cursive", 0));
        SDChooser->setText(QApplication::translate("Chooser", " Choisir la video", 0));
        labelSDN->setText(QApplication::translate("Chooser", "N", 0));
        SD_image_label_foreground->setText(QString());
        SD_image_label_original->setText(QString());
        SD_image_label_mask->setText(QString());
        label_4->setText(QApplication::translate("Chooser", "Image originale", 0));
        label_5->setText(QApplication::translate("Chooser", "Masque de mouvemennt", 0));
        label_6->setText(QApplication::translate("Chooser", "Avant plan", 0));
        begin_SD->setText(QString());
        deccel_SD->setText(QString());
        speedDown_SD->setText(QString());
        controlSD->setText(QString());
        speedUp_SD->setText(QString());
        accel_SD->setText(QString());
        end_SD->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tabMoySD), QApplication::translate("Chooser", "Moyenne \316\243-\342\210\206", 0));
        SAPChooser->setText(QApplication::translate("Chooser", " Choisir la video", 0));
#ifndef QT_NO_TOOLTIP
        labelSAPMultiple->setToolTip(QApplication::translate("Chooser", "Parametre pour le seuillage", 0));
#endif // QT_NO_TOOLTIP
        labelSAPMultiple->setText(QApplication::translate("Chooser", "Multiple", 0));
#ifndef QT_NO_TOOLTIP
        labelSAPAlpha->setToolTip(QApplication::translate("Chooser", "Parametre pour la mise a jour automatique du fond", 0));
#endif // QT_NO_TOOLTIP
        labelSAPAlpha->setText(QApplication::translate("Chooser", "\316\267", 0));
        labelSAPAlphaValue->setText(QString());
        SAP_image_label_foreground->setText(QString());
        SAP_image_label_back->setText(QString());
        SAP_image_label_mask->setText(QString());
        SAP_image_label_original->setText(QString());
        begin_SAP->setText(QString());
        deccel_SAP->setText(QString());
        speedDown_SAP->setText(QString());
        controlSAP->setText(QString());
        speedUp_SAP->setText(QString());
        accel_SAP->setText(QString());
        end_SAP->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tabSAP), QApplication::translate("Chooser", "SAP", 0));
    } // retranslateUi

};

namespace Ui {
    class Chooser: public Ui_Chooser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOOSER_H
