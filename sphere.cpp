#include "sphere.h"
#include <QMainWindow>
#include <QGraphicsScene>
#include <cstdlib>
#include <math.h>

Sphere::Sphere()
{

}

Sphere::Sphere(QPoint coord1, QPoint size1)
{
    coord = coord1;
    step  = calcStep();
    size = size1;
    color = calcColor();
    brush = 2;
}

QPoint Sphere::calcStep()
{
    return QPoint((((rand() % 10) - 5) + 1), (((rand() % 10) - 5) + 1));
}

void Sphere::flipTan(float tan)
{
    float deg = tan * 180 / M_PI;
    step.setX(deg / 20);
    step.setY(deg / 20);
}

int Sphere::calcColor()
{
    return (rand() % 16);
}

void Sphere::wait()
{
    waitNum = 5;
}

void Sphere::move()
{
    if(0 == waitNum) {
        coord += step;
        if(collisionX()) flipX();
        if(collisionY()) flipY();
    }else{
        waitNum--;
    }
}

QPoint Sphere::randomCoord() {
   return QPoint((rand() % size.x()), (rand() % size.y()));
}

bool Sphere::collisionX()
{
    return ((coord.x() - rad) < 0 || (coord.x() + rad) > size.x());
}

bool Sphere::collisionY()
{
    return ((coord.y() - rad) < 0 || (coord.y() + rad) > size.y());
}

void Sphere::flipX()
{
    step.setX(step.x() * -1);
}

void Sphere::flipY()
{
    step.setY(step.y() * -1);
}
