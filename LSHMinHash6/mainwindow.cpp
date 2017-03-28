#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tabWidget = new QTabWidget(this);
    lshMinHashRunWidget = new LSHMinHashRunWidget(this);
    //numberOfHashesPlotWidget = new NumberOfHashesPlotWidget(this);
    tabWidget->addTab(lshMinHashRunWidget, QString::fromStdString("Run"));
    //tabWidget->addTab(numberOfHashesPlotWidget, QString::fromStdString("HashesPlot"));
    //QBoxLayout * templayout = new QBoxLayout(QBoxLayout::LeftToRight);
    //templayout->addWidget(numberOfHashesPlotWidget);
    //tabWidget->addTab(templayout, QString::fromStdString("HashesPlot"));
    connect(tabWidget, SIGNAL(tabBarClicked(int)), this, SLOT(on_tabWidget_tabBarClicked(int)));
    setCentralWidget(tabWidget);
    //setCentralWidget(lshMinHashRunWidget);
    //lshMinHashRunWidget->show();
    //ui->menubar->setStyle(QStyle::CE_MenuBarItem);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_tabWidget_tabBarClicked(int index)
{
}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}
