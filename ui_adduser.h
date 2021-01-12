/********************************************************************************
** Form generated from reading UI file 'adduser.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDUSER_H
#define UI_ADDUSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_addUser
{
public:
    QPushButton *saveButton;
    QPushButton *cancelButton;
    QLabel *loginLabel;
    QLabel *passwordLabel;
    QLabel *surnameLabel;
    QLabel *nameLabel;
    QLabel *patronymicLabel;
    QLabel *homeLabel;
    QLineEdit *loginLineEdit;
    QLineEdit *lineEpasswordLineEdit;
    QLineEdit *surnameLineEdit;
    QLineEdit *nameLineEdit;
    QLineEdit *patronymicLineEdit;
    QLineEdit *homeLineEdit;
    QComboBox *comboBox;
    QLabel *errorLabel;

    void setupUi(QDialog *addUser)
    {
        if (addUser->objectName().isEmpty())
            addUser->setObjectName(QString::fromUtf8("addUser"));
        addUser->resize(800, 600);
        saveButton = new QPushButton(addUser);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        saveButton->setGeometry(QRect(600, 530, 91, 23));
        cancelButton = new QPushButton(addUser);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(474, 530, 91, 23));
        loginLabel = new QLabel(addUser);
        loginLabel->setObjectName(QString::fromUtf8("loginLabel"));
        loginLabel->setGeometry(QRect(60, 60, 47, 13));
        passwordLabel = new QLabel(addUser);
        passwordLabel->setObjectName(QString::fromUtf8("passwordLabel"));
        passwordLabel->setGeometry(QRect(60, 120, 61, 20));
        surnameLabel = new QLabel(addUser);
        surnameLabel->setObjectName(QString::fromUtf8("surnameLabel"));
        surnameLabel->setGeometry(QRect(50, 200, 71, 16));
        nameLabel = new QLabel(addUser);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
        nameLabel->setGeometry(QRect(70, 270, 47, 13));
        patronymicLabel = new QLabel(addUser);
        patronymicLabel->setObjectName(QString::fromUtf8("patronymicLabel"));
        patronymicLabel->setGeometry(QRect(50, 330, 81, 16));
        homeLabel = new QLabel(addUser);
        homeLabel->setObjectName(QString::fromUtf8("homeLabel"));
        homeLabel->setGeometry(QRect(70, 400, 81, 21));
        loginLineEdit = new QLineEdit(addUser);
        loginLineEdit->setObjectName(QString::fromUtf8("loginLineEdit"));
        loginLineEdit->setGeometry(QRect(150, 50, 271, 31));
        lineEpasswordLineEdit = new QLineEdit(addUser);
        lineEpasswordLineEdit->setObjectName(QString::fromUtf8("lineEpasswordLineEdit"));
        lineEpasswordLineEdit->setGeometry(QRect(150, 120, 271, 31));
        surnameLineEdit = new QLineEdit(addUser);
        surnameLineEdit->setObjectName(QString::fromUtf8("surnameLineEdit"));
        surnameLineEdit->setGeometry(QRect(150, 190, 271, 31));
        nameLineEdit = new QLineEdit(addUser);
        nameLineEdit->setObjectName(QString::fromUtf8("nameLineEdit"));
        nameLineEdit->setGeometry(QRect(150, 260, 271, 31));
        patronymicLineEdit = new QLineEdit(addUser);
        patronymicLineEdit->setObjectName(QString::fromUtf8("patronymicLineEdit"));
        patronymicLineEdit->setGeometry(QRect(150, 330, 271, 31));
        homeLineEdit = new QLineEdit(addUser);
        homeLineEdit->setObjectName(QString::fromUtf8("homeLineEdit"));
        homeLineEdit->setGeometry(QRect(150, 400, 271, 31));
        comboBox = new QComboBox(addUser);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(520, 180, 231, 22));
        errorLabel = new QLabel(addUser);
        errorLabel->setObjectName(QString::fromUtf8("errorLabel"));
        errorLabel->setGeometry(QRect(70, 473, 271, 31));

        retranslateUi(addUser);
        QObject::connect(cancelButton, SIGNAL(clicked()), addUser, SLOT(reject()));
        QObject::connect(saveButton, SIGNAL(clicked()), addUser, SLOT(accept()));

        QMetaObject::connectSlotsByName(addUser);
    } // setupUi

    void retranslateUi(QDialog *addUser)
    {
        addUser->setWindowTitle(QCoreApplication::translate("addUser", "Dialog", nullptr));
        saveButton->setText(QCoreApplication::translate("addUser", "\320\241\320\236\320\245\320\240\320\220\320\235\320\230\320\242\320\254", nullptr));
        cancelButton->setText(QCoreApplication::translate("addUser", "\320\236\320\242\320\234\320\225\320\235\320\220", nullptr));
        loginLabel->setText(QCoreApplication::translate("addUser", "\320\233\320\236\320\223\320\230\320\235", nullptr));
        passwordLabel->setText(QCoreApplication::translate("addUser", "\320\237\320\220\320\240\320\236\320\233\320\254", nullptr));
        surnameLabel->setText(QCoreApplication::translate("addUser", "\320\244\320\220\320\234\320\230\320\233\320\230\320\257", nullptr));
        nameLabel->setText(QCoreApplication::translate("addUser", "\320\230\320\234\320\257", nullptr));
        patronymicLabel->setText(QCoreApplication::translate("addUser", "\320\236\320\242\320\247\320\225\320\241\320\242\320\222\320\236", nullptr));
        homeLabel->setText(QCoreApplication::translate("addUser", "\320\224\320\236\320\234", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("addUser", "\320\220\320\264\320\274\320\270\320\275\320\270\321\201\321\202\321\200\320\260\321\202\320\276\321\200", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("addUser", "\320\221\320\270\320\261\320\273\320\270\320\276\321\202\320\265\320\272\320\260\321\200\321\214", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("addUser", "\320\247\320\270\321\202\320\260\321\202\320\265\320\273\321\214", nullptr));

        errorLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class addUser: public Ui_addUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDUSER_H
