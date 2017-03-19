#include <QApplication>
#include <QGraphicsScene>
#include "myrect.h"
//#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <iostream>
#include<myrect.cpp>


using namespace std;



int main (int argc, char *argv[]){

   QApplication a(argc, argv);

   //Cena do jogo
   QGraphicsScene *cena = new QGraphicsScene ();

   //Item da minha scena
   myrec *rect = new myrect();
   rect->setRect(0,0,100,100);
   cena->addItem(rect);
                                    //foco nos objetos
   rect->setFlag(QGraphicsItem::ItemIsFocusable);//FOCO de acao
   rect->setFocus();//permite receber o evento

   /*QGraphicsRectItem *rect2 = new QGraphicsRectItem();
   rect2->setRect(105,0,100,100);

   QGraphicsRectItem *rect3 = new QGraphicsRectItem();
   rect3->setRect(210,0,100,100);

   QGraphicsRectItem *rect4 = new QGraphicsRectItem();
   rect4->setRect(0,105,100,100);

   QGraphicsRectItem *rect5 = new QGraphicsRectItem();
   rect5->setRect(105,105,100,100);

   QGraphicsRectItem *rect6 = new QGraphicsRectItem();
   rect6->setRect(210,105,100,100);

   QGraphicsRectItem *rect7 = new QGraphicsRectItem();
   rect7->setRect(0,210,100,100);

   QGraphicsRectItem *rect8 = new QGraphicsRectItem();
   rect8->setRect(105,210,100,100);

   QGraphicsRectItem *rect9 = new QGraphicsRectItem();
   rect9->setRect(210,210,100,100);


   *//*   cena->addItem(rect2);   cena->addItem(rect3);
   cena->addItem(rect4);   cena->addItem(rect5);   cena->addItem(rect6);
   cena->addItem(rect7);   cena->addItem(rect8);   cena->addItem(rect9);
*/
   //Visao geral
   QGraphicsView * visao = new QGraphicsView();
   visao->setScene(cena);

   //mostrar a visao
   visao->show();

return a.exec();
}
