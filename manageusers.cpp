#include "manageusers.h"
#include "ui_manageusers.h"

#include "Config.h"
#include "adduser.h"

#include <QTableWidgetItem>
#include <QFile>
#include <QDataStream>
#include <QMessageBox>
#include <QDebug>

ManageUsers::ManageUsers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManageUsers)
{
    ui->setupUi(this);

    QFile file(Config::Usersbin);
    if (file.open(QIODevice::ReadOnly)) {
        QDataStream ist(&file);
        while (!ist.atEnd()) {
            User user;
            ist >> user;
            m_listUsers.append(user);
        }
    }

    int row = 0;
    foreach (const User &user, m_listUsers) {
            QTableWidgetItem *item_login = new QTableWidgetItem(user.login());
            QTableWidgetItem *item_name = new QTableWidgetItem(user.name());
            QTableWidgetItem *item_surname  = new QTableWidgetItem(user.surname());
            QTableWidgetItem *item_patronymic  = new QTableWidgetItem(user.patronymic());
            QTableWidgetItem *item_home = new QTableWidgetItem(user.homeAdress());
            QTableWidgetItem *item_status  = new QTableWidgetItem(user.statusString());

            ui->usersTable->insertRow(row);// Вставка строки в таблицу
            ui->usersTable->setItem(row, 0, item_login);
            ui->usersTable->setItem(row, 1, item_name);
            ui->usersTable->setItem(row, 2, item_surname);
            ui->usersTable->setItem(row, 3, item_patronymic);
            ui->usersTable->setItem(row, 4, item_home);
            ui->usersTable->setItem(row, 5, item_status);
            row++;
    }
}

ManageUsers::~ManageUsers()
{
    delete ui;
}

void ManageUsers::onDeleteClicked()
{
    int currentRow = ui->usersTable->currentRow();
    if (currentRow != -1)
    {
        const QString login = ui->usersTable->item(currentRow, 0)->text();
        const QString status = ui->usersTable->item(currentRow, 5)->text();

        if (status == "Администратор" && countAdmins() <= 1)
        {
            QMessageBox::warning(this, windowTitle(),
                                 "Ошибка: нельзя удалить последнего Администратора!");
            return;
        }
        ui->usersTable->removeRow(currentRow);

        QFile read_file(Config::Usersbin);
        if (read_file.open(QIODevice::ReadOnly))
        {
            //C:\\Kursach\\Library\\Library\\//
            QFile write_file("buf_file_users");
            write_file.open(QIODevice::WriteOnly);

            QDataStream read_ist(&read_file);
            QDataStream write_ist(&write_file);

            while (!read_ist.atEnd())
            {
                User user;
                read_ist >> user;

                if (user.login() != login)
                {
                    write_ist << user;
                }
            }

            read_file.close();
            read_file.remove();
            write_file.close();
            write_file.rename(Config::Usersbin);
        }
    }
    else
    {
        QMessageBox::warning(this, windowTitle(),
                             "Ошибка: Необходимо выбрать пользователя!");
    }
}

void ManageUsers::onAddClicked()
{

    addUser dialog(this);
    dialog.setWindowTitle(windowTitle());

    if (dialog.exec() == QDialog::Accepted)
    {
        const User &user = dialog.getUser();


        QFile file(Config::Usersbin);
        file.open(QIODevice::Append);
        QDataStream ost(&file);
        ost << user;


        QTableWidgetItem *item_login = new QTableWidgetItem(user.login());
        QTableWidgetItem *item_name = new QTableWidgetItem(user.name());
        QTableWidgetItem *item_surname  = new QTableWidgetItem(user.surname());
        QTableWidgetItem *item_patronymic  = new QTableWidgetItem(user.patronymic());
        QTableWidgetItem *item_home = new QTableWidgetItem(user.homeAdress());
        QTableWidgetItem *item_status  = new QTableWidgetItem(user.statusString());

        int row = ui->usersTable->rowCount();
        ui->usersTable->insertRow(row);
        ui->usersTable->setItem(row, 0, item_login);
        ui->usersTable->setItem(row, 1, item_name);
        ui->usersTable->setItem(row, 2, item_surname);
        ui->usersTable->setItem(row, 3, item_patronymic);
        ui->usersTable->setItem(row, 4, item_home);
        ui->usersTable->setItem(row, 5, item_status);
    }
}

int ManageUsers::countAdmins() const
{
    QFile file(Config::Usersbin);
    if (file.open(QIODevice::ReadOnly)) {
        QDataStream ist(&file);

        int count = 0;
        while (!ist.atEnd()) {
            User user;
            ist >> user;
            if (user.status() == User::Admin) count++;
        }
        return count;
    }
    else return 0;
}
