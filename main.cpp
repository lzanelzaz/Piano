#include "piano.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/icon.ico"));
    QRect  screenGeometry = QGuiApplication::primaryScreen()->geometry();
    Piano piano(screenGeometry.height(), screenGeometry.width());
    piano.show();
    return a.exec();
}
