#include "managebooks.h"
#include "ui_managebooks.h"

#include "Config.h"
#include "addbook.h"

#include <QTableWidgetItem>
#include <QFile>
#include <QDataStream>
#include <QMessageBox>
#include <QDebug>

ManageBooks::ManageBooks(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManageBooks)
{
    ui->setupUi(this);

    booksList.clear();

    QFile file(Config::BooksBin);
    if (file.open(QIODevice::ReadOnly)) {
        QDataStream ist(&file);

        while (!ist.atEnd()) {
            Book book;
            ist >> book;
            booksList.append(book);
        }
    }

    int row = 0;
    foreach (const Book &book, booksList) {
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

ManageBooks::~ManageBooks()
{
    delete ui;
}

void ManageBooks::onDeleteClicked()
{
    int currentRow = ui->booksTable->currentRow();
    if (currentRow != -1)
    {
        const QString name = ui->booksTable->item(currentRow, 0)->text();

        ui->booksTable->removeRow(currentRow);

        QFile read_file(Config::BooksBin);
        if (read_file.open(QIODevice::ReadOnly))
        {
            //C:\\Kursach\\Library\\Library\\//
            QFile write_file("buf_file_books");
            write_file.open(QIODevice::WriteOnly);

            QDataStream read_ist(&read_file);
            QDataStream write_ist(&write_file);

            while (!read_ist.atEnd())
            {
                Book book;
                read_ist >> book;

                if (book.name() != name)
                {
                    write_ist << book;
                }
            }

            read_file.close();
            read_file.remove();
            write_file.close();
            write_file.rename(Config::BooksBin);
        }
    }
    else
    {
        QMessageBox::warning(this, windowTitle(),
                             "Ошибка: Необходимо выбрать книгу!");
    }
}

void ManageBooks::onAddClicked()
{

    AddBook dialog(this);
    dialog.setWindowTitle(windowTitle());

    if (dialog.exec() == QDialog::Accepted){

        const Book &book = dialog.getBook();

        QFile file(Config::BooksBin);
        file.open(QIODevice::Append);
        QDataStream ost(&file);
        ost << book;


        QTableWidgetItem *item_name = new QTableWidgetItem(book.name());
        QTableWidgetItem *item_author = new QTableWidgetItem(book.author());
        QTableWidgetItem *item_pagesAmount  = new QTableWidgetItem(QString::number(book.pagesAmount()));

        int row = ui->booksTable->rowCount();
        ui->booksTable->insertRow(row);
        ui->booksTable->setItem(row, 0, item_name);
        ui->booksTable->setItem(row, 1, item_author);
        ui->booksTable->setItem(row, 2, item_pagesAmount);
    }
}
