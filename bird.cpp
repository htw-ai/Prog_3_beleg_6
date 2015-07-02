#include "bird.h"

Bird::Bird(QPoint size1)
{
    step  = calcStep();
    size  = size1;
    coord = randomCoord();
    color = 13;
    brush = 1;
}

Bird::~Bird()
{

}

