/********************************************************************************
** Form generated from reading UI file 'readerwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_READERWINDOW_H
#define UI_READERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ReaderWindow
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QTableWidget *avaliableBooksTable;
    QPushButton *getBookButton;
    QPushButton *returnBookButton;

    void setupUi(QWidget *ReaderWindow)
    {
        if (ReaderWindow->objectName().isEmpty())
            ReaderWindow->setObjectName(QString::fromUtf8("ReaderWindow"));
        ReaderWindow->resize(800, 600);
        QFont font;
        font.setPointSize(9);
        font.setBold(false);
        font.setUnderline(false);
        font.setWeight(50);
        ReaderWindow->setFont(font);
        verticalLayoutWidget = new QWidget(ReaderWindow);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(40, 30, 711, 481));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        avaliableBooksTable = new QTableWidget(verticalLayoutWidget);
        if (avaliableBooksTable->columnCount() < 3)
            avaliableBooksTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        avaliableBooksTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        avaliableBooksTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        avaliableBooksTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        avaliableBooksTable->setObjectName(QString::fromUtf8("avaliableBooksTable"));

        verticalLayout->addWidget(avaliableBooksTable);

        getBookButton = new QPushButton(ReaderWindow);
        getBookButton->setObjectName(QString::fromUtf8("getBookButton"));
        getBookButton->setGeometry(QRect(40, 540, 311, 41));
        QFont font1;
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setUnderline(true);
        font1.setWeight(75);
        getBookButton->setFont(font1);
        returnBookButton = new QPushButton(ReaderWindow);
        returnBookButton->setObjectName(QString::fromUtf8("returnBookButton"));
        returnBookButton->setGeometry(QRect(440, 540, 331, 41));
        returnBookButton->setFont(font1);

        retranslateUi(ReaderWindow);
        QObject::connect(returnBookButton, SIGNAL(clicked()), ReaderWindow, SLOT(returnBook()));
        QObject::connect(getBookButton, SIGNAL(clicked()), ReaderWindow, SLOT(takeBook()));

        QMetaObject::connectSlotsByName(ReaderWindow);
    } // setupUi

    void retranslateUi(QWidget *ReaderWindow)
    {
        ReaderWindow->setWindowTitle(QCoreApplication::translate("ReaderWindow", "Form", nullptr));
        QTableWidgetItem *___qtablewidgetitem = avaliableBooksTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("ReaderWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = avaliableBooksTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("ReaderWindow", "\320\220\320\262\321\202\320\276\321\200", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = avaliableBooksTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("ReaderWindow", "\320\232\320\276\320\273-\320\262\320\276 \321\201\321\202\321\200\320\260\320\275\320\270\321\206", nullptr));
        getBookButton->setText(QCoreApplication::translate("ReaderWindow", "\320\222\320\227\320\257\320\242\320\254 \320\232\320\235\320\230\320\223\320\243", nullptr));
        returnBookButton->setText(QCoreApplication::translate("ReaderWindow", "\320\222\320\225\320\240\320\235\320\243\320\242\320\254 \320\232\320\235\320\230\320\223\320\243", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ReaderWindow: public Ui_ReaderWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_READERWINDOW_H
