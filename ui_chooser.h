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
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Chooser
{
public:
    QGridLayout *gridLayout_6;
    QPushButton *exit;
    QTabWidget *tabWidget;
    QWidget *tabGradiantMorph;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QSlider *alphaChooserGrad;
    QLabel *labelGradAlpha;
    QProgressBar *progressBarGrad;
    QLabel *labelGradAlphaValue;
    QPushButton *gradiantChooser;
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
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QScrollArea *scrollArea_3;
    QWidget *scrollAreaWidgetContents_3;
    QLabel *label_progressGrad;
    QSlider *GradControl;
    QLabel *counterGrad;
    QTableWidget *grad_results_table;
    QWidget *tabMoyArith;
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
    QScrollArea *scrollArea_4;
    QWidget *scrollAreaWidgetContents_4;
    QScrollArea *scrollArea_5;
    QWidget *scrollAreaWidgetContents_5;
    QScrollArea *scrollArea_6;
    QWidget *scrollAreaWidgetContents_6;
    QScrollArea *scrollArea_7;
    QWidget *scrollAreaWidgetContents_7;
    QLabel *label_progressArith;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout;
    QPushButton *arithChooser;
    QProgressBar *backgroundProgressArith;
    QWidget *layoutWidget_5;
    QVBoxLayout *verticalLayout_3;
    QPushButton *shadowToggleArith;
    QLabel *label_20;
    QSlider *arithControl;
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
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QScrollArea *scrollArea_8;
    QWidget *scrollAreaWidgetContents_8;
    QScrollArea *scrollArea_9;
    QWidget *scrollAreaWidgetContents_9;
    QScrollArea *scrollArea_10;
    QWidget *scrollAreaWidgetContents_10;
    QScrollArea *scrollArea_11;
    QWidget *scrollAreaWidgetContents_11;
    QLabel *label_progressRec;
    QWidget *layoutWidget_6;
    QVBoxLayout *verticalLayout_4;
    QPushButton *shadowToggleRec;
    QLabel *label_21;
    QSlider *RecControl;
    QTableWidget *rec_results_table;
    QWidget *tabMoySD;
    QPushButton *SDChooser;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QSpinBox *NChooser;
    QLabel *labelSDN;
    QProgressBar *progressBarSD;
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
    QScrollArea *scrollArea_12;
    QWidget *scrollAreaWidgetContents_12;
    QScrollArea *scrollArea_13;
    QWidget *scrollAreaWidgetContents_13;
    QScrollArea *scrollArea_14;
    QWidget *scrollAreaWidgetContents_14;
    QLabel *label_progressSD;
    QWidget *layoutWidget_7;
    QVBoxLayout *verticalLayout_5;
    QPushButton *shadowToggleSD;
    QLabel *label_22;
    QSlider *SDControl;
    QTableWidget *SD_results_table;
    QWidget *tabSAP;
    QPushButton *SAPChooser;
    QWidget *gridLayoutWidget_4;
    QGridLayout *gridLayout_4;
    QProgressBar *backgroundProgressSAP;
    QSpinBox *multipleChooser;
    QLabel *labelSAPMultiple;
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
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QScrollArea *scrollArea_15;
    QWidget *scrollAreaWidgetContents_15;
    QScrollArea *scrollArea_16;
    QWidget *scrollAreaWidgetContents_16;
    QScrollArea *scrollArea_17;
    QWidget *scrollAreaWidgetContents_17;
    QScrollArea *scrollArea_18;
    QWidget *scrollAreaWidgetContents_18;
    QLabel *label_progressSAP;
    QWidget *layoutWidget_8;
    QVBoxLayout *verticalLayout_6;
    QPushButton *shadowToggleSAP;
    QLabel *label_23;
    QSlider *SAPControl;
    QTableWidget *SAP_results_table;
    QSlider *alphaChooserSAP;
    QLabel *labelSAPAlpha;
    QLabel *labelSAPAlphaValue;

    void setupUi(QWidget *Chooser)
    {
        if (Chooser->objectName().isEmpty())
            Chooser->setObjectName(QStringLiteral("Chooser"));
        Chooser->resize(1300, 768);
        QIcon icon;
        icon.addFile(QStringLiteral("Resources/backgrouds/Sans-titre-1.png"), QSize(), QIcon::Normal, QIcon::Off);
        Chooser->setWindowIcon(icon);
        gridLayout_6 = new QGridLayout(Chooser);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        exit = new QPushButton(Chooser);
        exit->setObjectName(QStringLiteral("exit"));
        exit->setFocusPolicy(Qt::NoFocus);
        exit->setFlat(true);

        gridLayout_6->addWidget(exit, 4, 0, 1, 1);

        tabWidget = new QTabWidget(Chooser);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setFocusPolicy(Qt::NoFocus);
        tabWidget->setContextMenuPolicy(Qt::ActionsContextMenu);
        tabWidget->setTabsClosable(false);
        tabGradiantMorph = new QWidget();
        tabGradiantMorph->setObjectName(QStringLiteral("tabGradiantMorph"));
        tabGradiantMorph->setMouseTracking(false);
        gridLayoutWidget = new QWidget(tabGradiantMorph);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(100, 10, 160, 151));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        alphaChooserGrad = new QSlider(gridLayoutWidget);
        alphaChooserGrad->setObjectName(QStringLiteral("alphaChooserGrad"));
        alphaChooserGrad->setFocusPolicy(Qt::NoFocus);
        alphaChooserGrad->setMaximum(1000);
        alphaChooserGrad->setValue(400);
        alphaChooserGrad->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(alphaChooserGrad, 2, 0, 1, 1);

        labelGradAlpha = new QLabel(gridLayoutWidget);
        labelGradAlpha->setObjectName(QStringLiteral("labelGradAlpha"));

        gridLayout->addWidget(labelGradAlpha, 4, 0, 1, 1, Qt::AlignHCenter);

        progressBarGrad = new QProgressBar(gridLayoutWidget);
        progressBarGrad->setObjectName(QStringLiteral("progressBarGrad"));
        progressBarGrad->setValue(0);
        progressBarGrad->setInvertedAppearance(false);

        gridLayout->addWidget(progressBarGrad, 5, 0, 1, 1);

        labelGradAlphaValue = new QLabel(gridLayoutWidget);
        labelGradAlphaValue->setObjectName(QStringLiteral("labelGradAlphaValue"));

        gridLayout->addWidget(labelGradAlphaValue, 1, 0, 1, 1);

        gradiantChooser = new QPushButton(gridLayoutWidget);
        gradiantChooser->setObjectName(QStringLiteral("gradiantChooser"));
        gradiantChooser->setFocusPolicy(Qt::NoFocus);
        QIcon icon1;
        icon1.addFile(QStringLiteral("Resources/Multiple Choice-26.png"), QSize(), QIcon::Normal, QIcon::Off);
        gradiantChooser->setIcon(icon1);
        gradiantChooser->setIconSize(QSize(26, 26));

        gridLayout->addWidget(gradiantChooser, 0, 0, 1, 1);

        grad_image_label_original = new QLabel(tabGradiantMorph);
        grad_image_label_original->setObjectName(QStringLiteral("grad_image_label_original"));
        grad_image_label_original->setGeometry(QRect(390, 0, 320, 240));
        grad_image_label_original->setScaledContents(true);
        grad_image_label_original->setOpenExternalLinks(false);
        grad_image_label_mask = new QLabel(tabGradiantMorph);
        grad_image_label_mask->setObjectName(QStringLiteral("grad_image_label_mask"));
        grad_image_label_mask->setGeometry(QRect(760, 0, 320, 240));
        grad_image_label_mask->setScaledContents(true);
        grad_image_label_foreground = new QLabel(tabGradiantMorph);
        grad_image_label_foreground->setObjectName(QStringLiteral("grad_image_label_foreground"));
        grad_image_label_foreground->setGeometry(QRect(575, 320, 320, 240));
        grad_image_label_foreground->setScaledContents(true);
        label = new QLabel(tabGradiantMorph);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(500, 270, 101, 20));
        label_2 = new QLabel(tabGradiantMorph);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(840, 270, 161, 20));
        label_3 = new QLabel(tabGradiantMorph);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(700, 580, 81, 20));
        layoutWidget = new QWidget(tabGradiantMorph);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(23, 243, 321, 34));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        begin = new QPushButton(layoutWidget);
        begin->setObjectName(QStringLiteral("begin"));
        begin->setFocusPolicy(Qt::NoFocus);
        QIcon icon2;
        icon2.addFile(QStringLiteral("Resources/MediaControl/Redo-26.png"), QSize(), QIcon::Normal, QIcon::Off);
        begin->setIcon(icon2);
        begin->setIconSize(QSize(26, 26));

        horizontalLayout->addWidget(begin);

        deccel = new QPushButton(layoutWidget);
        deccel->setObjectName(QStringLiteral("deccel"));
        deccel->setFocusPolicy(Qt::NoFocus);
        QIcon icon3;
        icon3.addFile(QStringLiteral("Resources/MediaControl/Rewind-26.png"), QSize(), QIcon::Normal, QIcon::Off);
        deccel->setIcon(icon3);
        deccel->setIconSize(QSize(26, 26));

        horizontalLayout->addWidget(deccel);

        speedDown = new QPushButton(layoutWidget);
        speedDown->setObjectName(QStringLiteral("speedDown"));
        speedDown->setFocusPolicy(Qt::NoFocus);
        QIcon icon4;
        icon4.addFile(QStringLiteral("Resources/MediaControl/Back-26.png"), QSize(), QIcon::Normal, QIcon::Off);
        speedDown->setIcon(icon4);
        speedDown->setIconSize(QSize(26, 26));

        horizontalLayout->addWidget(speedDown);

        control = new QPushButton(layoutWidget);
        control->setObjectName(QStringLiteral("control"));
        control->setFocusPolicy(Qt::NoFocus);
        QIcon icon5;
        icon5.addFile(QStringLiteral("Resources/MediaControl/Pause-26-Disabled.png"), QSize(), QIcon::Normal, QIcon::Off);
        control->setIcon(icon5);
        control->setIconSize(QSize(26, 26));

        horizontalLayout->addWidget(control);

        speedUp = new QPushButton(layoutWidget);
        speedUp->setObjectName(QStringLiteral("speedUp"));
        speedUp->setFocusPolicy(Qt::NoFocus);
        QIcon icon6;
        icon6.addFile(QStringLiteral("Resources/MediaControl/Forward-26.png"), QSize(), QIcon::Normal, QIcon::Off);
        speedUp->setIcon(icon6);
        speedUp->setIconSize(QSize(26, 26));

        horizontalLayout->addWidget(speedUp);

        accel = new QPushButton(layoutWidget);
        accel->setObjectName(QStringLiteral("accel"));
        accel->setFocusPolicy(Qt::NoFocus);
        QIcon icon7;
        icon7.addFile(QStringLiteral("Resources/MediaControl/Fast Forward-26.png"), QSize(), QIcon::Normal, QIcon::Off);
        accel->setIcon(icon7);
        accel->setIconSize(QSize(26, 26));

        horizontalLayout->addWidget(accel);

        end = new QPushButton(layoutWidget);
        end->setObjectName(QStringLiteral("end"));
        end->setFocusPolicy(Qt::NoFocus);
        QIcon icon8;
        icon8.addFile(QStringLiteral("Resources/MediaControl/End-26.png"), QSize(), QIcon::Normal, QIcon::Off);
        end->setIcon(icon8);
        end->setIconSize(QSize(26, 26));

        horizontalLayout->addWidget(end);

        scrollArea = new QScrollArea(tabGradiantMorph);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setGeometry(QRect(390, 0, 320, 240));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 318, 238));
        scrollArea->setWidget(scrollAreaWidgetContents);
        scrollArea_2 = new QScrollArea(tabGradiantMorph);
        scrollArea_2->setObjectName(QStringLiteral("scrollArea_2"));
        scrollArea_2->setGeometry(QRect(760, 0, 320, 240));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 318, 238));
        scrollArea_2->setWidget(scrollAreaWidgetContents_2);
        scrollArea_3 = new QScrollArea(tabGradiantMorph);
        scrollArea_3->setObjectName(QStringLiteral("scrollArea_3"));
        scrollArea_3->setGeometry(QRect(575, 320, 320, 240));
        scrollArea_3->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QStringLiteral("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 318, 238));
        scrollArea_3->setWidget(scrollAreaWidgetContents_3);
        label_progressGrad = new QLabel(tabGradiantMorph);
        label_progressGrad->setObjectName(QStringLiteral("label_progressGrad"));
        label_progressGrad->setGeometry(QRect(25, 170, 311, 20));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_progressGrad->sizePolicy().hasHeightForWidth());
        label_progressGrad->setSizePolicy(sizePolicy);
        label_progressGrad->setMaximumSize(QSize(393, 48));
        label_progressGrad->setMidLineWidth(0);
        label_progressGrad->setTextFormat(Qt::AutoText);
        label_progressGrad->setAlignment(Qt::AlignCenter);
        GradControl = new QSlider(tabGradiantMorph);
        GradControl->setObjectName(QStringLiteral("GradControl"));
        GradControl->setGeometry(QRect(20, 220, 321, 20));
        GradControl->setOrientation(Qt::Horizontal);
        counterGrad = new QLabel(tabGradiantMorph);
        counterGrad->setObjectName(QStringLiteral("counterGrad"));
        counterGrad->setGeometry(QRect(24, 310, 321, 20));
        counterGrad->setAlignment(Qt::AlignCenter);
        grad_results_table = new QTableWidget(tabGradiantMorph);
        grad_results_table->setObjectName(QStringLiteral("grad_results_table"));
        grad_results_table->setGeometry(QRect(60, 310, 250, 192));
        tabWidget->addTab(tabGradiantMorph, QString());
        layoutWidget->raise();
        gridLayoutWidget->raise();
        label->raise();
        label_2->raise();
        label_3->raise();
        scrollArea->raise();
        scrollArea_2->raise();
        scrollArea_3->raise();
        grad_image_label_foreground->raise();
        grad_image_label_mask->raise();
        grad_image_label_original->raise();
        label_progressGrad->raise();
        GradControl->raise();
        counterGrad->raise();
        grad_results_table->raise();
        tabMoyArith = new QWidget();
        tabMoyArith->setObjectName(QStringLiteral("tabMoyArith"));
        layoutWidget1 = new QWidget(tabMoyArith);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 190, 325, 34));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        begin_Arith = new QPushButton(layoutWidget1);
        begin_Arith->setObjectName(QStringLiteral("begin_Arith"));
        begin_Arith->setIcon(icon2);
        begin_Arith->setIconSize(QSize(26, 26));

        horizontalLayout_2->addWidget(begin_Arith);

        deccel_Arith = new QPushButton(layoutWidget1);
        deccel_Arith->setObjectName(QStringLiteral("deccel_Arith"));
        deccel_Arith->setIcon(icon3);
        deccel_Arith->setIconSize(QSize(26, 26));

        horizontalLayout_2->addWidget(deccel_Arith);

        speedDown_Arith = new QPushButton(layoutWidget1);
        speedDown_Arith->setObjectName(QStringLiteral("speedDown_Arith"));
        speedDown_Arith->setIcon(icon4);
        speedDown_Arith->setIconSize(QSize(26, 26));

        horizontalLayout_2->addWidget(speedDown_Arith);

        controlArith = new QPushButton(layoutWidget1);
        controlArith->setObjectName(QStringLiteral("controlArith"));
        QIcon icon9;
        icon9.addFile(QStringLiteral("Resources/MediaControl/Pause-26.png"), QSize(), QIcon::Normal, QIcon::Off);
        controlArith->setIcon(icon9);
        controlArith->setIconSize(QSize(26, 26));

        horizontalLayout_2->addWidget(controlArith);

        speedUp_Arith = new QPushButton(layoutWidget1);
        speedUp_Arith->setObjectName(QStringLiteral("speedUp_Arith"));
        speedUp_Arith->setIcon(icon6);
        speedUp_Arith->setIconSize(QSize(26, 26));

        horizontalLayout_2->addWidget(speedUp_Arith);

        accel_Arith = new QPushButton(layoutWidget1);
        accel_Arith->setObjectName(QStringLiteral("accel_Arith"));
        accel_Arith->setIcon(icon7);
        accel_Arith->setIconSize(QSize(26, 26));

        horizontalLayout_2->addWidget(accel_Arith);

        end_Arith = new QPushButton(layoutWidget1);
        end_Arith->setObjectName(QStringLiteral("end_Arith"));
        end_Arith->setIcon(icon8);
        end_Arith->setIconSize(QSize(26, 26));

        horizontalLayout_2->addWidget(end_Arith);

        arith_image_label_original = new QLabel(tabMoyArith);
        arith_image_label_original->setObjectName(QStringLiteral("arith_image_label_original"));
        arith_image_label_original->setGeometry(QRect(420, 0, 320, 240));
        arith_image_label_original->setScaledContents(true);
        arith_image_label_original->setOpenExternalLinks(false);
        arith_image_label_back = new QLabel(tabMoyArith);
        arith_image_label_back->setObjectName(QStringLiteral("arith_image_label_back"));
        arith_image_label_back->setGeometry(QRect(790, 0, 320, 240));
        arith_image_label_back->setScaledContents(true);
        label_7 = new QLabel(tabMoyArith);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(475, 260, 221, 20));
        label_7->setAlignment(Qt::AlignCenter);
        arith_image_label_foreground = new QLabel(tabMoyArith);
        arith_image_label_foreground->setObjectName(QStringLiteral("arith_image_label_foreground"));
        arith_image_label_foreground->setGeometry(QRect(790, 320, 320, 240));
        arith_image_label_foreground->setScaledContents(true);
        arith_image_label_mask = new QLabel(tabMoyArith);
        arith_image_label_mask->setObjectName(QStringLiteral("arith_image_label_mask"));
        arith_image_label_mask->setGeometry(QRect(420, 320, 320, 240));
        arith_image_label_mask->setScaledContents(true);
        label_10 = new QLabel(tabMoyArith);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(910, 260, 81, 18));
        label_8 = new QLabel(tabMoyArith);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(510, 580, 161, 20));
        label_9 = new QLabel(tabMoyArith);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(910, 580, 81, 20));
        scrollArea_4 = new QScrollArea(tabMoyArith);
        scrollArea_4->setObjectName(QStringLiteral("scrollArea_4"));
        scrollArea_4->setGeometry(QRect(420, 0, 320, 240));
        scrollArea_4->setWidgetResizable(true);
        scrollAreaWidgetContents_4 = new QWidget();
        scrollAreaWidgetContents_4->setObjectName(QStringLiteral("scrollAreaWidgetContents_4"));
        scrollAreaWidgetContents_4->setGeometry(QRect(0, 0, 318, 238));
        scrollArea_4->setWidget(scrollAreaWidgetContents_4);
        scrollArea_5 = new QScrollArea(tabMoyArith);
        scrollArea_5->setObjectName(QStringLiteral("scrollArea_5"));
        scrollArea_5->setGeometry(QRect(790, 0, 320, 240));
        scrollArea_5->setWidgetResizable(true);
        scrollAreaWidgetContents_5 = new QWidget();
        scrollAreaWidgetContents_5->setObjectName(QStringLiteral("scrollAreaWidgetContents_5"));
        scrollAreaWidgetContents_5->setGeometry(QRect(0, 0, 318, 238));
        scrollArea_5->setWidget(scrollAreaWidgetContents_5);
        scrollArea_6 = new QScrollArea(tabMoyArith);
        scrollArea_6->setObjectName(QStringLiteral("scrollArea_6"));
        scrollArea_6->setGeometry(QRect(420, 320, 320, 240));
        scrollArea_6->setWidgetResizable(true);
        scrollAreaWidgetContents_6 = new QWidget();
        scrollAreaWidgetContents_6->setObjectName(QStringLiteral("scrollAreaWidgetContents_6"));
        scrollAreaWidgetContents_6->setGeometry(QRect(0, 0, 318, 238));
        scrollArea_6->setWidget(scrollAreaWidgetContents_6);
        scrollArea_7 = new QScrollArea(tabMoyArith);
        scrollArea_7->setObjectName(QStringLiteral("scrollArea_7"));
        scrollArea_7->setGeometry(QRect(790, 320, 320, 240));
        scrollArea_7->setWidgetResizable(true);
        scrollAreaWidgetContents_7 = new QWidget();
        scrollAreaWidgetContents_7->setObjectName(QStringLiteral("scrollAreaWidgetContents_7"));
        scrollAreaWidgetContents_7->setGeometry(QRect(0, 0, 318, 238));
        scrollArea_7->setWidget(scrollAreaWidgetContents_7);
        label_progressArith = new QLabel(tabMoyArith);
        label_progressArith->setObjectName(QStringLiteral("label_progressArith"));
        label_progressArith->setGeometry(QRect(10, 110, 321, 20));
        label_progressArith->setAlignment(Qt::AlignCenter);
        layoutWidget2 = new QWidget(tabMoyArith);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(80, 10, 161, 84));
        verticalLayout = new QVBoxLayout(layoutWidget2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        arithChooser = new QPushButton(layoutWidget2);
        arithChooser->setObjectName(QStringLiteral("arithChooser"));
        arithChooser->setIcon(icon1);
        arithChooser->setIconSize(QSize(26, 26));

        verticalLayout->addWidget(arithChooser);

        backgroundProgressArith = new QProgressBar(layoutWidget2);
        backgroundProgressArith->setObjectName(QStringLiteral("backgroundProgressArith"));
        backgroundProgressArith->setValue(0);

        verticalLayout->addWidget(backgroundProgressArith);

        layoutWidget_5 = new QWidget(tabMoyArith);
        layoutWidget_5->setObjectName(QStringLiteral("layoutWidget_5"));
        layoutWidget_5->setGeometry(QRect(90, 250, 142, 86));
        verticalLayout_3 = new QVBoxLayout(layoutWidget_5);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        shadowToggleArith = new QPushButton(layoutWidget_5);
        shadowToggleArith->setObjectName(QStringLiteral("shadowToggleArith"));
        shadowToggleArith->setFocusPolicy(Qt::NoFocus);
        shadowToggleArith->setStyleSheet(QLatin1String("border-style: solid;\n"
"border-width: 5px;\n"
"border-radius: 15px;"));
        QIcon icon10;
        icon10.addFile(QStringLiteral("Resources/Toggle On-96.png"), QSize(), QIcon::Normal, QIcon::Off);
        shadowToggleArith->setIcon(icon10);
        shadowToggleArith->setIconSize(QSize(50, 50));
        shadowToggleArith->setCheckable(false);
        shadowToggleArith->setFlat(true);

        verticalLayout_3->addWidget(shadowToggleArith);

        label_20 = new QLabel(layoutWidget_5);
        label_20->setObjectName(QStringLiteral("label_20"));

        verticalLayout_3->addWidget(label_20);

        arithControl = new QSlider(tabMoyArith);
        arithControl->setObjectName(QStringLiteral("arithControl"));
        arithControl->setGeometry(QRect(5, 167, 332, 20));
        arithControl->setOrientation(Qt::Horizontal);
        tabWidget->addTab(tabMoyArith, QString());
        layoutWidget->raise();
        layoutWidget->raise();
        label_7->raise();
        label_10->raise();
        label_8->raise();
        label_9->raise();
        scrollArea_4->raise();
        scrollArea_5->raise();
        scrollArea_6->raise();
        scrollArea_7->raise();
        arith_image_label_back->raise();
        arith_image_label_foreground->raise();
        arith_image_label_mask->raise();
        arith_image_label_original->raise();
        label_progressArith->raise();
        layoutWidget_5->raise();
        arithControl->raise();
        tabMoyRec = new QWidget();
        tabMoyRec->setObjectName(QStringLiteral("tabMoyRec"));
        recChooser = new QPushButton(tabMoyRec);
        recChooser->setObjectName(QStringLiteral("recChooser"));
        recChooser->setGeometry(QRect(100, 20, 141, 31));
        recChooser->setFocusPolicy(Qt::NoFocus);
        recChooser->setIcon(icon1);
        recChooser->setIconSize(QSize(26, 26));
        gridLayoutWidget_2 = new QWidget(tabMoyRec);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(90, 60, 160, 121));
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
        rec_image_label_mask->setGeometry(QRect(420, 320, 320, 240));
        rec_image_label_mask->setScaledContents(true);
        rec_image_label_back = new QLabel(tabMoyRec);
        rec_image_label_back->setObjectName(QStringLiteral("rec_image_label_back"));
        rec_image_label_back->setGeometry(QRect(790, 0, 320, 240));
        rec_image_label_back->setScaledContents(true);
        rec_image_label_foreground = new QLabel(tabMoyRec);
        rec_image_label_foreground->setObjectName(QStringLiteral("rec_image_label_foreground"));
        rec_image_label_foreground->setGeometry(QRect(790, 320, 320, 240));
        rec_image_label_foreground->setScaledContents(true);
        rec_image_label_original = new QLabel(tabMoyRec);
        rec_image_label_original->setObjectName(QStringLiteral("rec_image_label_original"));
        rec_image_label_original->setGeometry(QRect(420, 0, 320, 240));
        rec_image_label_original->setScaledContents(true);
        rec_image_label_original->setOpenExternalLinks(false);
        layoutWidget_2 = new QWidget(tabMoyRec);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(13, 250, 321, 41));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        begin_Rec = new QPushButton(layoutWidget_2);
        begin_Rec->setObjectName(QStringLiteral("begin_Rec"));
        begin_Rec->setIcon(icon2);
        begin_Rec->setIconSize(QSize(26, 26));

        horizontalLayout_3->addWidget(begin_Rec);

        deccel_Rec = new QPushButton(layoutWidget_2);
        deccel_Rec->setObjectName(QStringLiteral("deccel_Rec"));
        deccel_Rec->setIcon(icon3);
        deccel_Rec->setIconSize(QSize(26, 26));

        horizontalLayout_3->addWidget(deccel_Rec);

        speedDown_Rec = new QPushButton(layoutWidget_2);
        speedDown_Rec->setObjectName(QStringLiteral("speedDown_Rec"));
        speedDown_Rec->setIcon(icon4);
        speedDown_Rec->setIconSize(QSize(26, 26));

        horizontalLayout_3->addWidget(speedDown_Rec);

        controlRec = new QPushButton(layoutWidget_2);
        controlRec->setObjectName(QStringLiteral("controlRec"));
        controlRec->setIcon(icon9);
        controlRec->setIconSize(QSize(26, 26));

        horizontalLayout_3->addWidget(controlRec);

        speedUp_Rec = new QPushButton(layoutWidget_2);
        speedUp_Rec->setObjectName(QStringLiteral("speedUp_Rec"));
        speedUp_Rec->setIcon(icon6);
        speedUp_Rec->setIconSize(QSize(26, 26));

        horizontalLayout_3->addWidget(speedUp_Rec);

        accel_Rec = new QPushButton(layoutWidget_2);
        accel_Rec->setObjectName(QStringLiteral("accel_Rec"));
        accel_Rec->setIcon(icon7);
        accel_Rec->setIconSize(QSize(26, 26));

        horizontalLayout_3->addWidget(accel_Rec);

        end_Rec = new QPushButton(layoutWidget_2);
        end_Rec->setObjectName(QStringLiteral("end_Rec"));
        end_Rec->setIcon(icon8);
        end_Rec->setIconSize(QSize(26, 26));

        horizontalLayout_3->addWidget(end_Rec);

        label_11 = new QLabel(tabMoyRec);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(500, 580, 161, 20));
        label_12 = new QLabel(tabMoyRec);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(525, 260, 111, 20));
        label_13 = new QLabel(tabMoyRec);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(910, 260, 81, 18));
        label_14 = new QLabel(tabMoyRec);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(910, 580, 81, 20));
        scrollArea_8 = new QScrollArea(tabMoyRec);
        scrollArea_8->setObjectName(QStringLiteral("scrollArea_8"));
        scrollArea_8->setGeometry(QRect(420, 0, 320, 240));
        scrollArea_8->setWidgetResizable(true);
        scrollAreaWidgetContents_8 = new QWidget();
        scrollAreaWidgetContents_8->setObjectName(QStringLiteral("scrollAreaWidgetContents_8"));
        scrollAreaWidgetContents_8->setGeometry(QRect(0, 0, 318, 238));
        scrollArea_8->setWidget(scrollAreaWidgetContents_8);
        scrollArea_9 = new QScrollArea(tabMoyRec);
        scrollArea_9->setObjectName(QStringLiteral("scrollArea_9"));
        scrollArea_9->setGeometry(QRect(790, 0, 320, 240));
        scrollArea_9->setWidgetResizable(true);
        scrollAreaWidgetContents_9 = new QWidget();
        scrollAreaWidgetContents_9->setObjectName(QStringLiteral("scrollAreaWidgetContents_9"));
        scrollAreaWidgetContents_9->setGeometry(QRect(0, 0, 318, 238));
        scrollArea_9->setWidget(scrollAreaWidgetContents_9);
        scrollArea_10 = new QScrollArea(tabMoyRec);
        scrollArea_10->setObjectName(QStringLiteral("scrollArea_10"));
        scrollArea_10->setGeometry(QRect(420, 320, 320, 240));
        scrollArea_10->setWidgetResizable(true);
        scrollAreaWidgetContents_10 = new QWidget();
        scrollAreaWidgetContents_10->setObjectName(QStringLiteral("scrollAreaWidgetContents_10"));
        scrollAreaWidgetContents_10->setGeometry(QRect(0, 0, 318, 238));
        scrollArea_10->setWidget(scrollAreaWidgetContents_10);
        scrollArea_11 = new QScrollArea(tabMoyRec);
        scrollArea_11->setObjectName(QStringLiteral("scrollArea_11"));
        scrollArea_11->setGeometry(QRect(790, 320, 320, 240));
        scrollArea_11->setWidgetResizable(true);
        scrollAreaWidgetContents_11 = new QWidget();
        scrollAreaWidgetContents_11->setObjectName(QStringLiteral("scrollAreaWidgetContents_11"));
        scrollAreaWidgetContents_11->setGeometry(QRect(0, 0, 318, 238));
        scrollArea_11->setWidget(scrollAreaWidgetContents_11);
        label_progressRec = new QLabel(tabMoyRec);
        label_progressRec->setObjectName(QStringLiteral("label_progressRec"));
        label_progressRec->setGeometry(QRect(15, 190, 311, 20));
        label_progressRec->setAlignment(Qt::AlignCenter);
        layoutWidget_6 = new QWidget(tabMoyRec);
        layoutWidget_6->setObjectName(QStringLiteral("layoutWidget_6"));
        layoutWidget_6->setGeometry(QRect(100, 330, 142, 86));
        verticalLayout_4 = new QVBoxLayout(layoutWidget_6);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        shadowToggleRec = new QPushButton(layoutWidget_6);
        shadowToggleRec->setObjectName(QStringLiteral("shadowToggleRec"));
        shadowToggleRec->setFocusPolicy(Qt::NoFocus);
        shadowToggleRec->setStyleSheet(QLatin1String("border-style: solid;\n"
"border-width: 5px;\n"
"border-radius: 15px;"));
        shadowToggleRec->setIcon(icon10);
        shadowToggleRec->setIconSize(QSize(50, 50));
        shadowToggleRec->setCheckable(false);
        shadowToggleRec->setFlat(true);

        verticalLayout_4->addWidget(shadowToggleRec);

        label_21 = new QLabel(layoutWidget_6);
        label_21->setObjectName(QStringLiteral("label_21"));

        verticalLayout_4->addWidget(label_21);

        RecControl = new QSlider(tabMoyRec);
        RecControl->setObjectName(QStringLiteral("RecControl"));
        RecControl->setGeometry(QRect(10, 230, 321, 20));
        RecControl->setOrientation(Qt::Horizontal);
        rec_results_table = new QTableWidget(tabMoyRec);
        rec_results_table->setObjectName(QStringLiteral("rec_results_table"));
        rec_results_table->setGeometry(QRect(50, 430, 250, 192));
        tabWidget->addTab(tabMoyRec, QString());
        recChooser->raise();
        gridLayoutWidget_2->raise();
        layoutWidget_2->raise();
        label_11->raise();
        label_12->raise();
        label_13->raise();
        label_14->raise();
        scrollArea_8->raise();
        scrollArea_9->raise();
        scrollArea_10->raise();
        scrollArea_11->raise();
        rec_image_label_foreground->raise();
        rec_image_label_back->raise();
        rec_image_label_mask->raise();
        rec_image_label_original->raise();
        label_progressRec->raise();
        layoutWidget_6->raise();
        RecControl->raise();
        rec_results_table->raise();
        tabMoySD = new QWidget();
        tabMoySD->setObjectName(QStringLiteral("tabMoySD"));
        SDChooser = new QPushButton(tabMoySD);
        SDChooser->setObjectName(QStringLiteral("SDChooser"));
        SDChooser->setGeometry(QRect(100, 20, 141, 31));
        SDChooser->setIcon(icon1);
        SDChooser->setIconSize(QSize(26, 26));
        gridLayoutWidget_3 = new QWidget(tabMoySD);
        gridLayoutWidget_3->setObjectName(QStringLiteral("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(90, 60, 160, 95));
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

        progressBarSD = new QProgressBar(gridLayoutWidget_3);
        progressBarSD->setObjectName(QStringLiteral("progressBarSD"));
        progressBarSD->setAutoFillBackground(false);
        progressBarSD->setValue(0);

        gridLayout_3->addWidget(progressBarSD, 2, 0, 1, 1);

        SD_image_label_foreground = new QLabel(tabMoySD);
        SD_image_label_foreground->setObjectName(QStringLiteral("SD_image_label_foreground"));
        SD_image_label_foreground->setGeometry(QRect(535, 320, 320, 240));
        SD_image_label_foreground->setScaledContents(true);
        SD_image_label_original = new QLabel(tabMoySD);
        SD_image_label_original->setObjectName(QStringLiteral("SD_image_label_original"));
        SD_image_label_original->setGeometry(QRect(350, 0, 320, 240));
        SD_image_label_original->setScaledContents(true);
        SD_image_label_original->setOpenExternalLinks(false);
        SD_image_label_mask = new QLabel(tabMoySD);
        SD_image_label_mask->setObjectName(QStringLiteral("SD_image_label_mask"));
        SD_image_label_mask->setGeometry(QRect(720, 0, 320, 240));
        SD_image_label_mask->setScaledContents(true);
        label_4 = new QLabel(tabMoySD);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(460, 270, 101, 20));
        label_5 = new QLabel(tabMoySD);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(800, 270, 161, 20));
        label_6 = new QLabel(tabMoySD);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(660, 580, 81, 20));
        layoutWidget_3 = new QWidget(tabMoySD);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(10, 220, 321, 41));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        begin_SD = new QPushButton(layoutWidget_3);
        begin_SD->setObjectName(QStringLiteral("begin_SD"));
        begin_SD->setIcon(icon2);
        begin_SD->setIconSize(QSize(26, 26));

        horizontalLayout_4->addWidget(begin_SD);

        deccel_SD = new QPushButton(layoutWidget_3);
        deccel_SD->setObjectName(QStringLiteral("deccel_SD"));
        deccel_SD->setIcon(icon3);
        deccel_SD->setIconSize(QSize(26, 26));

        horizontalLayout_4->addWidget(deccel_SD);

        speedDown_SD = new QPushButton(layoutWidget_3);
        speedDown_SD->setObjectName(QStringLiteral("speedDown_SD"));
        speedDown_SD->setIcon(icon4);
        speedDown_SD->setIconSize(QSize(26, 26));

        horizontalLayout_4->addWidget(speedDown_SD);

        controlSD = new QPushButton(layoutWidget_3);
        controlSD->setObjectName(QStringLiteral("controlSD"));
        controlSD->setIcon(icon9);
        controlSD->setIconSize(QSize(26, 26));

        horizontalLayout_4->addWidget(controlSD);

        speedUp_SD = new QPushButton(layoutWidget_3);
        speedUp_SD->setObjectName(QStringLiteral("speedUp_SD"));
        speedUp_SD->setIcon(icon6);
        speedUp_SD->setIconSize(QSize(26, 26));

        horizontalLayout_4->addWidget(speedUp_SD);

        accel_SD = new QPushButton(layoutWidget_3);
        accel_SD->setObjectName(QStringLiteral("accel_SD"));
        accel_SD->setIcon(icon7);
        accel_SD->setIconSize(QSize(26, 26));

        horizontalLayout_4->addWidget(accel_SD);

        end_SD = new QPushButton(layoutWidget_3);
        end_SD->setObjectName(QStringLiteral("end_SD"));
        end_SD->setIcon(icon8);
        end_SD->setIconSize(QSize(26, 26));

        horizontalLayout_4->addWidget(end_SD);

        scrollArea_12 = new QScrollArea(tabMoySD);
        scrollArea_12->setObjectName(QStringLiteral("scrollArea_12"));
        scrollArea_12->setGeometry(QRect(720, 0, 320, 240));
        scrollArea_12->setWidgetResizable(true);
        scrollAreaWidgetContents_12 = new QWidget();
        scrollAreaWidgetContents_12->setObjectName(QStringLiteral("scrollAreaWidgetContents_12"));
        scrollAreaWidgetContents_12->setGeometry(QRect(0, 0, 318, 238));
        scrollArea_12->setWidget(scrollAreaWidgetContents_12);
        scrollArea_13 = new QScrollArea(tabMoySD);
        scrollArea_13->setObjectName(QStringLiteral("scrollArea_13"));
        scrollArea_13->setGeometry(QRect(350, 0, 320, 240));
        scrollArea_13->setWidgetResizable(true);
        scrollAreaWidgetContents_13 = new QWidget();
        scrollAreaWidgetContents_13->setObjectName(QStringLiteral("scrollAreaWidgetContents_13"));
        scrollAreaWidgetContents_13->setGeometry(QRect(0, 0, 318, 238));
        scrollArea_13->setWidget(scrollAreaWidgetContents_13);
        scrollArea_14 = new QScrollArea(tabMoySD);
        scrollArea_14->setObjectName(QStringLiteral("scrollArea_14"));
        scrollArea_14->setGeometry(QRect(535, 320, 320, 240));
        scrollArea_14->setWidgetResizable(true);
        scrollAreaWidgetContents_14 = new QWidget();
        scrollAreaWidgetContents_14->setObjectName(QStringLiteral("scrollAreaWidgetContents_14"));
        scrollAreaWidgetContents_14->setGeometry(QRect(0, 0, 318, 238));
        scrollArea_14->setWidget(scrollAreaWidgetContents_14);
        label_progressSD = new QLabel(tabMoySD);
        label_progressSD->setObjectName(QStringLiteral("label_progressSD"));
        label_progressSD->setGeometry(QRect(10, 170, 321, 20));
        label_progressSD->setAlignment(Qt::AlignCenter);
        layoutWidget_7 = new QWidget(tabMoySD);
        layoutWidget_7->setObjectName(QStringLiteral("layoutWidget_7"));
        layoutWidget_7->setGeometry(QRect(90, 280, 142, 86));
        verticalLayout_5 = new QVBoxLayout(layoutWidget_7);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        shadowToggleSD = new QPushButton(layoutWidget_7);
        shadowToggleSD->setObjectName(QStringLiteral("shadowToggleSD"));
        shadowToggleSD->setFocusPolicy(Qt::NoFocus);
        shadowToggleSD->setStyleSheet(QLatin1String("border-style: solid;\n"
"border-width: 5px;\n"
"border-radius: 15px;"));
        shadowToggleSD->setIcon(icon10);
        shadowToggleSD->setIconSize(QSize(50, 50));
        shadowToggleSD->setCheckable(false);
        shadowToggleSD->setFlat(true);

        verticalLayout_5->addWidget(shadowToggleSD);

        label_22 = new QLabel(layoutWidget_7);
        label_22->setObjectName(QStringLiteral("label_22"));

        verticalLayout_5->addWidget(label_22);

        SDControl = new QSlider(tabMoySD);
        SDControl->setObjectName(QStringLiteral("SDControl"));
        SDControl->setGeometry(QRect(10, 200, 321, 20));
        SDControl->setOrientation(Qt::Horizontal);
        SD_results_table = new QTableWidget(tabMoySD);
        SD_results_table->setObjectName(QStringLiteral("SD_results_table"));
        SD_results_table->setGeometry(QRect(40, 380, 250, 192));
        tabWidget->addTab(tabMoySD, QString());
        SDChooser->raise();
        gridLayoutWidget_3->raise();
        label_4->raise();
        label_5->raise();
        label_6->raise();
        layoutWidget_3->raise();
        scrollArea_12->raise();
        scrollArea_13->raise();
        scrollArea_14->raise();
        SD_image_label_original->raise();
        SD_image_label_foreground->raise();
        SD_image_label_mask->raise();
        label_progressSD->raise();
        layoutWidget_7->raise();
        SDControl->raise();
        SD_results_table->raise();
        tabSAP = new QWidget();
        tabSAP->setObjectName(QStringLiteral("tabSAP"));
        SAPChooser = new QPushButton(tabSAP);
        SAPChooser->setObjectName(QStringLiteral("SAPChooser"));
        SAPChooser->setGeometry(QRect(100, 40, 141, 31));
        SAPChooser->setIcon(icon1);
        SAPChooser->setIconSize(QSize(26, 26));
        gridLayoutWidget_4 = new QWidget(tabSAP);
        gridLayoutWidget_4->setObjectName(QStringLiteral("gridLayoutWidget_4"));
        gridLayoutWidget_4->setGeometry(QRect(90, 80, 160, 101));
        gridLayout_4 = new QGridLayout(gridLayoutWidget_4);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        backgroundProgressSAP = new QProgressBar(gridLayoutWidget_4);
        backgroundProgressSAP->setObjectName(QStringLiteral("backgroundProgressSAP"));
        backgroundProgressSAP->setValue(0);

        gridLayout_4->addWidget(backgroundProgressSAP, 3, 0, 1, 1);

        multipleChooser = new QSpinBox(gridLayoutWidget_4);
        multipleChooser->setObjectName(QStringLiteral("multipleChooser"));
        multipleChooser->setMinimum(1);
        multipleChooser->setMaximum(8);
        multipleChooser->setValue(1);

        gridLayout_4->addWidget(multipleChooser, 1, 0, 1, 1);

        labelSAPMultiple = new QLabel(gridLayoutWidget_4);
        labelSAPMultiple->setObjectName(QStringLiteral("labelSAPMultiple"));

        gridLayout_4->addWidget(labelSAPMultiple, 2, 0, 1, 1, Qt::AlignHCenter);

        SAP_image_label_foreground = new QLabel(tabSAP);
        SAP_image_label_foreground->setObjectName(QStringLiteral("SAP_image_label_foreground"));
        SAP_image_label_foreground->setGeometry(QRect(790, 320, 320, 240));
        SAP_image_label_foreground->setScaledContents(true);
        SAP_image_label_back = new QLabel(tabSAP);
        SAP_image_label_back->setObjectName(QStringLiteral("SAP_image_label_back"));
        SAP_image_label_back->setGeometry(QRect(790, 0, 320, 240));
        SAP_image_label_back->setScaledContents(true);
        SAP_image_label_mask = new QLabel(tabSAP);
        SAP_image_label_mask->setObjectName(QStringLiteral("SAP_image_label_mask"));
        SAP_image_label_mask->setGeometry(QRect(420, 320, 320, 240));
        SAP_image_label_mask->setScaledContents(true);
        SAP_image_label_original = new QLabel(tabSAP);
        SAP_image_label_original->setObjectName(QStringLiteral("SAP_image_label_original"));
        SAP_image_label_original->setGeometry(QRect(420, 0, 320, 240));
        SAP_image_label_original->setScaledContents(true);
        SAP_image_label_original->setOpenExternalLinks(false);
        layoutWidget_4 = new QWidget(tabSAP);
        layoutWidget_4->setObjectName(QStringLiteral("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(10, 320, 321, 34));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget_4);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        begin_SAP = new QPushButton(layoutWidget_4);
        begin_SAP->setObjectName(QStringLiteral("begin_SAP"));
        begin_SAP->setIcon(icon2);
        begin_SAP->setIconSize(QSize(26, 26));

        horizontalLayout_5->addWidget(begin_SAP);

        deccel_SAP = new QPushButton(layoutWidget_4);
        deccel_SAP->setObjectName(QStringLiteral("deccel_SAP"));
        deccel_SAP->setIcon(icon3);
        deccel_SAP->setIconSize(QSize(26, 26));

        horizontalLayout_5->addWidget(deccel_SAP);

        speedDown_SAP = new QPushButton(layoutWidget_4);
        speedDown_SAP->setObjectName(QStringLiteral("speedDown_SAP"));
        speedDown_SAP->setIcon(icon4);
        speedDown_SAP->setIconSize(QSize(26, 26));

        horizontalLayout_5->addWidget(speedDown_SAP);

        controlSAP = new QPushButton(layoutWidget_4);
        controlSAP->setObjectName(QStringLiteral("controlSAP"));
        controlSAP->setIcon(icon9);
        controlSAP->setIconSize(QSize(26, 26));

        horizontalLayout_5->addWidget(controlSAP);

        speedUp_SAP = new QPushButton(layoutWidget_4);
        speedUp_SAP->setObjectName(QStringLiteral("speedUp_SAP"));
        speedUp_SAP->setIcon(icon6);
        speedUp_SAP->setIconSize(QSize(26, 26));

        horizontalLayout_5->addWidget(speedUp_SAP);

        accel_SAP = new QPushButton(layoutWidget_4);
        accel_SAP->setObjectName(QStringLiteral("accel_SAP"));
        accel_SAP->setIcon(icon7);
        accel_SAP->setIconSize(QSize(26, 26));

        horizontalLayout_5->addWidget(accel_SAP);

        end_SAP = new QPushButton(layoutWidget_4);
        end_SAP->setObjectName(QStringLiteral("end_SAP"));
        end_SAP->setIcon(icon8);
        end_SAP->setIconSize(QSize(26, 26));

        horizontalLayout_5->addWidget(end_SAP);

        label_15 = new QLabel(tabSAP);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(525, 260, 111, 20));
        label_16 = new QLabel(tabSAP);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(910, 580, 81, 20));
        label_17 = new QLabel(tabSAP);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(910, 260, 81, 18));
        label_18 = new QLabel(tabSAP);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(500, 580, 161, 20));
        scrollArea_15 = new QScrollArea(tabSAP);
        scrollArea_15->setObjectName(QStringLiteral("scrollArea_15"));
        scrollArea_15->setGeometry(QRect(420, 0, 320, 240));
        scrollArea_15->setWidgetResizable(true);
        scrollAreaWidgetContents_15 = new QWidget();
        scrollAreaWidgetContents_15->setObjectName(QStringLiteral("scrollAreaWidgetContents_15"));
        scrollAreaWidgetContents_15->setGeometry(QRect(0, 0, 318, 238));
        scrollArea_15->setWidget(scrollAreaWidgetContents_15);
        scrollArea_16 = new QScrollArea(tabSAP);
        scrollArea_16->setObjectName(QStringLiteral("scrollArea_16"));
        scrollArea_16->setGeometry(QRect(790, 0, 320, 240));
        scrollArea_16->setWidgetResizable(true);
        scrollAreaWidgetContents_16 = new QWidget();
        scrollAreaWidgetContents_16->setObjectName(QStringLiteral("scrollAreaWidgetContents_16"));
        scrollAreaWidgetContents_16->setGeometry(QRect(0, 0, 318, 238));
        scrollArea_16->setWidget(scrollAreaWidgetContents_16);
        scrollArea_17 = new QScrollArea(tabSAP);
        scrollArea_17->setObjectName(QStringLiteral("scrollArea_17"));
        scrollArea_17->setGeometry(QRect(420, 320, 320, 240));
        scrollArea_17->setWidgetResizable(true);
        scrollAreaWidgetContents_17 = new QWidget();
        scrollAreaWidgetContents_17->setObjectName(QStringLiteral("scrollAreaWidgetContents_17"));
        scrollAreaWidgetContents_17->setGeometry(QRect(0, 0, 318, 238));
        scrollArea_17->setWidget(scrollAreaWidgetContents_17);
        scrollArea_18 = new QScrollArea(tabSAP);
        scrollArea_18->setObjectName(QStringLiteral("scrollArea_18"));
        scrollArea_18->setGeometry(QRect(790, 320, 320, 240));
        scrollArea_18->setWidgetResizable(true);
        scrollAreaWidgetContents_18 = new QWidget();
        scrollAreaWidgetContents_18->setObjectName(QStringLiteral("scrollAreaWidgetContents_18"));
        scrollAreaWidgetContents_18->setGeometry(QRect(0, 0, 318, 238));
        scrollArea_18->setWidget(scrollAreaWidgetContents_18);
        label_progressSAP = new QLabel(tabSAP);
        label_progressSAP->setObjectName(QStringLiteral("label_progressSAP"));
        label_progressSAP->setGeometry(QRect(15, 270, 311, 20));
        label_progressSAP->setAlignment(Qt::AlignCenter);
        layoutWidget_8 = new QWidget(tabSAP);
        layoutWidget_8->setObjectName(QStringLiteral("layoutWidget_8"));
        layoutWidget_8->setGeometry(QRect(90, 360, 142, 86));
        verticalLayout_6 = new QVBoxLayout(layoutWidget_8);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        shadowToggleSAP = new QPushButton(layoutWidget_8);
        shadowToggleSAP->setObjectName(QStringLiteral("shadowToggleSAP"));
        shadowToggleSAP->setFocusPolicy(Qt::NoFocus);
        shadowToggleSAP->setStyleSheet(QLatin1String("border-style: solid;\n"
"border-width: 5px;\n"
"border-radius: 15px;"));
        shadowToggleSAP->setIcon(icon10);
        shadowToggleSAP->setIconSize(QSize(50, 50));
        shadowToggleSAP->setCheckable(false);
        shadowToggleSAP->setFlat(true);

        verticalLayout_6->addWidget(shadowToggleSAP);

        label_23 = new QLabel(layoutWidget_8);
        label_23->setObjectName(QStringLiteral("label_23"));

        verticalLayout_6->addWidget(label_23);

        SAPControl = new QSlider(tabSAP);
        SAPControl->setObjectName(QStringLiteral("SAPControl"));
        SAPControl->setGeometry(QRect(10, 300, 321, 20));
        SAPControl->setOrientation(Qt::Horizontal);
        SAP_results_table = new QTableWidget(tabSAP);
        SAP_results_table->setObjectName(QStringLiteral("SAP_results_table"));
        SAP_results_table->setGeometry(QRect(40, 450, 250, 192));
        alphaChooserSAP = new QSlider(tabSAP);
        alphaChooserSAP->setObjectName(QStringLiteral("alphaChooserSAP"));
        alphaChooserSAP->setEnabled(false);
        alphaChooserSAP->setGeometry(QRect(260, 400, 158, 15));
        alphaChooserSAP->setMaximum(1000);
        alphaChooserSAP->setOrientation(Qt::Horizontal);
        labelSAPAlpha = new QLabel(tabSAP);
        labelSAPAlpha->setObjectName(QStringLiteral("labelSAPAlpha"));
        labelSAPAlpha->setEnabled(false);
        labelSAPAlpha->setGeometry(QRect(330, 420, 9, 33));
        labelSAPAlphaValue = new QLabel(tabSAP);
        labelSAPAlphaValue->setObjectName(QStringLiteral("labelSAPAlphaValue"));
        labelSAPAlphaValue->setEnabled(false);
        labelSAPAlphaValue->setGeometry(QRect(350, 420, 21, 53));
        tabWidget->addTab(tabSAP, QString());
        SAPChooser->raise();
        gridLayoutWidget_4->raise();
        layoutWidget_4->raise();
        label_15->raise();
        label_16->raise();
        label_17->raise();
        label_18->raise();
        scrollArea_15->raise();
        scrollArea_16->raise();
        scrollArea_17->raise();
        scrollArea_18->raise();
        SAP_image_label_original->raise();
        SAP_image_label_mask->raise();
        SAP_image_label_back->raise();
        SAP_image_label_foreground->raise();
        label_progressSAP->raise();
        layoutWidget_8->raise();
        SAPControl->raise();
        SAP_results_table->raise();
        alphaChooserSAP->raise();
        labelSAPAlpha->raise();
        labelSAPAlphaValue->raise();

        gridLayout_6->addWidget(tabWidget, 3, 0, 1, 1);


        retranslateUi(Chooser);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(Chooser);
    } // setupUi

    void retranslateUi(QWidget *Chooser)
    {
        Chooser->setWindowTitle(QApplication::translate("Chooser", "Methodes de detection", 0));
        exit->setText(QApplication::translate("Chooser", "Quitter", 0));
        labelGradAlpha->setText(QApplication::translate("Chooser", "alpha", 0));
        labelGradAlphaValue->setText(QString());
        gradiantChooser->setText(QApplication::translate("Chooser", " Choisir la video", 0));
        grad_image_label_original->setText(QString());
        grad_image_label_mask->setText(QString());
        grad_image_label_foreground->setText(QString());
        label->setText(QApplication::translate("Chooser", "Image originale", 0));
        label_2->setText(QApplication::translate("Chooser", "Masque de mouvement", 0));
        label_3->setText(QApplication::translate("Chooser", "Avant plan", 0));
        begin->setText(QString());
        deccel->setText(QString());
        speedDown->setText(QString());
        control->setText(QString());
        speedUp->setText(QString());
        accel->setText(QString());
        end->setText(QString());
        label_progressGrad->setText(QString());
        counterGrad->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tabGradiantMorph), QApplication::translate("Chooser", "Gradiant mophologique oublieux", 0));
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
        label_10->setText(QApplication::translate("Chooser", "Arri\303\250re plan", 0));
        label_8->setText(QApplication::translate("Chooser", "Masque de mouvement", 0));
        label_9->setText(QApplication::translate("Chooser", "Avant plan", 0));
        label_progressArith->setText(QString());
        arithChooser->setText(QApplication::translate("Chooser", " Choisir la video", 0));
        shadowToggleArith->setText(QString());
        label_20->setText(QApplication::translate("Chooser", "Elimination d'ombres", 0));
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
        label_11->setText(QApplication::translate("Chooser", "Masque de mouvement", 0));
        label_12->setText(QApplication::translate("Chooser", "Image originale", 0));
        label_13->setText(QApplication::translate("Chooser", "Arri\303\250re plan", 0));
        label_14->setText(QApplication::translate("Chooser", "Avant plan", 0));
        label_progressRec->setText(QString());
        shadowToggleRec->setText(QString());
        label_21->setText(QApplication::translate("Chooser", "Elimination d'ombres", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabMoyRec), QApplication::translate("Chooser", "Moyenne r\303\251cursive", 0));
        SDChooser->setText(QApplication::translate("Chooser", " Choisir la video", 0));
