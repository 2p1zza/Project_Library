#ifndef MANAGEUSERS_H
#define MANAGEUSERS_H

#include <QDialog>
#include "user.h"

namespace Ui {
class ManageUsers;
}

class ManageUsers : public QDialog
{
    Q_OBJECT

public:
    explicit ManageUsers(QWidget *parent = nullptr);
    ~ManageUsers();

private slots:
    void onDeleteClicked();
    void onAddClicked();

private:
    Ui::ManageUsers *ui;

    QList<User> m_listUsers;
    int countAdmins() const;
};

#endif // MANAGEUSERS_H
