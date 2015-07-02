#include "wolf.h"

Wolf::Wolf(QPoint size1)
{
    step  = calcStep();
    size  = size1;
    coord = randomCoord();
    color = 12;
    brush = 1;
}

Wolf::~Wolf()
{

}

