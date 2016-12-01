#include "dialog.h"
#include "ui_dialog.h"


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    data = QDate::currentDate();

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_buttonBox_accepted()
{
    data = ui->calendarWidget->selectedDate();
    mesaj = ui->lineEdit->text();
}

void Dialog::setCalDate(QDate d){
    ui->calendarWidget->setSelectedDate(d);
}

void Dialog::setText(QString s){
    ui->lineEdit->setText(s);
}
