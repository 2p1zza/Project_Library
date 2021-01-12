/********************************************************************************
** Form generated from reading UI file 'authorization.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHORIZATION_H
#define UI_AUTHORIZATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Authorization
{
public:
    QPushButton *enterButton;
    QLabel *errorLabel;
    QLabel *loginLabel;
    QLabel *passwordLabel;
    QLineEdit *loginLineEdit;
    QLineEdit *passordLineEdit;
    QPushButton *regButton;

    void setupUi(QWidget *Authorization)
    {
        if (Authorization->objectName().isEmpty())
            Authorization->setObjectName(QString::fromUtf8("Authorization"));
        Authorization->resize(800, 600);
        enterButton = new QPushButton(Authorization);
        enterButton->setObjectName(QString::fromUtf8("enterButton"));
        enterButton->setGeometry(QRect(300, 420, 200, 50));
        QFont font;
        font.setPointSize(20);
        font.setBold(false);
        font.setItalic(false);
        font.setUnderline(true);
        font.setWeight(50);
        enterButton->setFont(font);
        errorLabel = new QLabel(Authorization);
        errorLabel->setObjectName(QString::fromUtf8("errorLabel"));
        errorLabel->setGeometry(QRect(136, 19, 631, 91));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setWeight(75);
        errorLabel->setFont(font1);
        loginLabel = new QLabel(Authorization);
        loginLabel->setObjectName(QString::fromUtf8("loginLabel"));
        loginLabel->setGeometry(QRect(340, 150, 131, 50));
        QFont font2;
        font2.setPointSize(20);
        font2.setBold(true);
        font2.setWeight(75);
        loginLabel->setFont(font2);
        passwordLabel = new QLabel(Authorization);
        passwordLabel->setObjectName(QString::fromUtf8("passwordLabel"));
        passwordLabel->setGeometry(QRect(330, 270, 151, 50));
        passwordLabel->setFont(font2);
        loginLineEdit = new QLineEdit(Authorization);
        loginLineEdit->setObjectName(QString::fromUtf8("loginLineEdit"));
        loginLineEdit->setGeometry(QRect(300, 200, 200, 50));
        passordLineEdit = new QLineEdit(Authorization);
        passordLineEdit->setObjectName(QString::fromUtf8("passordLineEdit"));
        passordLineEdit->setGeometry(QRect(300, 320, 200, 50));
        regButton = new QPushButton(Authorization);
        regButton->setObjectName(QString::fromUtf8("regButton"));
        regButton->setGeometry(QRect(200, 500, 400, 50));
        QFont font3;
        font3.setPointSize(20);
        font3.setBold(false);
        font3.setUnderline(true);
        font3.setWeight(50);
        regButton->setFont(font3);

        retranslateUi(Authorization);
        QObject::connect(enterButton, SIGNAL(clicked()), Authorization, SLOT(on_entry_clicked()));

        QMetaObject::connectSlotsByName(Authorization);
    } // setupUi

    void retranslateUi(QWidget *Authorization)
    {
        Authorization->setWindowTitle(QCoreApplication::translate("Authorization", "Form", nullptr));
        enterButton->setText(QCoreApplication::translate("Authorization", "\320\222\320\236\320\231\320\242\320\230", nullptr));
        errorLabel->setText(QString());
        loginLabel->setText(QCoreApplication::translate("Authorization", "\320\233\320\236\320\223\320\230\320\235", nullptr));
        passwordLabel->setText(QCoreApplication::translate("Authorization", "\320\237\320\220\320\240\320\236\320\233\320\254", nullptr));
        loginLineEdit->setText(QString());
        regButton->setText(QCoreApplication::translate("Authorization", "\320\227\320\220\320\240\320\225\320\223\320\230\320\241\320\242\320\240\320\230\320\240\320\236\320\222\320\220\320\242\320\254\320\241\320\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Authorization: public Ui_Authorization {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHORIZATION_H
