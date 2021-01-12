/********************************************************************************
** Form generated from reading UI file 'manageusers.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGEUSERS_H
#define UI_MANAGEUSERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_ManageUsers
{
public:
    QPushButton *addNewButton;
    QPushButton *deleteUserButton;
    QPushButton *exitButton;
    QTableWidget *usersTable;

    void setupUi(QDialog *ManageUsers)
    {
        if (ManageUsers->objectName().isEmpty())
            ManageUsers->setObjectName(QString::fromUtf8("ManageUsers"));
        ManageUsers->resize(800, 600);
        addNewButton = new QPushButton(ManageUsers);
        addNewButton->setObjectName(QString::fromUtf8("addNewButton"));
        addNewButton->setGeometry(QRect(140, 520, 75, 23));
        deleteUserButton = new QPushButton(ManageUsers);
        deleteUserButton->setObjectName(QString::fromUtf8("deleteUserButton"));
        deleteUserButton->setGeometry(QRect(350, 520, 75, 23));
        exitButton = new QPushButton(ManageUsers);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setGeometry(QRect(570, 520, 75, 23));
        usersTable = new QTableWidget(ManageUsers);
        if (usersTable->columnCount() < 6)
            usersTable->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        usersTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        usersTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        usersTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        usersTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        usersTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        usersTable->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        usersTable->setObjectName(QString::fromUtf8("usersTable"));
        usersTable->setGeometry(QRect(40, 30, 691, 421));

        retranslateUi(ManageUsers);
        QObject::connect(deleteUserButton, SIGNAL(clicked()), ManageUsers, SLOT(onDeleteClicked()));
        QObject::connect(addNewButton, SIGNAL(clicked()), ManageUsers, SLOT(onAddClicked()));
        QObject::connect(exitButton, SIGNAL(clicked()), ManageUsers, SLOT(reject()));

        QMetaObject::connectSlotsByName(ManageUsers);
    } // setupUi

    void retranslateUi(QDialog *ManageUsers)
    {
        ManageUsers->setWindowTitle(QCoreApplication::translate("ManageUsers", "Dialog", nullptr));
        addNewButton->setText(QCoreApplication::translate("ManageUsers", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        deleteUserButton->setText(QCoreApplication::translate("ManageUsers", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        exitButton->setText(QCoreApplication::translate("ManageUsers", "\320\222\321\213\320\271\321\202\320\270", nullptr));
        QTableWidgetItem *___qtablewidgetitem = usersTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("ManageUsers", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = usersTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("ManageUsers", "\320\230\320\274\321\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = usersTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("ManageUsers", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = usersTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("ManageUsers", "\320\236\321\202\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = usersTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("ManageUsers", "\320\224\320\276\320\274. \320\260\320\264\321\200\320\265\321\201", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = usersTable->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("ManageUsers", "\320\241\321\202\320\260\321\202\321\203\321\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ManageUsers: public Ui_ManageUsers {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGEUSERS_H
