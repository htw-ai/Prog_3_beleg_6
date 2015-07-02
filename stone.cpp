#include "stone.h"

Stone::Stone(QPoint size1)
{
    step  = QPoint(0,0);
    size  = size1;
    coord = randomCoord();
    color = 1;
    brush = 1;
}

Stone::~Stone()
{

}

