#ifndef CIRCLE_H
#define CIRCLE_H

#include <QGraphicsScene>
#include "sphere.h"

/** @brief inherits from Sphere and changes the brush
 */
class Circle : public Sphere
{
    public:
        Circle(QPoint coord1, QPoint size1);
};

#endif // CIRCLE_H
