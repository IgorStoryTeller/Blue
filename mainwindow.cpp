#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sockettest.h"
#include "parser.h"
#include "graphwidget.h"
#include "dijkstrasalg.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    SocketTest Socket;
    parser Parser;
    Socket.Connect();
    Socket.SendMessage(LOGIN,{{"name", ui->login->text()}});
    Socket.SendMessage(MAP,{{"layer", 0}});
    Parser.Pars(Socket.getterDoc());
    QVector <int> pointsOfGraph = Parser.getterPointsOfGraph();
    QVector <QVector <int> > Table = Parser.getterLayer0();
//    DijkstrasAlg alg(1,Table,pointsOfGraph);
//    QVector <int> test1 = alg.Path(true,4);
//    qDebug() << test1;
//    test1 = alg.Path(false,4);
//    qDebug() << test1;
    Socket.SendMessage(MAP,{{"layer", 1}});
    Parser.Pars(Socket.getterDoc());
    QVector <QVector <int> > pointsType = Parser.getterLayer1();
    new GraphWidget(nullptr, Table, pointsOfGraph, pointsType, this);
    Socket.SendMessage(MAP,{{"layer", 10}});
}
