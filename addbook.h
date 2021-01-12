#ifndef ADDBOOK_H
#define ADDBOOK_H

#include <QDialog>
#include "book.h"

namespace Ui {
class AddBook;
}

class AddBook : public QDialog
{
    Q_OBJECT

public:
    explicit AddBook(QWidget *parent = nullptr);
    ~AddBook();

    const Book &getBook() const;

private:
    Ui::AddBook *ui;
    Book newBook;

public slots:
    void accept();
    bool isNameExists(const QString &name);
};

#endif // ADDBOOK_H
