#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>
#include <QStringList>
#include <QCalendarWidget>
#include <calendar.h>
#include "todoitem.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();



private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();


    void on_listWidget_doubleClicked(const QModelIndex &index);

private:
    QVector<QDate> Daysv;
    QTableView *view;
    Calendar *c;
    QStringList List;
    Ui::MainWindow *ui;
    QStringListModel *model;
    QString s;
    QString text;
    QVector<todoitem> items;

};


#endif // MAINWINDOW_H
