#include "view/mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[]) {
  setlocale(LC_ALL, "C");
  QApplication a(argc, argv);
  MainWindow w;
  w.show();
  return a.exec();
}
