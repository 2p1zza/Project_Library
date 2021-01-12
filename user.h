#ifndef USER_H
#define USER_H

#include <QString>
#include <QDataStream>
#include <QMap>

class User
{
public:
    enum Status {Admin, Librarian, Reader};

    User();

    User(const Status &status, const QString &login, const QString &password,
         const QString &name, const QString &patronymic, const QString &surname,
         const QString &homeAdress, const int &number);

    const Status &status() const;
    const QString &login() const;
    const QString &password() const;
    const QString &name() const;
    const QString &patronymic() const;
    const QString &surname() const;
    const QString &homeAdress() const;
    const int &number() const;
    const QString statusString() const;
    static QMap<Status, QString> getListStatus();

    void setData(const Status &status, const QString &login, const QString &password,
                 const QString &name, const QString &patronymic, const QString &surname,
                 const QString &homeAdress, const int &number);
    void setStatus(const Status &status);
    void setLogin(const QString &login);
    void setPassword(const QString &password);
    void setNumber(const int &number);

private:
    Status userStatus;
    QString userLogin;
    QString userPassword;
    QString userName;
    QString userPatronymic;
    QString userSurname;
    QString userHomeAdress;
    int readerNumber;
};

inline QDataStream &operator<< (QDataStream &ost, const User &user)
{
    ost << user.status() << user.login() << user.password()
        << user.name() << user.patronymic() << user.surname()
        << user.homeAdress() << user.number();
    return ost;
}

inline QDataStream &operator>> (QDataStream &ist, User &user)
{
    int status;
    QString login;
    QString password;
    QString name;
    QString patronymic;
    QString surname;
    QString homeAdress;
    int readerNumber;

    ist >> status >> login >> password
        >> name >> patronymic >> surname
        >> homeAdress >> readerNumber;

    user.setData(User::Status(status), login, password,
                 name, patronymic, surname,
                 homeAdress, readerNumber);

    return ist;
}

#endif // USER_H
