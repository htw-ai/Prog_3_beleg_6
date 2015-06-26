#include "myqgraphicsview.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

     MyQGraphicsView view;
     view.show();

     return a.exec();
}
