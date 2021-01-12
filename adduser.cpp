#include "adduser.h"
#include "ui_adduser.h"
#include "Config.h"

#include <QFile>
#include <QDataStream>

addUser::addUser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addUser)
{
    ui->setupUi(this);
}

addUser::~addUser()
{
    delete ui;
}

const User &addUser::getUser() const{
    return newUser;
}

bool addUser::isLoginExists(const QString &login){
    amount = 0;
    QFile file(Config::Usersbin);
    bool registered = false;
    if (file.exists()){
        if (!file.open(QIODevice::ReadOnly)){
            return registered;
        }

        QDataStream ist(&file);

        while (!ist.atEnd()){
            User buf_user;
            ist >> buf_user;
            if((buf_user.status() != User::Admin) && (buf_user.status() != User::Librarian)){
                amount++;
            }
            if (buf_user.login() == login){
                registered = true;
            }
        }
        return registered;
    }
    else
        return registered;
}

void addUser::accept()
{
    QRegExp nameExp ("[А-Я]+[а-я]+");
    QRegExp loginExp ("[A-z]+[a-z]+");


    ui->errorLabel->clear();
    const QString login = ui->loginLineEdit->text();
    const QString password = ui->lineEpasswordLineEdit->text();
    const QString name = ui->nameLineEdit->text();
    const QString surname = ui->surnameLineEdit->text();
    const QString patronymic = ui->patronymicLineEdit->text();
    const QString homeAdress = ui->homeLineEdit->text();


    User::Status status = User::getListStatus().key(ui->comboBox->currentText());

    if (login.isEmpty() || password.isEmpty() || name.isEmpty() ||
            surname.isEmpty() || patronymic.isEmpty() || homeAdress.isEmpty())
    {
        ui->errorLabel->setText("Ошибка: необходимо заполнить все поля!");
    }
    else if (!login.contains(loginExp))
    {
        ui->errorLabel->setText("Ошибка: имя пользователя введено неверно!");
    }
    else if (isLoginExists(login))
    {
        if (ui->errorLabel->text().isEmpty())
            ui->errorLabel->setText("Ошибка: данное имя пользователя уже существует!");
    }
    else if (password.size() < 6 || password.size() > 15)
    {
        ui->errorLabel->setText("Ошибка: пароль должен содержать от 6 до 15 символов!");
    }
    else if(!name.contains(nameExp)){
        ui->errorLabel->setText("Ошибка: имя введено неверно!");
    }
    else if(!surname.contains(nameExp)){
        ui->errorLabel->setText("Ошибка: фамилия введена неверно!");
    }
    else if(!patronymic.contains(nameExp)){
        ui->errorLabel->setText("Ошибка: отчество введено неверно!");
    }
    else
    {
        amount++;
        newUser.setData(status, login, password, name, patronymic, surname, homeAdress, amount);
        if(status != User::Reader){
            newUser.setNumber(0);
        }
        QDialog::accept();
    }
}
