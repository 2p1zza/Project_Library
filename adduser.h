#ifndef ADDUSER_H
#define ADDUSER_H

#include <QDialog>
#include "user.h"


namespace Ui {
class addUser;
}

class addUser : public QDialog
{
    Q_OBJECT

public:
    explicit addUser(QWidget *parent = nullptr);
    ~addUser();
    const User &getUser() const;

private:
    Ui::addUser *ui;
    User newUser;
    int amount = 0;

public slots:
    void accept();
    bool isLoginExists(const QString &login);
};

#endif // ADDUSER_H
