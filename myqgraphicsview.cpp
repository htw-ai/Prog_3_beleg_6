#include "myqgraphicsview.h"
#include "bunny.h"
#include "carrot.h"
#include "wolf.h"
#include "bird.h"
#include "stone.h"
#include <QPointF>
#include <QPoint>

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
    sphere.clear();
//    initFirework(e->pos());
//    change direction of birds and bunnies
}

void MyQGraphicsView::timerEvent(QTimerEvent *event)
{
    scene->clear();
    for(int i = 0; i < sphere.size(); i++)
    {
        printSphere(sphere[i]->getX(), sphere[i]->getY(), sphere[i]->getRad(), sphere[i]->getColor(), sphere[i]->getBrush());
        sphere[i]->move();
    }
}

void MyQGraphicsView::initFirework(QPoint coord)
{
    for(int i = 0; i < sphereSize; i++)
        sphere.push_back(newSpehere(i, coord));
}

Sphere* MyQGraphicsView::newSpehere(int i, QPoint coord)
{
    if(i % 3)
        return new Carrot(size);
    else if(i % 5)
        return new Bunny(size);
    else if(i % 7)
        return new Wolf(size);
    else if(i % 9)
        return new Bird(size);
    else
        return new Stone(size);
}

void MyQGraphicsView::printSphere(int x, int y, double rad, int color, int brush)
{
    scene->addEllipse(x, y, rad , rad, QPen((Qt::GlobalColor) color), QBrush((Qt::BrushStyle)brush));
}
