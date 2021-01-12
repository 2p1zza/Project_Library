#ifndef MAINWIDJET_H
#define MAINWIDJET_H

#include <QWidget>
class User;

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

private:
    QWidget *currentWidget; //Текущий виджет

private slots:
    void slotOpenAuthorization();
    void slotOpenRegistration();
    void slotOpenMainWindow(User*);
    void slotOpenReaderWindow(User*);
};
#endif // MAINWIDGET_H
