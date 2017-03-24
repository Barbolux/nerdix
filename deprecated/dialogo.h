#ifndef DIALOGO_H
#define DIALOGO_H
#include<QObject>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "dialogo.h"
#include <QQmlContext>

class Dialogo : public QObject
{
     DIALOGO_H

public:

Dialogo ();


public slots:
void conversa();


};

#endif // DIALOGO_H

