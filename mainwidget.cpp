#include "mainwidget.h"

#include "Config.h"
#include "mainwindow.h"
#include<registration.h>
#include <authorization.h>
#include <QFile>
#include <QVBoxLayout>
#include <QDebug>
#include "user.h"
#include "readerwindow.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent),
      currentWidget(nullptr)
{
    setWindowTitle(Config::nameApplication);

    if (!QFile(Config::Usersbin).exists()){
        currentWidget = new Registration(Registration::Admin, this);
        connect(currentWidget, SIGNAL(openAuthorization()),
        this, SLOT(slotOpenAuthorization()));
    }
    else{
        currentWidget = new Authorization(this);
        connect(currentWidget, SIGNAL(openRegistration()),
                this, SLOT(slotOpenRegistration()));
        connect(currentWidget, SIGNAL(succesfulEntry(User*)),
                this, SLOT(slotOpenMainWindow(User*)));
        connect(currentWidget, SIGNAL(succesfulReaderEntry(User*)),
                this, SLOT(slotOpenReaderWindow(User*)));
    }

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setMargin(0);
    layout->addWidget(currentWidget);
    setLayout(layout);
}

MainWidget::~MainWidget()
{
    delete currentWidget;
}

void MainWidget::slotOpenAuthorization()
{
    delete currentWidget;
    currentWidget = new Authorization(this);
    connect(currentWidget, SIGNAL(openRegistration()),
            this, SLOT(slotOpenRegistration()));
    connect(currentWidget, SIGNAL(succesfulEntry(User*)),
            this, SLOT(slotOpenMainWindow(User*)));

    layout()->addWidget(currentWidget);
}

void MainWidget::slotOpenRegistration()
{
    delete currentWidget;
    currentWidget = new Registration(Registration::Reader, this);
    connect(currentWidget, SIGNAL(openAuthorization()),
            this, SLOT(slotOpenAuthorization()));
    layout()->addWidget(currentWidget);
}

void MainWidget::slotOpenMainWindow(User *user)
{
    delete currentWidget;
    currentWidget = new MainWindow(*user, this);

    this->resize(800, 600);
    layout()->addWidget(currentWidget);
}

void MainWidget::slotOpenReaderWindow(User *user){
    delete currentWidget;
    currentWidget = new ReaderWindow(*user, this);

    this->resize(800, 600);
    layout()->addWidget(currentWidget);
}