#ifndef QT_NO_TOOLTIP
        labelSDN->setToolTip(QApplication::translate("Chooser", "Param\303\250tre de", 0));
#endif // QT_NO_TOOLTIP
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
        label_progressSD->setText(QString());
        shadowToggleSD->setText(QString());
        label_22->setText(QApplication::translate("Chooser", "Elimination d'ombres", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabMoySD), QApplication::translate("Chooser", "Moyenne \316\243-\342\210\206", 0));
        SAPChooser->setText(QApplication::translate("Chooser", " Choisir la video", 0));
#ifndef QT_NO_TOOLTIP
        labelSAPMultiple->setToolTip(QApplication::translate("Chooser", "Parametre pour le seuillage", 0));
#endif // QT_NO_TOOLTIP
        labelSAPMultiple->setText(QApplication::translate("Chooser", "Multiple", 0));
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
        label_15->setText(QApplication::translate("Chooser", "Image originale", 0));
        label_16->setText(QApplication::translate("Chooser", "Avant plan", 0));
        label_17->setText(QApplication::translate("Chooser", "Arri\303\250re plan", 0));
        label_18->setText(QApplication::translate("Chooser", "Masque de mouvement", 0));
        label_progressSAP->setText(QString());
        shadowToggleSAP->setText(QString());
        label_23->setText(QApplication::translate("Chooser", "Elimination d'ombres", 0));
#ifndef QT_NO_TOOLTIP
        labelSAPAlpha->setToolTip(QApplication::translate("Chooser", "Parametre pour la mise a jour automatique du fond", 0));
#endif // QT_NO_TOOLTIP
        labelSAPAlpha->setText(QApplication::translate("Chooser", "\316\267", 0));
        labelSAPAlphaValue->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tabSAP), QApplication::translate("Chooser", "SAP", 0));
    } // retranslateUi

};

namespace Ui {
    class Chooser: public Ui_Chooser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOOSER_H
