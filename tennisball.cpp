#include "tennisball.h"

TennisBall::TennisBall(QPoint coord1, QPoint size1)
{
    coord = coord1;
    step  = calcStep();
    size = size1;
    color = 12;
    brush = 1;
}
