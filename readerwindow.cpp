#include "readerwindow.h"
#include "ui_readerwindow.h"
#include <QFile>
#include <QDataStream>
#include <QDebug>

#include "Config.h"

#include <QTableWidgetItem>
#include <QMessageBox>


ReaderWindow::ReaderWindow(User &user, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ReaderWindow),
    currentUser(user)
{
    ui->setupUi(this);
    loadBooks();
}

ReaderWindow::~ReaderWindow()
{
    delete ui;
}

void ReaderWindow::loadBooks()
{
    currentBooksList.clear();

    QFile file(Config::BooksBin);
    if (file.open(QIODevice::ReadOnly)) {
        QDataStream ist(&file);
        while (!ist.atEnd()) {
            Book book;
            ist >> book;
            currentBooksList.append(book);
        }
    }

    int row = 0;
    foreach (const Book &book, currentBooksList) {
        if(book.cardNumber() == 0 || book.cardNumber() == currentUser.number()){
            QTableWidgetItem *item_name = new QTableWidgetItem(book.name());
            QTableWidgetItem *item_author  = new QTableWidgetItem(book.author());
            QTableWidgetItem *item_pagesAmount  = new QTableWidgetItem(QString::number(book.pagesAmount()));

            ui->avaliableBooksTable->insertRow(row);
            ui->avaliableBooksTable->setItem(row, 0, item_name);
            ui->avaliableBooksTable->setItem(row, 1, item_author);
            ui->avaliableBooksTable->setItem(row, 2, item_pagesAmount);

            if(book.cardNumber() == currentUser.number()){
                ui->avaliableBooksTable->item(row, 0)->setBackground(Qt::red);
                ui->avaliableBooksTable->item(row, 1)->setBackground(Qt::red);
                ui->avaliableBooksTable->item(row, 2)->setBackground(Qt::red);
            }
            row++;
        }

    }
}

void ReaderWindow::takeBook(){
    int currentRow = ui->avaliableBooksTable->currentRow();
    if(currentRow != -1){
        Book book = currentBooksList[currentRow];
        if(book.cardNumber() != currentUser.number()){
            book.setBookCardNumber(currentUser.number());
            book.setBookIssueDate(QDate::currentDate());
            currentBooksList[currentRow] = book;

            ui->avaliableBooksTable->item(currentRow, 0)->setBackground(Qt::red);
            ui->avaliableBooksTable->item(currentRow, 1)->setBackground(Qt::red);
            ui->avaliableBooksTable->item(currentRow, 2)->setBackground(Qt::red);

            QFile read_file(Config::BooksBin);
            if (read_file.open(QIODevice::ReadOnly))
            {
                //C:\\Kursach\\Library\\Library\\//
                QFile write_file("book_file");
                write_file.open(QIODevice::WriteOnly);

                QDataStream read_ist(&read_file);
                QDataStream write_ist(&write_file);

                while (!read_ist.atEnd())
                {
                    Book bufferBook;
                    read_ist >> bufferBook;

                    if (bufferBook.name() == book.name())
                    {
                        bufferBook = book;
                    }

                    write_ist << bufferBook;
                }
                read_file.close();
                read_file.remove();
                write_file.close();
                write_file.rename(Config::BooksBin);
            }
        }
        else {
            QMessageBox msgBox;
            msgBox.setText("Ошибка!");
            msgBox.setInformativeText("Вы уже взяли эту книгу!");
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.setDefaultButton(QMessageBox::Ok);
            msgBox.exec();
        }
    }
}

void ReaderWindow::returnBook(){
    int currentRow = ui->avaliableBooksTable->currentRow();
    if(currentRow != -1){
        Book book = currentBooksList[currentRow];
        if(book.cardNumber() == currentUser.number()){
            book.setBookCardNumber(0);
            currentBooksList[currentRow] = book;

            ui->avaliableBooksTable->item(currentRow, 0)->setBackground(Qt::white);
            ui->avaliableBooksTable->item(currentRow, 1)->setBackground(Qt::white);
            ui->avaliableBooksTable->item(currentRow, 2)->setBackground(Qt::white);

            QFile read_file(Config::BooksBin);
            if (read_file.open(QIODevice::ReadOnly))
            {
                //C:\\Kursach\\Library\\Library\\//
                QFile write_file("book_file");
                write_file.open(QIODevice::WriteOnly);

                QDataStream read_ist(&read_file);
                QDataStream write_ist(&write_file);

                while (!read_ist.atEnd())
                {
                    Book bufferBook;
                    read_ist >> bufferBook;

                    if (bufferBook.name() == book.name())
                    {
                        bufferBook = book;
                    }

                    write_ist << bufferBook;
                }
                read_file.close();
                read_file.remove();
                write_file.close();
                write_file.rename(Config::BooksBin);
            }
        }
        else {
            QMessageBox msgBox;
            msgBox.setText("Ошибка!");
            msgBox.setInformativeText("Вы не можете вернуть книгу, которой у вас нет!");
            msgBox.setStandardButtons(QMessageBox::Ok);
            msgBox.setDefaultButton(QMessageBox::Ok);
            msgBox.exec();
        }
    }
}
