#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "items_inside_rect.h"
#include "obsticles_inside_rect.h"
#include <iostream>
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsView>

MainWindow :: MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui :: MainWindow)

{
    ui->setupUi(this);

    /*
    // QGraphicsView* w = new QGraphicsView();
    //scene->setSceneRect( w->rect() );
   // w->setScene( scene );
    //w->setFixedSize( 500, 500 );
    QPixmap pix( "E:\BSCV2\BSCV_2\Computer Science\Project Computer Science\MyProject\ball.png" );
    scene->addPixmap( pix );
    w->show();
*/
   // ui->label->setPixmap(QPixmap(":/new/prefix1/ball"));

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
    scene -> setSceneRect(-200,-200,300,300);
    QPen pen = QPen(Qt::yellow);
    scene -> setBackgroundBrush(Qt::black);


/*
   // QBrush greenBrush(Qt::green);
    QBrush blueBrush(Qt::blue);
    QPen pen = QPen(Qt::black);
    pen.setWidth(3);
    scene->addRect(10,10,50,50, pen, blueBrush);
*/

   // QBrush brush(scene->sceneRect());
   // brush.setColor(scene->sceneRect(Qt::black));


            //painter->fillRect(rectangle, brush);
            //painter->drawRect(rectangle);

            // QBrush brush(view->setSceneRect(Qt::blue));
          // brush.setColor(view->setSceneRect(Qt::blue));

    QLineF topline(scene->sceneRect().topLeft(),scene->sceneRect().topRight());
    QLineF leftline(scene->sceneRect().topLeft(),scene->sceneRect().bottomLeft());
    QLineF rightline(scene->sceneRect().topRight(),scene->sceneRect().bottomRight());
    QLineF bottomline(scene->sceneRect().bottomLeft(),scene->sceneRect().bottomRight());
    scene->addLine(topline,pen);
    scene->addLine(leftline,pen);
    scene->addLine(rightline,pen);
    scene->addLine(bottomline,pen);









/*
    imageObject = new QImage();
    imageObject->load("E:\BSCV2\BSCV_2\Computer Science\Project Computer Science\MyProject\ball.png");
    image = QPixmap::fromImage(*imageObject);

    image.load("E:\BSCV2\BSCV_2\Computer Science\Project Computer Science\MyProject\ball.png");
    scene->addPixmap(image);
    scene->setSceneRect(image.rect());
    ui-> graphicsView->setScene(scene);
*/

  //  view = new  QGraphicsView(scene);
    //QGraphicsView view(&scene);
    //view.show();
   // view.setBackgroundBrush(Qt::blue);



/***************ITEMS INSIDE RECTANGLE***********************/

   // int count_item =1;
   // for(int i = 0; i < count_item; i++)
  //  {
        Items_inside_Rect *item = new Items_inside_Rect();
        scene->addItem(item);
        //Items_inside_Rect *item2 = new Items_inside_Rect();
        //scene->addItem(item2);


  //  }

/*************************************************************/


/***************OBSTICLES INSIDE RECTANGLE********************/
/*
    int count_obsticles = 1;
    for(int i = 0; i < count_obsticles; i++)
    {
        obsticles_inside_rect *obsticles = new obsticles_inside_rect;
        Ob->addLine(obsticles);

    }
*/
/*************************************************************/

    time = new QTimer(this);
    connect(time,SIGNAL(timeout()),scene ,SLOT(advance()));
    time -> start(2);


}

MainWindow::~MainWindow()
{
    delete ui;
}



//void MainWindow::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
//{


  /*  QRectF rectangle= boundingRect();
    QBrush brush = QBrush(Qt::black);
   // brush.setColor(Qt::yellow);
    painter->fillRect(rectangle, brush);
    painter->drawRect(rectangle);

    // QBrush brush(view->setSceneRect(Qt::blue));
  // brush.setColor(view->setSceneRect(Qt::blue));



}
*/

//void MainWindow::on_lcdNumber_overflow()
//{

//}


/*

void MainWindow::on_pushButton_clicked()
{
    int  a,b,c;
    bool check1;
    bool check2;

    ui->label->setText("Enter number");
    ui->label_2->setText("Enter number");
    ui->label_3->setText("Result");

    a = ui->input1->text().toInt(&check1);
    b = ui->input2->text().toInt(&check2);

    if (check1 == true && check2 == true )
    {
    c = a+b;
    ui->result->setText(QString::number(c));
}
    else
        {
        ui->result->setText("Number entered is not and integer or it is not entered ");
        }
}

void MainWindow::on_pushButton_pressed()
{

    ui->label->setText("Button Pressed");
    ui->label_2->setText("Button Pressed");
    ui->label_3->setText("Button Pressed");

}*/

/*void MainWindow::on_lcdNumber_overflow()
{

}
*/
