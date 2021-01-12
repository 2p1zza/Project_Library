#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QDataStream>
#include <QDebug>
#include "Config.h"
#include <QDateTime>
#include <QTableWidgetItem>

#include "manageusers.h"
#include "managebooks.h"

MainWindow::MainWindow(User &user, QWidget *parent)
    : QWidget(parent),
      ui(new Ui::MainWindow),
      currentUser(user)

{
    ui->setupUi(this);

    if(user.status() == User::Librarian){
        ui->changeBooks->hide();
        ui->changeUsers->hide();
    }
    loadUsers();
    loadBooks();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::giftBook(){
    int currentRowBook = ui->booksTable->currentRow();
    int currentRowUser = ui->usersTable->currentRow();

    if(currentRowBook != -1 && currentRowUser != -1){
        Book book = currentBooksList[currentRowBook];
        User user = currentUsersList[currentRowUser];

        book.setBookCardNumber(user.number());
        book.setBookIssueDate(QDate::currentDate());

        currentBooksList[currentRowBook] = book;
        ui->booksTable->removeRow(currentRowBook);

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
}

void MainWindow::loadBooks()
{
    currentBooksList.clear();
    ui->booksTable->model()->removeRows(0, ui->booksTable->rowCount());


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
        if(book.cardNumber() == 0){
            QTableWidgetItem *item_name = new QTableWidgetItem(book.name());
            QTableWidgetItem *item_author  = new QTableWidgetItem(book.author());
            QTableWidgetItem *item_pagesAmount  = new QTableWidgetItem(QString::number(book.pagesAmount()));

            ui->booksTable->insertRow(row);
            ui->booksTable->setItem(row, 0, item_name);
            ui->booksTable->setItem(row, 1, item_author );
            ui->booksTable->setItem(row, 2, item_pagesAmount );
            row++;
        }
    }
    ui->booksTable->update();
}

void MainWindow::loadUsers()
{
    currentUsersList.clear();
    ui->usersTable->model()->removeRows(0, ui->usersTable->rowCount());

    QFile file(Config::Usersbin);
    if (file.open(QIODevice::ReadOnly)) {
        QDataStream ist(&file);
        while (!ist.atEnd()) {
            User user;
            ist >> user;
            if(user.number() != 0){
            currentUsersList.append(user);
            }
        }
    }

    int row = 0;
    foreach (const User &user, currentUsersList) {
        if(user.number() != 0){
            QTableWidgetItem *item_name = new QTableWidgetItem(user.name());
            QTableWidgetItem *item_surname  = new QTableWidgetItem(user.surname());
            QTableWidgetItem *item_patronymic  = new QTableWidgetItem(user.patronymic());
            QTableWidgetItem *item_number  = new QTableWidgetItem(QString::number(user.number()));

            ui->usersTable->insertRow(row);// Вставка строки в таблицу
            ui->usersTable->setItem(row, 0, item_surname);
            ui->usersTable->setItem(row, 1, item_name);
            ui->usersTable->setItem(row, 2, item_patronymic);
            ui->usersTable->setItem(row, 3, item_number);
            row++;
        }
    }
    ui->usersTable->update();
}

void MainWindow::onManageUsersClicked(){
    ManageUsers dialog(this);
    dialog.setWindowTitle("Управление пользователями");
    dialog.show();
    if (dialog.exec() == QDialog::Rejected)
    {
        loadUsers();
    }
}

void MainWindow::onManageBooksClicked(){
    ManageBooks manageBooks(this);
    manageBooks.setWindowTitle("Управление книгами");
    manageBooks.show();
    if (manageBooks.exec() == QDialog::Rejected)
    {
        loadBooks();
    }
}
