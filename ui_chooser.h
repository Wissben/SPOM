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
    QPushButton *control;
    QLabel *grad_image_label_mask;
    QLabel *grad_image_label_foreground;
    QWidget *tabMoyArith;
    QPushButton *arithChooser;
    QProgressBar *backgroundProgressArith;
    QPushButton *controlArith;
    QLabel *arith_image_label_original;
    QLabel *arith_image_label_foreground;
    QLabel *arith_image_label_mask;
    QLabel *arith_image_label_back;
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
    QPushButton *controlRec;
    QWidget *tabMoySD;
    QPushButton *SDChooser;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QSpinBox *NChooser;
    QLabel *labelSDN;
    QLabel *SD_image_label_foreground;
    QLabel *SD_image_label_original;
    QLabel *SD_image_label_mask;
    QPushButton *controlSD;
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
    QPushButton *controlSAP;

    void setupUi(QWidget *Chooser)
    {
        if (Chooser->objectName().isEmpty())
            Chooser->setObjectName(QStringLiteral("Chooser"));
        Chooser->resize(1300, 1000);
        gridLayout_6 = new QGridLayout(Chooser);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        tabWidget = new QTabWidget(Chooser);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabGradiantMorph = new QWidget();
        tabGradiantMorph->setObjectName(QStringLiteral("tabGradiantMorph"));
        tabGradiantMorph->setMouseTracking(false);
        gradiantChooser = new QPushButton(tabGradiantMorph);
        gradiantChooser->setObjectName(QStringLiteral("gradiantChooser"));
        gradiantChooser->setGeometry(QRect(40, 30, 131, 26));
        gridLayoutWidget = new QWidget(tabGradiantMorph);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(20, 90, 160, 65));
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
        grad_image_label_original->setGeometry(QRect(350, 30, 320, 240));
        grad_image_label_original->setScaledContents(true);
        grad_image_label_original->setOpenExternalLinks(false);
        control = new QPushButton(tabGradiantMorph);
        control->setObjectName(QStringLiteral("control"));
        control->setGeometry(QRect(50, 230, 86, 26));
        QIcon icon;
        icon.addFile(QStringLiteral("../../../AlarmRed.png"), QSize(), QIcon::Normal, QIcon::Off);
        control->setIcon(icon);
        grad_image_label_mask = new QLabel(tabGradiantMorph);
        grad_image_label_mask->setObjectName(QStringLiteral("grad_image_label_mask"));
        grad_image_label_mask->setGeometry(QRect(720, 30, 320, 240));
        grad_image_label_foreground = new QLabel(tabGradiantMorph);
        grad_image_label_foreground->setObjectName(QStringLiteral("grad_image_label_foreground"));
        grad_image_label_foreground->setGeometry(QRect(535, 300, 320, 240));
        tabWidget->addTab(tabGradiantMorph, QString());
        tabMoyArith = new QWidget();
        tabMoyArith->setObjectName(QStringLiteral("tabMoyArith"));
        arithChooser = new QPushButton(tabMoyArith);
        arithChooser->setObjectName(QStringLiteral("arithChooser"));
        arithChooser->setGeometry(QRect(30, 30, 141, 26));
        backgroundProgressArith = new QProgressBar(tabMoyArith);
        backgroundProgressArith->setObjectName(QStringLiteral("backgroundProgressArith"));
        backgroundProgressArith->setGeometry(QRect(27, 130, 151, 23));
        backgroundProgressArith->setValue(0);
        controlArith = new QPushButton(tabMoyArith);
        controlArith->setObjectName(QStringLiteral("controlArith"));
        controlArith->setGeometry(QRect(60, 220, 86, 26));
        arith_image_label_original = new QLabel(tabMoyArith);
        arith_image_label_original->setObjectName(QStringLiteral("arith_image_label_original"));
        arith_image_label_original->setGeometry(QRect(380, 120, 320, 240));
        arith_image_label_original->setScaledContents(true);
        arith_image_label_original->setOpenExternalLinks(false);
        arith_image_label_foreground = new QLabel(tabMoyArith);
        arith_image_label_foreground->setObjectName(QStringLiteral("arith_image_label_foreground"));
        arith_image_label_foreground->setGeometry(QRect(380, 390, 320, 240));
        arith_image_label_mask = new QLabel(tabMoyArith);
        arith_image_label_mask->setObjectName(QStringLiteral("arith_image_label_mask"));
        arith_image_label_mask->setGeometry(QRect(750, 120, 320, 240));
        arith_image_label_back = new QLabel(tabMoyArith);
        arith_image_label_back->setObjectName(QStringLiteral("arith_image_label_back"));
        arith_image_label_back->setGeometry(QRect(750, 390, 320, 240));
        tabWidget->addTab(tabMoyArith, QString());
        tabMoyRec = new QWidget();
        tabMoyRec->setObjectName(QStringLiteral("tabMoyRec"));
        recChooser = new QPushButton(tabMoyRec);
        recChooser->setObjectName(QStringLiteral("recChooser"));
        recChooser->setGeometry(QRect(50, 60, 111, 26));
        gridLayoutWidget_2 = new QWidget(tabMoyRec);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(30, 110, 160, 97));
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
        controlRec = new QPushButton(tabMoyRec);
        controlRec->setObjectName(QStringLiteral("controlRec"));
        controlRec->setGeometry(QRect(70, 270, 86, 26));
        tabWidget->addTab(tabMoyRec, QString());
        tabMoySD = new QWidget();
        tabMoySD->setObjectName(QStringLiteral("tabMoySD"));
        SDChooser = new QPushButton(tabMoySD);
        SDChooser->setObjectName(QStringLiteral("SDChooser"));
        SDChooser->setGeometry(QRect(50, 70, 111, 26));
        gridLayoutWidget_3 = new QWidget(tabMoySD);
        gridLayoutWidget_3->setObjectName(QStringLiteral("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(20, 120, 160, 53));
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
        SD_image_label_foreground->setGeometry(QRect(585, 380, 320, 240));
        SD_image_label_original = new QLabel(tabMoySD);
        SD_image_label_original->setObjectName(QStringLiteral("SD_image_label_original"));
        SD_image_label_original->setGeometry(QRect(400, 110, 320, 240));
        SD_image_label_original->setScaledContents(true);
        SD_image_label_original->setOpenExternalLinks(false);
        SD_image_label_mask = new QLabel(tabMoySD);
        SD_image_label_mask->setObjectName(QStringLiteral("SD_image_label_mask"));
        SD_image_label_mask->setGeometry(QRect(770, 110, 320, 240));
        controlSD = new QPushButton(tabMoySD);
        controlSD->setObjectName(QStringLiteral("controlSD"));
        controlSD->setGeometry(QRect(60, 240, 86, 26));
        tabWidget->addTab(tabMoySD, QString());
        tabSAP = new QWidget();
        tabSAP->setObjectName(QStringLiteral("tabSAP"));
        SAPChooser = new QPushButton(tabSAP);
        SAPChooser->setObjectName(QStringLiteral("SAPChooser"));
        SAPChooser->setGeometry(QRect(40, 50, 111, 26));
        gridLayoutWidget_4 = new QWidget(tabSAP);
        gridLayoutWidget_4->setObjectName(QStringLiteral("gridLayoutWidget_4"));
        gridLayoutWidget_4->setGeometry(QRect(20, 100, 160, 154));
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
        SAP_image_label_foreground->setGeometry(QRect(440, 430, 320, 240));
        SAP_image_label_back = new QLabel(tabSAP);
        SAP_image_label_back->setObjectName(QStringLiteral("SAP_image_label_back"));
        SAP_image_label_back->setGeometry(QRect(810, 430, 320, 240));
        SAP_image_label_mask = new QLabel(tabSAP);
        SAP_image_label_mask->setObjectName(QStringLiteral("SAP_image_label_mask"));
        SAP_image_label_mask->setGeometry(QRect(810, 160, 320, 240));
        SAP_image_label_original = new QLabel(tabSAP);
        SAP_image_label_original->setObjectName(QStringLiteral("SAP_image_label_original"));
        SAP_image_label_original->setGeometry(QRect(440, 160, 320, 240));
        SAP_image_label_original->setScaledContents(true);
        SAP_image_label_original->setOpenExternalLinks(false);
        controlSAP = new QPushButton(tabSAP);
        controlSAP->setObjectName(QStringLiteral("controlSAP"));
        controlSAP->setGeometry(QRect(60, 320, 86, 26));
        tabWidget->addTab(tabSAP, QString());

        gridLayout_6->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(Chooser);

        tabWidget->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(Chooser);
    } // setupUi

    void retranslateUi(QWidget *Chooser)
    {
        Chooser->setWindowTitle(QApplication::translate("Chooser", "Form", 0));
        gradiantChooser->setText(QApplication::translate("Chooser", "Choisir la video", 0));
        labelGradAlpha->setText(QApplication::translate("Chooser", "alpha", 0));
        labelGradAlphaValue->setText(QString());
        grad_image_label_original->setText(QString());
        control->setText(QString());
        grad_image_label_mask->setText(QString());
        grad_image_label_foreground->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tabGradiantMorph), QApplication::translate("Chooser", "Gradiant mophologique oublieux", 0));
        arithChooser->setText(QApplication::translate("Chooser", "Choisir la video", 0));
        controlArith->setText(QApplication::translate("Chooser", "Control", 0));
        arith_image_label_original->setText(QString());
        arith_image_label_foreground->setText(QString());
        arith_image_label_mask->setText(QString());
        arith_image_label_back->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tabMoyArith), QApplication::translate("Chooser", "Moyenne arithm\303\251tique", 0));
        recChooser->setText(QApplication::translate("Chooser", "Choisir la video", 0));
        labelRecAlpha->setText(QApplication::translate("Chooser", "alpha", 0));
        labelRecAlphaValue->setText(QString());
        rec_image_label_mask->setText(QString());
        rec_image_label_back->setText(QString());
        rec_image_label_foreground->setText(QString());
        rec_image_label_original->setText(QString());
        controlRec->setText(QApplication::translate("Chooser", "control", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabMoyRec), QApplication::translate("Chooser", "Moyenne r\303\251cursive", 0));
        SDChooser->setText(QApplication::translate("Chooser", "Choisir la video", 0));
        labelSDN->setText(QApplication::translate("Chooser", "N", 0));
        SD_image_label_foreground->setText(QString());
        SD_image_label_original->setText(QString());
        SD_image_label_mask->setText(QString());
        controlSD->setText(QApplication::translate("Chooser", "control", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabMoySD), QApplication::translate("Chooser", "Moyenne \316\243-\342\210\206", 0));
        SAPChooser->setText(QApplication::translate("Chooser", "Choisir la video", 0));
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
        controlSAP->setText(QApplication::translate("Chooser", "Control", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabSAP), QApplication::translate("Chooser", "SAP", 0));
    } // retranslateUi

};

namespace Ui {
    class Chooser: public Ui_Chooser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOOSER_H
