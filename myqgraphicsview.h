#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QMouseEvent>
#include "sphere.h"

using namespace std;

/** @brief extends QGraphicsView in order to listen to mouse Click event
 *
 */
class MyQGraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit MyQGraphicsView(QWidget *parent = 0);

private:
    QGraphicsScene * scene;
    /** @brief has all the balls
     */
    vector<Sphere*> sphere;
    /** firework size
    */
    int sphereSize = 50;
    /** @brief prints an ellipse
     *
     *  @param x coord
     *  @param y coord
     *  @param rad radius
     *  @param color Qt color int
     *  @param brush Qt brush int
     *  @return Void.
     */
    void printSphere(int x, int y, double rad, int color, int brush);
    /** @brief initializes Firework
     *
     *  @param coord coord
     *  @return Void.
     */
    void initFirework(QPoint coord);

    /** @brief size of the window
     */
    QPoint size = QPoint(500, 500);

protected:
    /** @brief printing happens here
     *  @return Void.
     */
    void timerEvent(QTimerEvent *event);

    /** @brief makes an new dot or circle depending on the i parameter
     *  @param i deciding factor
     *  @param coord coord
     *  @return Sphere pointer.
     */
    Sphere* newSpehere(int i, QPoint coord);

signals:

public slots:
    /** @brief init Firework and Tennisball
     *  @return Void.
     */
    void mousePressEvent(QMouseEvent * e);
};
