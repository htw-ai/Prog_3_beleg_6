#ifndef BIRD_H
#define BIRD_H

#include "sphere.h"

class Bird : public Sphere
{
public:
    Bird(QPoint size1);
    ~Bird();
    double getType() { return BIRD; };
};

#endif // BIRD_H
