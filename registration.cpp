#include "registration.h"
#include "ui_registration.h"
#include "Config.h"
#include "user.h"

#include <QFile>
#include <QDataStream>

Registration::Registration(TypeRegistration typeReg, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Registration)
{
    ui->setupUi(this);

    if (typeReg == Admin){
        ui->errorLable->setText("Регистрация Админа!");
        ui->enterButton->hide();
    }
    regType = typeReg;


    connect(ui->enterButton, SIGNAL(clicked()),
           this, SIGNAL(openAuthorization()));

}

Registration::~Registration()
{
    delete ui;
}

bool Registration::isLoginExists(const QString &login){
    amount = 0;
    QFile file(Config::Usersbin);
    bool registered = false;
    if (file.exists()){
        if (!file.open(QIODevice::ReadOnly)){
            ui->errorLable->setText("Ошибка: чтение файла невозможно!");
            return registered;
        }

        QDataStream ist(&file);

        while (!ist.atEnd()){
            //считывание данных
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

void Registration::on_accept_clicked()
{
    QRegExp nameExp ("[А-Я]+[а-я]+");
    QRegExp loginExp ("[A-Z]+[a-z]+");

    ui->errorLable->clear();
    const QString login = ui->loginLineEdit->text();
    const QString password = ui->passwordLineEdit->text();
    const QString name = ui->nameLineEdit->text();
    const QString surname = ui->surnameLineEdit->text();
    const QString patronymic = ui->patronymicLineEdit->text();
    const QString homeAdress = ui->homeLineEdit->text();



    if (login.isEmpty() || password.isEmpty() || name.isEmpty() ||
        surname.isEmpty() || patronymic.isEmpty() || homeAdress.isEmpty()){
        ui->errorLable->setText("Ошибка: заполните все поля!");
    }
    else if (isLoginExists(login)){
        if (ui->errorLable->text().isEmpty())
            ui->errorLable->setText("Ошибка: данное имя пользователя занято!");
    }
    else if (!login.contains(loginExp))
    {
        ui->errorLable->setText("Ошибка: имя пользователя введено неверно!");
    }
    else if (isLoginExists(login))
    {
        if (ui->errorLable->text().isEmpty())
            ui->errorLable->setText("Ошибка: данное имя пользователя уже существует!");
    }
    else if (password.size() < 6 || password.size() > 15)
    {
        ui->errorLable->setText("Ошибка: пароль должен содержать от 6 до 15 символов!");
    }
    else if(!name.contains(nameExp)){
        ui->errorLable->setText("Ошибка: имя введено неверно!");
    }
    else if(!surname.contains(nameExp)){
        ui->errorLable->setText("Ошибка: фамилия введена неверно!");
    }
    else if(!patronymic.contains(nameExp)){
        ui->errorLable->setText("Ошибка: отчество введено неверно!");
    }
    else
    {
        amount++;
        User user(regType == Admin ? User::Admin : User::Reader, login, password,
                  name, patronymic, surname, homeAdress, amount);

        if(regType == Admin){
            user.setNumber(0);
        }

        QFile file(Config::Usersbin);
        file.open(QIODevice::Append);
        QDataStream ost(&file);
        ost << user;

        emit openAuthorization();
    }
}
