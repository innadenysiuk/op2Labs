#include "mainwindow.h"

#include <QApplication>
#include <QLabel>
#include <QPixmap>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(700,500);
    w.setWindowTitle("Обчислення значення функції");

    QPixmap image("/Users/admin/Desktop/opLab7_8/function");
    QLabel label(&w);
    label.setPixmap(image);
    int x = 215;
    int y = 50;
    label.setGeometry(x, y, image.width(), image.height());

    w.show();
    return a.exec();
}
