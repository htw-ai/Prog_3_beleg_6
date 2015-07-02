#include "bunny.h"

Bunny::Bunny(QPoint size1)
{
    step  = calcStep();
    size  = size1;
    coord = randomCoord();
    color = 5;
    brush = 1;
}

Bunny::~Bunny()
{

}

