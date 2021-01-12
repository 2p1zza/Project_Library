#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QWidget>

namespace Ui {
class Registration;
}

class Registration : public QWidget
{
    Q_OBJECT

public:
    enum TypeRegistration {Admin, Librarian, Reader};

    explicit Registration(TypeRegistration typeReg, QWidget *parent = nullptr);
    ~Registration();

private:
    Ui::Registration *ui;
    TypeRegistration regType;
    int amount = 0;
    bool isLoginExists(const QString &login);

signals:
    void openAuthorization();
private slots:
    void on_accept_clicked();
};

#endif // REGISTRATION_H
