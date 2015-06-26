#ifndef SPHERE_H
#define SPHERE_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <cstdlib>

class Sphere
{
public:
    Sphere(QPoint coord1, QPoint size1);
    Sphere();
    /** @brief moves sphere inside the provided size
     *
     * @return void
     */
    void move();

    // attr readers
    double getX() { return coord.x(); };
    double getY() { return coord.y(); };
    double getRad() { return rad; };
    double getColor() { return color; };
    double getBrush() { return brush; };
protected:
    QPoint coord;
    QPoint step;
    QPoint size;
    int color, brush;
    double rad = 3.0;
    /** @brief checks if sphere collided with the X boudry of its world
     *
     * @return bool
     */
    bool collisionX();
    /** @brief checks if sphere collided with the Y boudry of its world
     *
     * @return bool
     */
    bool collisionY();
    /** @brief flips the step direction on x
     *
     * @return void
     */
    virtual void flipX();
    /** @brief flips the step direction on y
     *
     * @return void
     */
    virtual void flipY();

    /** @brief calculates random step
     *
     * @return QPoint
     */
    QPoint calcStep();
    /** @brief calculates random color
     *
     * @return int
     */
    int calcColor();
};


#endif // SPHERE_H
