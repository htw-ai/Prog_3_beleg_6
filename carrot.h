#ifndef CARROT_H
#define CARROT_H
#include "sphere.h"

class Carrot : public Sphere
{
public:
    Carrot(QPoint size1);
    ~Carrot();
    double getType() { return CARROT; };
};

#endif // CARROT_H
