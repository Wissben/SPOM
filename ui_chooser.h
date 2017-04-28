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
    QLabel *image_label;
    QWidget *tabMoyArith;
    QPushButton *arithChooser;
    QWidget *tabMoyRec;
    QPushButton *recChooser;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QLabel *labelRecAlpha;
    QLabel *labelRecAlphaValue;
    QSlider *alphaChooserRec;
    QWidget *tabMoySD;
    QPushButton *SDChooser;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_3;
    QSpinBox *NChooser;
    QLabel *labelSDN;
    QWidget *tabSAP;
    QPushButton *SAPChooser;
    QWidget *gridLayoutWidget_4;
    QGridLayout *gridLayout_4;
    QSpinBox *multipleChooser;
    QSlider *alphaChooserSAP;
    QLabel *labelSAPMultiple;
    QLabel *labelSAPAlpha;
    QLabel *labelSAPAlphaValue;

    void setupUi(QWidget *Chooser)
    {
        if (Chooser->objectName().isEmpty())
            Chooser->setObjectName(QStringLiteral("Chooser"));
        Chooser->resize(713, 401);
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
        alphaChooserGrad->setMaximum(999);
        alphaChooserGrad->setValue(400);
        alphaChooserGrad->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(alphaChooserGrad, 1, 0, 1, 1);

        labelGradAlpha = new QLabel(gridLayoutWidget);
        labelGradAlpha->setObjectName(QStringLiteral("labelGradAlpha"));

        gridLayout->addWidget(labelGradAlpha, 3, 0, 1, 1, Qt::AlignHCenter);

        labelGradAlphaValue = new QLabel(gridLayoutWidget);
        labelGradAlphaValue->setObjectName(QStringLiteral("labelGradAlphaValue"));

        gridLayout->addWidget(labelGradAlphaValue, 0, 0, 1, 1, Qt::AlignHCenter);

        image_label = new QLabel(tabGradiantMorph);
        image_label->setObjectName(QStringLiteral("image_label"));
        image_label->setGeometry(QRect(360, 40, 291, 251));
        tabWidget->addTab(tabGradiantMorph, QString());
        tabMoyArith = new QWidget();
        tabMoyArith->setObjectName(QStringLiteral("tabMoyArith"));
        arithChooser = new QPushButton(tabMoyArith);
        arithChooser->setObjectName(QStringLiteral("arithChooser"));
        arithChooser->setGeometry(QRect(30, 30, 141, 26));
        tabWidget->addTab(tabMoyArith, QString());
        tabMoyRec = new QWidget();
        tabMoyRec->setObjectName(QStringLiteral("tabMoyRec"));
        recChooser = new QPushButton(tabMoyRec);
        recChooser->setObjectName(QStringLiteral("recChooser"));
        recChooser->setGeometry(QRect(50, 60, 111, 26));
        gridLayoutWidget_2 = new QWidget(tabMoyRec);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(30, 110, 160, 61));
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
        alphaChooserRec->setMaximum(999);
        alphaChooserRec->setValue(5);
        alphaChooserRec->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(alphaChooserRec, 1, 0, 1, 1);

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

        tabWidget->addTab(tabMoySD, QString());
        tabSAP = new QWidget();
        tabSAP->setObjectName(QStringLiteral("tabSAP"));
        SAPChooser = new QPushButton(tabSAP);
        SAPChooser->setObjectName(QStringLiteral("SAPChooser"));
        SAPChooser->setGeometry(QRect(40, 50, 86, 26));
        gridLayoutWidget_4 = new QWidget(tabSAP);
        gridLayoutWidget_4->setObjectName(QStringLiteral("gridLayoutWidget_4"));
        gridLayoutWidget_4->setGeometry(QRect(20, 100, 160, 122));
        gridLayout_4 = new QGridLayout(gridLayoutWidget_4);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        multipleChooser = new QSpinBox(gridLayoutWidget_4);
        multipleChooser->setObjectName(QStringLiteral("multipleChooser"));

        gridLayout_4->addWidget(multipleChooser, 4, 0, 1, 1);

        alphaChooserSAP = new QSlider(gridLayoutWidget_4);
        alphaChooserSAP->setObjectName(QStringLiteral("alphaChooserSAP"));
        alphaChooserSAP->setMaximum(9);
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

        tabWidget->addTab(tabSAP, QString());

        gridLayout_6->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(Chooser);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(Chooser);
    } // setupUi

    void retranslateUi(QWidget *Chooser)
    {
        Chooser->setWindowTitle(QApplication::translate("Chooser", "Form", 0));
        gradiantChooser->setText(QApplication::translate("Chooser", "Choisir la video", 0));
        labelGradAlpha->setText(QApplication::translate("Chooser", "alpha", 0));
        labelGradAlphaValue->setText(QString());
        image_label->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tabGradiantMorph), QApplication::translate("Chooser", "Gradiant mophologique oublieux", 0));
        arithChooser->setText(QApplication::translate("Chooser", "Choisir la video", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabMoyArith), QApplication::translate("Chooser", "Moyenne arithm\303\251tique", 0));
        recChooser->setText(QApplication::translate("Chooser", "Choisir la video", 0));
        labelRecAlpha->setText(QApplication::translate("Chooser", "alpha", 0));
        labelRecAlphaValue->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tabMoyRec), QApplication::translate("Chooser", "Moyenne r\303\251cursive", 0));
        SDChooser->setText(QApplication::translate("Chooser", "Choisir la video", 0));
        labelSDN->setText(QApplication::translate("Chooser", "N", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabMoySD), QApplication::translate("Chooser", "Moyenne \316\243-\342\210\206", 0));
        SAPChooser->setText(QApplication::translate("Chooser", "PushButton", 0));
#ifndef QT_NO_TOOLTIP
        labelSAPMultiple->setToolTip(QApplication::translate("Chooser", "Parametre pour le seuillage", 0));
#endif // QT_NO_TOOLTIP
        labelSAPMultiple->setText(QApplication::translate("Chooser", "Multiple", 0));
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
