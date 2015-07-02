#ifndef BUNNY_H
#define BUNNY_H

#include "sphere.h"

class Bunny : public Sphere
{
public:
    Bunny(QPoint size1);
    ~Bunny();
    double getType() { return BUNNY; };
};

#endif // BUNNY_H
