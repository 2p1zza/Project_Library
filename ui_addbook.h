/********************************************************************************
** Form generated from reading UI file 'addbook.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDBOOK_H
#define UI_ADDBOOK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AddBook
{
public:
    QPushButton *addBookButton;
    QPushButton *exitButton;
    QLabel *nameLabel;
    QLabel *authorLabel;
    QLabel *pagesLabel;
    QLineEdit *nameLineEdit;
    QLineEdit *authorLineEdit;
    QLineEdit *pagesLineEdit;
    QLabel *errorLabel;

    void setupUi(QDialog *AddBook)
    {
        if (AddBook->objectName().isEmpty())
            AddBook->setObjectName(QString::fromUtf8("AddBook"));
        AddBook->resize(800, 600);
        addBookButton = new QPushButton(AddBook);
        addBookButton->setObjectName(QString::fromUtf8("addBookButton"));
        addBookButton->setGeometry(QRect(254, 512, 141, 51));
        exitButton = new QPushButton(AddBook);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setGeometry(QRect(430, 512, 141, 51));
        nameLabel = new QLabel(AddBook);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
        nameLabel->setGeometry(QRect(130, 50, 111, 41));
        QFont font;
        font.setPointSize(12);
        nameLabel->setFont(font);
        authorLabel = new QLabel(AddBook);
        authorLabel->setObjectName(QString::fromUtf8("authorLabel"));
        authorLabel->setGeometry(QRect(130, 130, 111, 51));
        authorLabel->setFont(font);
        pagesLabel = new QLabel(AddBook);
        pagesLabel->setObjectName(QString::fromUtf8("pagesLabel"));
        pagesLabel->setGeometry(QRect(130, 220, 141, 31));
        pagesLabel->setFont(font);
        nameLineEdit = new QLineEdit(AddBook);
        nameLineEdit->setObjectName(QString::fromUtf8("nameLineEdit"));
        nameLineEdit->setGeometry(QRect(270, 49, 341, 51));
        authorLineEdit = new QLineEdit(AddBook);
        authorLineEdit->setObjectName(QString::fromUtf8("authorLineEdit"));
        authorLineEdit->setGeometry(QRect(270, 129, 341, 51));
        pagesLineEdit = new QLineEdit(AddBook);
        pagesLineEdit->setObjectName(QString::fromUtf8("pagesLineEdit"));
        pagesLineEdit->setGeometry(QRect(270, 209, 341, 51));
        errorLabel = new QLabel(AddBook);
        errorLabel->setObjectName(QString::fromUtf8("errorLabel"));
        errorLabel->setGeometry(QRect(190, 360, 561, 71));
        QPalette palette;
        QBrush brush(QColor(255, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush1(QColor(255, 0, 0, 128));
        brush1.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush1);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush1);
#endif
        QBrush brush2(QColor(120, 120, 120, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        QBrush brush3(QColor(0, 0, 0, 128));
        brush3.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush3);
#endif
        errorLabel->setPalette(palette);
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        errorLabel->setFont(font1);

        retranslateUi(AddBook);
        QObject::connect(addBookButton, SIGNAL(clicked()), AddBook, SLOT(accept()));
        QObject::connect(exitButton, SIGNAL(clicked()), AddBook, SLOT(reject()));

        QMetaObject::connectSlotsByName(AddBook);
    } // setupUi

    void retranslateUi(QDialog *AddBook)
    {
        AddBook->setWindowTitle(QCoreApplication::translate("AddBook", "Dialog", nullptr));
        addBookButton->setText(QCoreApplication::translate("AddBook", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        exitButton->setText(QCoreApplication::translate("AddBook", "\320\222\321\213\320\271\321\202\320\270", nullptr));
        nameLabel->setText(QCoreApplication::translate("AddBook", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        authorLabel->setText(QCoreApplication::translate("AddBook", "\320\220\320\262\321\202\320\276\321\200", nullptr));
        pagesLabel->setText(QCoreApplication::translate("AddBook", "\320\247\320\270\321\201\320\273\320\276 \321\201\321\202\321\200\320\260\320\275\320\270\321\206", nullptr));
        errorLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AddBook: public Ui_AddBook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDBOOK_H
