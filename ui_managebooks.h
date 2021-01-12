/********************************************************************************
** Form generated from reading UI file 'managebooks.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGEBOOKS_H
#define UI_MANAGEBOOKS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_ManageBooks
{
public:
    QPushButton *addButton;
    QPushButton *delButton;
    QPushButton *exitButton;
    QTableWidget *booksTable;

    void setupUi(QDialog *ManageBooks)
    {
        if (ManageBooks->objectName().isEmpty())
            ManageBooks->setObjectName(QString::fromUtf8("ManageBooks"));
        ManageBooks->resize(800, 600);
        addButton = new QPushButton(ManageBooks);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        addButton->setGeometry(QRect(110, 530, 75, 23));
        delButton = new QPushButton(ManageBooks);
        delButton->setObjectName(QString::fromUtf8("delButton"));
        delButton->setGeometry(QRect(350, 530, 75, 23));
        exitButton = new QPushButton(ManageBooks);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setGeometry(QRect(580, 530, 75, 23));
        booksTable = new QTableWidget(ManageBooks);
        if (booksTable->columnCount() < 3)
            booksTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        booksTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        booksTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        booksTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        booksTable->setObjectName(QString::fromUtf8("booksTable"));
        booksTable->setGeometry(QRect(30, 41, 721, 431));

        retranslateUi(ManageBooks);
        QObject::connect(delButton, SIGNAL(clicked()), ManageBooks, SLOT(onDeleteClicked()));
        QObject::connect(addButton, SIGNAL(clicked()), ManageBooks, SLOT(onAddClicked()));
        QObject::connect(exitButton, SIGNAL(clicked()), ManageBooks, SLOT(reject()));

        QMetaObject::connectSlotsByName(ManageBooks);
    } // setupUi

    void retranslateUi(QDialog *ManageBooks)
    {
        ManageBooks->setWindowTitle(QCoreApplication::translate("ManageBooks", "Dialog", nullptr));
        addButton->setText(QCoreApplication::translate("ManageBooks", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        delButton->setText(QCoreApplication::translate("ManageBooks", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        exitButton->setText(QCoreApplication::translate("ManageBooks", "\320\222\321\213\320\271\321\202\320\270", nullptr));
        QTableWidgetItem *___qtablewidgetitem = booksTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("ManageBooks", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = booksTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("ManageBooks", "\320\220\320\262\321\202\320\276\321\200", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = booksTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("ManageBooks", "\320\232\320\276\320\273-\320\262\320\276 \321\201\321\202\321\200\320\260\320\275\320\270\321\206", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ManageBooks: public Ui_ManageBooks {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGEBOOKS_H
