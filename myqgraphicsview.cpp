#include "myqgraphicsview.h"
#include "bunny.h"
#include "carrot.h"
#include "wolf.h"
#include "bird.h"
#include "stone.h"
#include <QPointF>
#include <QPoint>

#include <math.h>
#include <iostream>
using namespace std;

MyQGraphicsView::MyQGraphicsView(QWidget *parent) :
    QGraphicsView(parent)
{
    scene = new QGraphicsScene();
    initFirework(QPoint(250, 200));
    this->setSceneRect(0, 0, size.x(), size.y());
    this->setScene(scene);
    startTimer(10);
}

void MyQGraphicsView::mousePressEvent(QMouseEvent * e)
{
    float tan;
    for(int i = 0; i < sphere.size(); i++)
    {
        if(sphere[i]->getType() == BIRD || sphere[i]->getType() == BUNNY || sphere[i]->getType() == WOLF)
        {
            tan = atan2(sphere[i]->getY() - e->pos().y(), sphere[i]->getX() - e->pos().x());
            sphere[i]->flipTan(tan);
        }
    }
}

void MyQGraphicsView::timerEvent(QTimerEvent *event)
{
    scene->clear();
    int i, j;
    for(i = 0; i < sphere.size(); i++)
    {
        for(j = i + 1; j < sphere.size(); j++)
        {
            if((sphere[i]->getX() - (sphere[i]->getRad() * 2)) < sphere[j]->getX() &&
               (sphere[i]->getX() + (sphere[i]->getRad() * 2)) > sphere[j]->getX() &&
               (sphere[i]->getY() - (sphere[i]->getRad() * 2)) < sphere[j]->getY() &&
               (sphere[i]->getY() + (sphere[i]->getRad() * 2)) > sphere[j]->getY())
            {
                if(sphere[i]->getType() == WOLF && sphere[j]->getType() == BUNNY) {
                    sphere.erase(sphere.begin() + j);
                    sphere[i]->wait();
                } else if(sphere[i]->getType() == BUNNY && sphere[j]->getType() == CARROT) {
                    sphere.erase(sphere.begin() + j);
                    sphere[i]->wait();
                } else if(sphere[i]->getType() == STONE && (sphere[j]->getType() == BUNNY || sphere[j]->getType() == WOLF)){
                    if((sphere[j]->getStep().x() ^ -1) > (sphere[j]->getStep().y() ^ -1)){
                        sphere[j]->flipX();
                    }else{
                        sphere[j]->flipY();
                    }
                }
//                if(sphere[i]->getType() == BUNNY && sphere[j]->getType() == BUNNY)
//                    sphere.push_back(new Bunny(size));
            }
        }
    }

    for(i = 0; i < sphere.size(); i++)
    {
        printSphere(sphere[i]->getX(), sphere[i]->getY(), sphere[i]->getRad(), sphere[i]->getColor(), sphere[i]->getBrush());
        sphere[i]->move();
    }
}

void MyQGraphicsView::initFirework(QPoint coord)
{
//    for(int i = 0; i < sphereSize; i++)
//        sphere.push_back(newSpehere(i, coord));
    for(int i = 0; i < sphereSize; i++) {

            sphere.push_back(new Carrot(size));
            if(i % 2) {
                sphere.push_back(new Wolf(size));
                sphere.push_back(new Bunny(size));
            }
            if(i % 3)
                sphere.push_back(new Bird(size));
            sphere.push_back(new Stone(size));
    }
}

Sphere* MyQGraphicsView::newSpehere(int i, QPoint coord)
{
    if(i % 3)
        return new Carrot(size);
    else if(i % 5)
        return new Wolf(size);
    else if(i % 7)
        return new Bunny(size);
    else if(i % 9)
        return new Bird(size);
    else
        return new Stone(size);
}

void MyQGraphicsView::printSphere(int x, int y, double rad, int color, int brush)
{
    scene->addEllipse(x, y, rad , rad, QPen((Qt::GlobalColor) color), QBrush((Qt::BrushStyle)brush));
}
