#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "book.h"
#include "user.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(User &user, QWidget *parent = nullptr);
    ~MainWindow();

    const QList<Book> &booksList() const;
    const QList<User> &usersList() const;

public slots:
    void giftBook();

private slots:

    void onManageUsersClicked();
    void onManageBooksClicked();


private:
    Ui::MainWindow *ui;

    User &currentUser;
    QList<Book> currentBooksList;
    QList<User> currentUsersList;

    void loadUsers();
    void loadBooks();
};
#endif // MAINWINDOW_H
