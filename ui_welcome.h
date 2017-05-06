/********************************************************************************
** Form generated from reading UI file 'welcome.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WELCOME_H
#define UI_WELCOME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Welcome
{
public:
    QPushButton *pushButton;
    QPushButton *about;
    QPushButton *pushButton_3;

    void setupUi(QWidget *Welcome)
    {
        if (Welcome->objectName().isEmpty())
            Welcome->setObjectName(QStringLiteral("Welcome"));
        Welcome->resize(480, 640);
        pushButton = new QPushButton(Welcome);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(220, 475, 86, 31));
        QIcon icon;
        icon.addFile(QStringLiteral("Resources/Cancel-26.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(20, 20));
        about = new QPushButton(Welcome);
        about->setObjectName(QStringLiteral("about"));
        about->setGeometry(QRect(215, 355, 90, 31));
        QIcon icon1;
        icon1.addFile(QStringLiteral("Resources/Info-528.png"), QSize(), QIcon::Normal, QIcon::Off);
        about->setIcon(icon1);
        about->setIconSize(QSize(20, 20));
        pushButton_3 = new QPushButton(Welcome);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(180, 190, 171, 61));
        QIcon icon2;
        icon2.addFile(QStringLiteral("Resources/Ok-520.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon2);

        retranslateUi(Welcome);

        QMetaObject::connectSlotsByName(Welcome);
    } // setupUi

    void retranslateUi(QWidget *Welcome)
    {
        Welcome->setWindowTitle(QApplication::translate("Welcome", "Form", 0));
        pushButton->setText(QApplication::translate("Welcome", " Quitter", 0));
        about->setText(QApplication::translate("Welcome", " \303\200 propos", 0));
        pushButton_3->setText(QApplication::translate("Welcome", "VIVE MATOUB", 0));
    } // retranslateUi

};

namespace Ui {
    class Welcome: public Ui_Welcome {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELCOME_H
