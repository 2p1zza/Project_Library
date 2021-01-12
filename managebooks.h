#ifndef MANAGEBOOKS_H
#define MANAGEBOOKS_H

#include <QDialog>
#include "book.h"

namespace Ui {
class ManageBooks;
}

class ManageBooks : public QDialog
{
    Q_OBJECT

public:
    explicit ManageBooks(QWidget *parent = nullptr);
    ~ManageBooks();

private slots:
    void onDeleteClicked();
    void onAddClicked();

private:
    Ui::ManageBooks *ui;
    QList<Book> booksList;
};

#endif // MANAGEBOOKS_H
