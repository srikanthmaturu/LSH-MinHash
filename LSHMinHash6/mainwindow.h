#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "lshminhashrunwidget.h"
//#include "numberofhashesplotwidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QTabWidget * tabWidget;
    LSHMinHashRunWidget * lshMinHashRunWidget;
    //NumberOfHashesPlotWidget * numberOfHashesPlotWidget;

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_tabWidget_tabBarClicked(int index);

    void on_actionExit_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
