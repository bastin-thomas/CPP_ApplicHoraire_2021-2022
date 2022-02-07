#include "applichorairewindow.h"

#include <QApplication>

ApplicHoraireWindow *w;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    w = new ApplicHoraireWindow();
    w->show();
    return a.exec();
}