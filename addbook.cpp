#include "addbook.h"
#include "ui_addbook.h"

#include "Config.h"

#include <QFile>
#include <QRegExp>

AddBook::AddBook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddBook)
{
    ui->setupUi(this);
}

AddBook::~AddBook()
{
    delete ui;
}

const Book &AddBook::getBook() const{
    return newBook;
}

bool AddBook::isNameExists(const QString &name){
    QFile file(Config::BooksBin);

    bool registered = false;

    if (file.exists()){
        if (!file.open(QIODevice::ReadOnly)){
            return registered;
        }

        QDataStream ist(&file);

        while (!ist.atEnd()){
            Book bufferBook;
            ist >> bufferBook;

            if (bufferBook.name() == name){
                registered = true;
            }
        }
        return registered;
    }
    else
        return registered;
}


void AddBook::accept()
{
    QRegExp nameExp ("[А-Я]+[а-я]+");

    bool ok;
    ui->errorLabel->clear();
    const QString name = ui->nameLineEdit->text();
    const QString author = ui->authorLineEdit->text();
    const QString pages = ui->pagesLineEdit->text();
    int pagesAmount = pages.toInt(&ok);

    if (name.isEmpty() || author.isEmpty() || pages.isEmpty())
    {
        ui->errorLabel->setText("Ошибка: необходимо заполнить все поля!");
    }
    else if (isNameExists(name))
    {
        if (ui->errorLabel->text().isEmpty())
            ui->errorLabel->setText("Ошибка: Книга с таким именем уже существует!");
    }
    else if (!name.contains(nameExp))
    {
        ui->errorLabel->setText("Ошибка: имя пользователя введено неверно!");
    }
    else if (!author.contains(nameExp))
    {
        ui->errorLabel->setText("Ошибка: имя автора введено неверно!");
    }
    else if(ok == false){
        ui->errorLabel->setText("Ошибка: неверно указано число страниц!");
    }
    else
    {
        newBook.setBookName(name);
        newBook.setBookAuthor(author);
        newBook.setBookPagesAmount(pagesAmount);
        newBook.setBookCardNumber(0);
        QDialog::accept();
    }
}
