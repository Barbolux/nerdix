#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "dialogo.h"
#include <QQmlContext>
#include <dialogo.cpp>



using namespace std;

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QQmlContext *contexto = engine.rootContext();
    Dialogo di; // essa classe deve herdar Qtobject para existirem as formas
    contexto-> setContextProperty ("conversa", &di);//endereco de di (name que vai ser usado para acessar o objeto, endereco)



    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    return app.exec();
}
