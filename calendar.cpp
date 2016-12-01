#include "calendar.h"

Calendar::Calendar(QWidget* parent)
    : QCalendarWidget(parent)
{

}

Calendar::~Calendar(){}
void Calendar::paintCell(QPainter *painter,const QRect &rect,const QDate &date){
    QPen p(Qt::black);
    QPen p1(Qt::red);

    painter->save();
    painter->setPen(p);
    painter->drawText(rect.center(),QString::number(date.day()+123));


    painter->setPen(p1);
    painter->drawPoint(rect.topLeft());
    painter->restore();

    update();
}
