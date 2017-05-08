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
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Welcome
{
public:
    QPushButton *pushButton;
    QPushButton *about;
    QPushButton *pushButton_3;
    QLabel *label;
    QTextBrowser *aboutText;
    QPushButton *help;

    void setupUi(QWidget *Welcome)
    {
        if (Welcome->objectName().isEmpty())
            Welcome->setObjectName(QStringLiteral("Welcome"));
        Welcome->resize(480, 640);
        pushButton = new QPushButton(Welcome);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(380, 600, 86, 31));
        pushButton->setStyleSheet(QLatin1String("QPushButton { \n"
"color: 000000;\n"
"}"));
        QIcon icon;
        icon.addFile(QStringLiteral("Resources/Cancel-26.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(20, 20));
        pushButton->setFlat(true);
        about = new QPushButton(Welcome);
        about->setObjectName(QStringLiteral("about"));
        about->setGeometry(QRect(10, 600, 90, 31));
        about->setStyleSheet(QLatin1String("QPushButton { \n"
"color: 000000;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QStringLiteral("Resources/Info-528.png"), QSize(), QIcon::Normal, QIcon::Off);
        about->setIcon(icon1);
        about->setIconSize(QSize(20, 20));
        about->setFlat(true);
        pushButton_3 = new QPushButton(Welcome);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(150, 30, 171, 61));
        pushButton_3->setStyleSheet(QLatin1String("QPushButton { \n"
"color: 000000;\n"
"}"));
        QIcon icon2;
        icon2.addFile(QStringLiteral("Resources/Ok-520.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon2);
        pushButton_3->setFlat(true);
        label = new QLabel(Welcome);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 480, 640));
        label->setPixmap(QPixmap(QString::fromUtf8("Resources/backgrouds/Plandetravail1VGA.png")));
        aboutText = new QTextBrowser(Welcome);
        aboutText->setObjectName(QStringLiteral("aboutText"));
        aboutText->setEnabled(false);
        aboutText->setGeometry(QRect(20, 30, 440, 560));
        aboutText->setUndoRedoEnabled(false);
        help = new QPushButton(Welcome);
        help->setObjectName(QStringLiteral("help"));
        help->setGeometry(QRect(195, 600, 90, 31));
        help->setAutoFillBackground(false);
        help->setStyleSheet(QLatin1String("QPushButton { \n"
"color: 000000;\n"
"}"));
        QIcon icon3;
        icon3.addFile(QStringLiteral("Resources/Help Filled-500.png"), QSize(), QIcon::Normal, QIcon::Off);
        help->setIcon(icon3);
        help->setIconSize(QSize(20, 20));
        help->setFlat(true);
        aboutText->raise();
        label->raise();
        pushButton->raise();
        about->raise();
        pushButton_3->raise();
        help->raise();

        retranslateUi(Welcome);

        QMetaObject::connectSlotsByName(Welcome);
    } // setupUi

    void retranslateUi(QWidget *Welcome)
    {
        Welcome->setWindowTitle(QApplication::translate("Welcome", "Form", 0));
        pushButton->setText(QApplication::translate("Welcome", " Quitter", 0));
        about->setText(QApplication::translate("Welcome", " \303\200 propos", 0));
        pushButton_3->setText(QApplication::translate("Welcome", "VIVE MATOUB", 0));
        label->setText(QString());
        help->setText(QApplication::translate("Welcome", " Aide", 0));
    } // retranslateUi

};

namespace Ui {
    class Welcome: public Ui_Welcome {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELCOME_H
