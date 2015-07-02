#ifndef STONE_H
#define STONE_H

#include "sphere.h"

class Stone : public Sphere
{
public:
    Stone(QPoint size1);
    ~Stone();
};

#endif // STONE_H
