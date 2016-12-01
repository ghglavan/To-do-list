#-------------------------------------------------
#
# Project created by QtCreator 2016-11-15T18:27:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = todolist
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    calendar.cpp \
    todoitem.cpp \
    dialog.cpp

HEADERS  += mainwindow.h \
    calendar.h \
    todoitem.h \
    dialog.h

FORMS    += mainwindow.ui \
    dialog.ui

DISTFILES += \
    list.txt
