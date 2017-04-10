/********************************************************************************
** Form generated from reading UI file 'selector.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTOR_H
#define UI_SELECTOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Selector
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *SelectGroup;
    QRadioButton *gradiantOublieux;
    QRadioButton *moyenneRecurssive;
    QRadioButton *moyenneArith;
    QRadioButton *moyenneSD;
    QRadioButton *SAP;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_5;
    QSlider *horizontalSlider;
    QLCDNumber *alphaValue;
    QLabel *alpha;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_2;
    QSpinBox *multipleChooser;
    QLabel *multiple;
    QPushButton *quitSelector;

    void setupUi(QWidget *Selector)
    {
        if (Selector->objectName().isEmpty())
            Selector->setObjectName(QStringLiteral("Selector"));
        Selector->setEnabled(true);
        Selector->resize(659, 380);
        Selector->setCursor(QCursor(Qt::PointingHandCursor));
        verticalLayout = new QVBoxLayout(Selector);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        SelectGroup = new QGroupBox(Selector);
        SelectGroup->setObjectName(QStringLiteral("SelectGroup"));
        SelectGroup->setMinimumSize(QSize(442, 265));
        SelectGroup->setFlat(true);
        gradiantOublieux = new QRadioButton(SelectGroup);
        gradiantOublieux->setObjectName(QStringLiteral("gradiantOublieux"));
        gradiantOublieux->setGeometry(QRect(10, 30, 442, 24));
        moyenneRecurssive = new QRadioButton(SelectGroup);
        moyenneRecurssive->setObjectName(QStringLiteral("moyenneRecurssive"));
        moyenneRecurssive->setGeometry(QRect(10, 60, 442, 24));
        moyenneArith = new QRadioButton(SelectGroup);
        moyenneArith->setObjectName(QStringLiteral("moyenneArith"));
        moyenneArith->setGeometry(QRect(10, 90, 442, 24));
        moyenneSD = new QRadioButton(SelectGroup);
        moyenneSD->setObjectName(QStringLiteral("moyenneSD"));
        moyenneSD->setGeometry(QRect(10, 120, 442, 24));
        SAP = new QRadioButton(SelectGroup);
        SAP->setObjectName(QStringLiteral("SAP"));
        SAP->setGeometry(QRect(10, 150, 442, 24));
        verticalLayoutWidget = new QWidget(SelectGroup);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(50, 190, 181, 71));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalSlider = new QSlider(verticalLayoutWidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        verticalLayout_5->addWidget(horizontalSlider);

        alphaValue = new QLCDNumber(verticalLayoutWidget);
        alphaValue->setObjectName(QStringLiteral("alphaValue"));

        verticalLayout_5->addWidget(alphaValue);

        alpha = new QLabel(verticalLayoutWidget);
        alpha->setObjectName(QStringLiteral("alpha"));

        verticalLayout_5->addWidget(alpha, 0, Qt::AlignHCenter);

        gridLayoutWidget = new QWidget(SelectGroup);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(420, 190, 181, 71));
        gridLayout_2 = new QGridLayout(gridLayoutWidget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        multipleChooser = new QSpinBox(gridLayoutWidget);
        multipleChooser->setObjectName(QStringLiteral("multipleChooser"));
        multipleChooser->setMinimum(1);
        multipleChooser->setMaximum(10);
        multipleChooser->setSingleStep(1);

        gridLayout_2->addWidget(multipleChooser, 0, 0, 1, 1);

        multiple = new QLabel(gridLayoutWidget);
        multiple->setObjectName(QStringLiteral("multiple"));

        gridLayout_2->addWidget(multiple, 1, 0, 1, 1, Qt::AlignHCenter);


        verticalLayout->addWidget(SelectGroup);

        quitSelector = new QPushButton(Selector);
        quitSelector->setObjectName(QStringLiteral("quitSelector"));

        verticalLayout->addWidget(quitSelector);


        retranslateUi(Selector);

        QMetaObject::connectSlotsByName(Selector);
    } // setupUi

    void retranslateUi(QWidget *Selector)
    {
        Selector->setWindowTitle(QApplication::translate("Selector", "Selector", 0));
        SelectGroup->setTitle(QApplication::translate("Selector", "Selection", 0));
        gradiantOublieux->setText(QApplication::translate("Selector", "gradiant morophologique oublieux", 0));
        moyenneRecurssive->setText(QApplication::translate("Selector", "Moyenne r\303\251curssive", 0));
        moyenneArith->setText(QApplication::translate("Selector", "Moyenne arithm\303\251tique", 0));
        moyenneSD->setText(QApplication::translate("Selector", "Moyenne Sigma-Delta", 0));
        SAP->setText(QApplication::translate("Selector", "SAP", 0));
        alpha->setText(QApplication::translate("Selector", "\316\261", 0));
        multiple->setText(QApplication::translate("Selector", "Multiple", 0));
        quitSelector->setText(QApplication::translate("Selector", "Quit", 0));
    } // retranslateUi

};

namespace Ui {
    class Selector: public Ui_Selector {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTOR_H
