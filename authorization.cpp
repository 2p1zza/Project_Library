#include "authorization.h"
#include "ui_authorization.h"

#include "Config.h"
#include "user.h"

#include <QFile>
#include <QDataStream>

Authorization::Authorization(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Authorization)
{
    ui->setupUi(this);

    connect(ui->regButton, SIGNAL(clicked()),
            this, SIGNAL(openRegistration()));
}

Authorization::~Authorization()
{
    delete ui;
}

User *Authorization::checkUser(const QString &login, const QString &password){
    QFile file(Config::Usersbin);
    if (file.exists()){
        User *user = nullptr;
        if (!file.open(QIODevice::ReadOnly)){
             ui->errorLabel->setText("Ошибка: открытие файла невозможно!");
            return nullptr;
        }

        QDataStream ist(&file);

        while (!ist.atEnd()){

            User bufferUser;
            ist >> bufferUser;
            if (bufferUser.login() == login && bufferUser.password() == password){

                user = new User(bufferUser);
                return user;
            }
        }

        return user;
    }
    else
        return nullptr;
}

void Authorization::on_entry_clicked(){
    QRegExp loginExp ("[A-z]+[a-z]+");

    ui->errorLabel->clear();

    const QString login = ui->loginLineEdit->text();
    const QString password = ui->passordLineEdit->text();

    if (login.isEmpty() || password.isEmpty()){
        ui->errorLabel->setText("Ошибка: заполните все поля!");
    }
    else if (!login.contains(loginExp)){
        ui->errorLabel->setText("Ошибка: имя пользователя введено неверно!");
    }
    else if (password.size() < 5 || password.size() > 15){
        ui->errorLabel->setText("Ошибка: пароль должен содержать от 5 до 15 символов!");
    }
    else{
        User *user = checkUser(login, password);

        if (!checkUser(login, password)) ui->errorLabel->setText("Ошибка: 11!");
        if (user == nullptr){
            ui->errorLabel->setText("Ошибка: неправильный логин или пароль!");
        }
        else if(user->status() == User::Reader){
            emit succesfulReaderEntry(user);
        }
        else{
            emit succesfulEntry(user);
        }
    }
}
