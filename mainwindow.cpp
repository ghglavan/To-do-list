#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QDateTime>
#include <QCalendarWidget>
#include <calendar.h>
#include "dialog.h"
#include <QListView>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QIcon i("/home/x2009/build-todolist-Desktop_Qt_5_7_0_GCC_64bit-Release/da.jpg");

    this->setWindowIcon(i);

    this->setWindowTitle("To Do List!");

        QFile file("/home/x2009/build-todolist-Desktop_Qt_5_7_0_GCC_64bit-Release/list.txt");


        //todo          !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        //http://doc.qt.io/qt-5/qtableview.html
        // change the tableview to a tabelview!!!!!!




        if(!file.exists() || !file.open(QIODevice::ReadOnly)){
            ui->label->setText("Eroare la deschiderea fisierului");
        }else{
            QTextStream in(&file);

            QString d;

            s = in.readLine();
            d = in.readLine();


            while(s != ""){
                todoitem t;
                t.subiect = s;
                t.data = QDate::fromString(d);
                items.push_back(t);

                int zile = QDate::currentDate().daysTo(t.data);

                if(zile >= -2){
                    ui->listWidget->addItem( s + ". Expira in " + QString::number(QDate::currentDate().daysTo(t.data)) + " zile.");
                    if(zile < 1){
                       ui->listWidget->item(ui->listWidget->count()-1)->setTextColor(Qt::red);
                    }else if(zile < 2){
                        ui->listWidget->item(ui->listWidget->count()-1)->setTextColor(Qt::green);
                    }else{
                        ui->listWidget->item(ui->listWidget->count()-1)->setTextColor(Qt::blue);

                    }

                }

                s = in.readLine();
                d = in.readLine();
            }

        }
        file.close();

        // Make data


        // Populate our model
        //model->setStringList(List);

        // Glue model and view together
        //ui->listWidget->setModel(model);


        // Add additional feature so that
        // we can manually modify the data in ListView
        // It may be triggered by hitting any key or double-click etc.

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    /*
    int row = model->rowCount();
    model->insertRows(row,1);
    QModelIndex index = model->index(row);
    ui->listView->setCurrentIndex(index);
    ui->listView->edit(index);
    */

    Dialog d;
    d.setWindowTitle("Add new item");
    d.setModal(true);
    int ret = d.exec();

    if(d.mesaj == "" || ret == 0)
        return;

    int zile = QDate::currentDate().daysTo(d.data);

    if(zile >= 0){
        ui->listWidget->addItem( d.mesaj + ". Expira in " + QString::number(QDate::currentDate().daysTo(d.data)) + " zile.");
        if(zile < 1){
           ui->listWidget->item(ui->listWidget->count()-1)->setTextColor(Qt::red);
        }else if(zile < 2){
            ui->listWidget->item(ui->listWidget->count()-1)->setTextColor(Qt::green);
        }else{
            ui->listWidget->item(ui->listWidget->count()-1)->setTextColor(Qt::blue);

        }

    }else{
        return ;
    }


    todoitem i;

    i.subiect = d.mesaj;
    i.data = d.data;

    items.push_back(i);

}

void MainWindow::on_pushButton_2_clicked()
{

    if(ui->listWidget->selectedItems().empty()){
        return ;
    }

    int row = ui->listWidget->currentRow() ;

    auto it = items.begin() + ui->listWidget->currentRow() ;

    items.erase(it);

    qDeleteAll(ui->listWidget->selectedItems());


    if(!ui->listWidget->selectedItems().empty())
        if(row == ui->listWidget->count()){
            ui->listWidget->item(row-1)->setSelected(false);
        }else{
            ui->listWidget->item(row)->setSelected(false);
        }



}

void MainWindow::on_pushButton_3_clicked()
{

    QFile f("/home/x2009/build-todolist-Desktop_Qt_5_7_0_GCC_64bit-Release/list.txt");
    if(!f.exists() || !f.open(QIODevice::WriteOnly | QIODevice::Truncate)){
        ui->label->setText("Eroare la deschiderea fisierului");
    }else{
        QTextStream out(&f);
        for(int i = 0; i < items.size(); i ++){
            out<< items[i].subiect << "\n" <<items[i].data.toString();
        }
    }
    f.close();

}


void MainWindow::on_listWidget_doubleClicked(const QModelIndex &index)
{

    QListWidgetItem *p = ui->listWidget->currentItem();

    Dialog d;
    d.setWindowTitle(p->text());
    d.setModal(true);
    d.setCalDate(items[index.row()].data);
    d.setText(items[index.row()].subiect);
    int ret = d.exec();

    if(d.mesaj == "" || ret == 0){
        p->setSelected(false);
        return;
    }

    //p->setText(d.mesaj + ". Expira in " + QString::number(QDate::currentDate().daysTo(d.data)) + " zile.");
    int zile = QDate::currentDate().daysTo(d.data);

    if(zile >= -2 && d.mesaj!= "" ){
        p->setText( d.mesaj + ". Expira in " + QString::number(QDate::currentDate().daysTo(d.data)) + " zile.");
        if(zile < 1){
           p->setTextColor(Qt::red);
        }else if(zile < 2){
           p->setTextColor(Qt::green);
        }else{
            p->setTextColor(Qt::blue);

        }
        items[index.row()].data = d.data;
        items[index.row()].subiect = d.mesaj;

    }

    p->setSelected(false);

}
