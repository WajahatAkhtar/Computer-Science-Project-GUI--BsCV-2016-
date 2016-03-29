#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QPainter>
#include <QGraphicsView>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
  //  QRectF boundingRect()const;
    // void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    
private slots:
   // void on_lcdNumber_overflow();


private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    //QGraphicsView *view;
   // QGraphicsScene *Ob;
   // QBrush	backgroundBrush();
   // QImage  *imageObject;
  //  QPixmap image;
      QTimer *time;
};

#endif // MAINWINDOW_H
