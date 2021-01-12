#ifndef AUTHORIZATION_H
#define AUTHORIZATION_H

#include <QWidget>

class User;

namespace Ui {
class Authorization;
}

class Authorization : public QWidget
{
    Q_OBJECT

public:
    explicit Authorization(QWidget *parent = nullptr);
    ~Authorization();

private:
    Ui::Authorization *ui;
    User *checkUser(const QString &login, const QString &password);

signals:
    void openRegistration(); //Сигнал об необходимости открытия окна регистрации
    void succesfulEntry(User*);
    void succesfulReaderEntry(User*);

private slots:
    void on_entry_clicked();
};

#endif // AUTHORIZATION_H
