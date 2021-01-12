/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QLabel *bookLabel;
    QLabel *userLabel;
    QPushButton *giftBook;
    QPushButton *changeBooks;
    QPushButton *changeUsers;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QTableWidget *booksTable;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *usersTable;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        bookLabel = new QLabel(MainWindow);
        bookLabel->setObjectName(QString::fromUtf8("bookLabel"));
        bookLabel->setGeometry(QRect(140, 20, 121, 30));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        bookLabel->setFont(font);
        userLabel = new QLabel(MainWindow);
        userLabel->setObjectName(QString::fromUtf8("userLabel"));
        userLabel->setGeometry(QRect(460, 20, 281, 30));
        userLabel->setFont(font);
        giftBook = new QPushButton(MainWindow);
        giftBook->setObjectName(QString::fromUtf8("giftBook"));
        giftBook->setGeometry(QRect(20, 560, 220, 30));
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setUnderline(true);
        font1.setWeight(75);
        giftBook->setFont(font1);
        changeBooks = new QPushButton(MainWindow);
        changeBooks->setObjectName(QString::fromUtf8("changeBooks"));
        changeBooks->setGeometry(QRect(560, 560, 220, 30));
        changeBooks->setFont(font1);
        changeUsers = new QPushButton(MainWindow);
        changeUsers->setObjectName(QString::fromUtf8("changeUsers"));
        changeUsers->setGeometry(QRect(250, 560, 300, 30));
        changeUsers->setFont(font1);
        verticalLayoutWidget = new QWidget(MainWindow);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 80, 361, 461));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        booksTable = new QTableWidget(verticalLayoutWidget);
        if (booksTable->columnCount() < 3)
            booksTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        booksTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        booksTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        booksTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        booksTable->setObjectName(QString::fromUtf8("booksTable"));

        verticalLayout->addWidget(booksTable);

        verticalLayoutWidget_2 = new QWidget(MainWindow);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(420, 80, 361, 461));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        usersTable = new QTableWidget(verticalLayoutWidget_2);
        if (usersTable->columnCount() < 4)
            usersTable->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        usersTable->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        usersTable->setHorizontalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        usersTable->setHorizontalHeaderItem(2, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        usersTable->setHorizontalHeaderItem(3, __qtablewidgetitem6);
        usersTable->setObjectName(QString::fromUtf8("usersTable"));

        verticalLayout_2->addWidget(usersTable);


        retranslateUi(MainWindow);
        QObject::connect(changeUsers, SIGNAL(clicked()), MainWindow, SLOT(onManageUsersClicked()));
        QObject::connect(changeBooks, SIGNAL(clicked()), MainWindow, SLOT(onManageBooksClicked()));
        QObject::connect(giftBook, SIGNAL(clicked()), MainWindow, SLOT(giftBook()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        bookLabel->setText(QCoreApplication::translate("MainWindow", "\320\232\320\235\320\230\320\223\320\230", nullptr));
        userLabel->setText(QCoreApplication::translate("MainWindow", "\320\237\320\236\320\233\320\254\320\227\320\236\320\222\320\220\320\242\320\225\320\233\320\230", nullptr));
        giftBook->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\264\320\260\321\202\321\214 \320\272\320\275\320\270\320\263\321\203", nullptr));
        changeBooks->setText(QCoreApplication::translate("MainWindow", "\320\243\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\272\320\275\320\270\320\263\320\260\320\274\320\270", nullptr));
        changeUsers->setText(QCoreApplication::translate("MainWindow", "\320\243\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217\320\274\320\270", nullptr));
        QTableWidgetItem *___qtablewidgetitem = booksTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = booksTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "\320\220\320\262\321\202\320\276\321\200", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = booksTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "\320\247\320\270\321\201\320\273\320\276 \321\201\321\202\321\200\320\260\320\275\320\270\321\206", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = usersTable->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = usersTable->horizontalHeaderItem(1);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "\320\230\320\274\321\217", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = usersTable->horizontalHeaderItem(2);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = usersTable->horizontalHeaderItem(3);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "\342\204\226 \321\207\320\270\321\202\320\260\321\202\320\265\320\273\321\214\321\201\320\272\320\276\320\263\320\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
