#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initValues(std::list<unsigned int> amount, std::list<float> time){
    this->time = time;
    this->amount = amount;
}

void MainWindow::on_pushButton_clicked()
{


    float max_time = time.front();
    unsigned max_amount = amount.front();
    float min_time = time.front();
    unsigned min_amount = amount.front();

    QVector<double> x(time.size()), y(amount.size());
    int i = 0;
    while(!amount.empty()) {
        x[i] = amount.front();
        y[i] = time.front();

        if(time.front() > max_time){
            max_time = time.front();
        }
        if(time.front() < min_time){
            min_time = time.front();
        }
        if(amount.front() > max_amount){
            max_amount = amount.front();
        }
        if(amount.front() < min_amount){
            min_amount = amount.front();
        }


        time.pop_front();
        amount.pop_front();
        i++;




    }

    ui->plot->clearGraphs();
    ui->plot->addGraph();
    ui->plot->graph(0)->setData(x,y);

    ui->plot->xAxis->setLabel("Time");
    ui->plot->yAxis->setLabel("CountOfWord");

    ui->plot->xAxis->setRange(0, max_amount);


    ///
    double minY = min_time;
    double maxY = max_time;

    ui->plot->yAxis->setRange(minY,maxY);

    ui->plot->replot();

}
