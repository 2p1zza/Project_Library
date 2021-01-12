#ifndef READERWINDOW_H
#define READERWINDOW_H

#include <QWidget>
#include "book.h"
#include "user.h"

namespace Ui {
class ReaderWindow;
}

class ReaderWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ReaderWindow(User &user, QWidget *parent = nullptr);
    ~ReaderWindow();

    const QList<Book> &booksList() const;

public slots:
    void returnBook();
    void takeBook();


private:
    Ui::ReaderWindow *ui;

    User &currentUser;
    QList<Book> currentBooksList;

    void loadBooks();
};

#endif // READERWINDOW_H
