#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QDate>


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

    QString mesaj;
    QDate data;

    void setCalDate(QDate d);

    void setText(QString s);


private slots:
    void on_buttonBox_accepted();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
