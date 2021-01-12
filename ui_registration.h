/********************************************************************************
** Form generated from reading UI file 'registration.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRATION_H
#define UI_REGISTRATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Registration
{
public:
    QLineEdit *loginLineEdit;
    QLineEdit *passwordLineEdit;
    QLineEdit *nameLineEdit;
    QLineEdit *surnameLineEdit;
    QLineEdit *patronymicLineEdit;
    QLineEdit *homeLineEdit;
    QPushButton *enterButton;
    QPushButton *regButton;
    QLabel *loginLabel;
    QLabel *passwordLabel;
    QLabel *nameLabel;
    QLabel *surnameLabel;
    QLabel *patronymicLabel;
    QLabel *homeLabel;
    QLabel *errorLable;

    void setupUi(QWidget *Registration)
    {
        if (Registration->objectName().isEmpty())
            Registration->setObjectName(QString::fromUtf8("Registration"));
        Registration->resize(800, 600);
        loginLineEdit = new QLineEdit(Registration);
        loginLineEdit->setObjectName(QString::fromUtf8("loginLineEdit"));
        loginLineEdit->setGeometry(QRect(300, 45, 400, 35));
        passwordLineEdit = new QLineEdit(Registration);
        passwordLineEdit->setObjectName(QString::fromUtf8("passwordLineEdit"));
        passwordLineEdit->setGeometry(QRect(300, 125, 400, 35));
        nameLineEdit = new QLineEdit(Registration);
        nameLineEdit->setObjectName(QString::fromUtf8("nameLineEdit"));
        nameLineEdit->setGeometry(QRect(300, 205, 400, 35));
        surnameLineEdit = new QLineEdit(Registration);
        surnameLineEdit->setObjectName(QString::fromUtf8("surnameLineEdit"));
        surnameLineEdit->setGeometry(QRect(300, 285, 400, 35));
        patronymicLineEdit = new QLineEdit(Registration);
        patronymicLineEdit->setObjectName(QString::fromUtf8("patronymicLineEdit"));
        patronymicLineEdit->setGeometry(QRect(300, 365, 400, 35));
        homeLineEdit = new QLineEdit(Registration);
        homeLineEdit->setObjectName(QString::fromUtf8("homeLineEdit"));
        homeLineEdit->setGeometry(QRect(300, 445, 400, 35));
        enterButton = new QPushButton(Registration);
        enterButton->setObjectName(QString::fromUtf8("enterButton"));
        enterButton->setGeometry(QRect(400, 540, 371, 41));
        QFont font;
        font.setPointSize(17);
        font.setBold(true);
        font.setUnderline(true);
        font.setWeight(75);
        enterButton->setFont(font);
        regButton = new QPushButton(Registration);
        regButton->setObjectName(QString::fromUtf8("regButton"));
        regButton->setGeometry(QRect(20, 540, 371, 41));
        regButton->setFont(font);
        loginLabel = new QLabel(Registration);
        loginLabel->setObjectName(QString::fromUtf8("loginLabel"));
        loginLabel->setGeometry(QRect(100, 40, 121, 35));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setWeight(75);
        loginLabel->setFont(font1);
        passwordLabel = new QLabel(Registration);
        passwordLabel->setObjectName(QString::fromUtf8("passwordLabel"));
        passwordLabel->setGeometry(QRect(100, 120, 181, 35));
        passwordLabel->setFont(font1);
        nameLabel = new QLabel(Registration);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
        nameLabel->setGeometry(QRect(120, 200, 141, 35));
        nameLabel->setFont(font1);
        surnameLabel = new QLabel(Registration);
        surnameLabel->setObjectName(QString::fromUtf8("surnameLabel"));
        surnameLabel->setGeometry(QRect(90, 280, 151, 35));
        surnameLabel->setFont(font1);
        patronymicLabel = new QLabel(Registration);
        patronymicLabel->setObjectName(QString::fromUtf8("patronymicLabel"));
        patronymicLabel->setGeometry(QRect(90, 360, 151, 35));
        patronymicLabel->setFont(font1);
        homeLabel = new QLabel(Registration);
        homeLabel->setObjectName(QString::fromUtf8("homeLabel"));
        homeLabel->setGeometry(QRect(50, 440, 231, 35));
        homeLabel->setFont(font1);
        errorLable = new QLabel(Registration);
        errorLable->setObjectName(QString::fromUtf8("errorLable"));
        errorLable->setGeometry(QRect(200, 500, 400, 30));

        retranslateUi(Registration);
        QObject::connect(regButton, SIGNAL(clicked()), Registration, SLOT(on_accept_clicked()));

        QMetaObject::connectSlotsByName(Registration);
    } // setupUi

    void retranslateUi(QWidget *Registration)
    {
        Registration->setWindowTitle(QCoreApplication::translate("Registration", "Form", nullptr));
        enterButton->setText(QCoreApplication::translate("Registration", "\320\222\320\236\320\231\320\242\320\230", nullptr));
        regButton->setText(QCoreApplication::translate("Registration", "\320\227\320\220\320\240\320\225\320\223\320\230\320\241\320\242\320\240\320\230\320\240\320\236\320\222\320\220\320\242\320\254\320\241\320\257", nullptr));
        loginLabel->setText(QCoreApplication::translate("Registration", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        passwordLabel->setText(QCoreApplication::translate("Registration", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        nameLabel->setText(QCoreApplication::translate("Registration", "\320\230\320\274\321\217", nullptr));
        surnameLabel->setText(QCoreApplication::translate("Registration", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", nullptr));
        patronymicLabel->setText(QCoreApplication::translate("Registration", "\320\236\321\202\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
        homeLabel->setText(QCoreApplication::translate("Registration", "\320\224\320\276\320\274\320\260\321\210\320\275\320\270\320\271 \320\260\320\264\321\200\320\265\321\201", nullptr));
        errorLable->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Registration: public Ui_Registration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATION_H
