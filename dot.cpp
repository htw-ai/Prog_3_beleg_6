#include "dot.h"

Dot::Dot(QPoint coord1, QPoint size1)
{
    coord = coord1;
    step  = calcStep();
    size = size1;
    color = calcColor();
    brush = 1;
}
