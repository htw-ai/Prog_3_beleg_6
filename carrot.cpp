#include "carrot.h"

Carrot::Carrot(QPoint size1)
{
    step  = QPoint(0,0);
    size  = size1;
    coord = randomCoord();
    color = 7;
    brush = 1;
}

Carrot::~Carrot()
{

}

