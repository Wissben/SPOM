/********************************************************************************
** Form generated from reading UI file 'tutorial.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TUTORIAL_H
#define UI_TUTORIAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Tutorial
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *first;
    QLabel *second;
    QLabel *third;

    void setupUi(QWidget *Tutorial)
    {
        if (Tutorial->objectName().isEmpty())
            Tutorial->setObjectName(QStringLiteral("Tutorial"));
        Tutorial->resize(1368, 680);
        pushButton = new QPushButton(Tutorial);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(0, 4, 50, 671));
        pushButton->setFocusPolicy(Qt::NoFocus);
        QIcon icon;
        icon.addFile(QStringLiteral("Resources/MediaControl/Back-104.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(50, 50));
        pushButton->setFlat(true);
        pushButton_2 = new QPushButton(Tutorial);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(1320, 5, 50, 671));
        pushButton_2->setFocusPolicy(Qt::NoFocus);
        QIcon icon1;
        icon1.addFile(QStringLiteral("Resources/MediaControl/Forward-104.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon1);
        pushButton_2->setIconSize(QSize(50, 50));
        pushButton_2->setFlat(true);
        first = new QLabel(Tutorial);
        first->setObjectName(QStringLiteral("first"));
        first->setGeometry(QRect(450, 20, 480, 640));
        first->setScaledContents(true);
        second = new QLabel(Tutorial);
        second->setObjectName(QStringLiteral("second"));
        second->setGeometry(QRect(50, 0, 1268, 680));
        second->setScaledContents(true);
        third = new QLabel(Tutorial);
        third->setObjectName(QStringLiteral("third"));
        third->setGeometry(QRect(50, 0, 1268, 680));
        third->setScaledContents(true);
        first->raise();
        second->raise();
        pushButton_2->raise();
        pushButton->raise();
        third->raise();

        retranslateUi(Tutorial);

        QMetaObject::connectSlotsByName(Tutorial);
    } // setupUi

    void retranslateUi(QWidget *Tutorial)
    {
        Tutorial->setWindowTitle(QApplication::translate("Tutorial", "Form", 0));
        pushButton->setText(QString());
        pushButton->setShortcut(QApplication::translate("Tutorial", "Left", 0));
        pushButton_2->setText(QString());
        pushButton_2->setShortcut(QApplication::translate("Tutorial", "Right", 0));
        first->setText(QString());
        second->setText(QString());
        third->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Tutorial: public Ui_Tutorial {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TUTORIAL_H
