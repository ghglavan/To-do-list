#ifndef CALENDAR_H
#define CALENDAR_H
#include <QCalendarWidget>
#include <QPainter>
#include <QTableView>

class Calendar : public QCalendarWidget
{
public:
    Calendar(QWidget* =0);
    virtual ~Calendar();
protected:
    void paintCell(QPainter *painter,const QRect &rect,const QDate &date);

};

#endif // CALENDAR_H
