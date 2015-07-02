#ifndef WOLF_H
#define WOLF_H

#include "sphere.h"

class Wolf : public Sphere
{
public:
    Wolf(QPoint size1);
    ~Wolf();
    double getType() { return WOLF; };
};

#endif // WOLF_H
