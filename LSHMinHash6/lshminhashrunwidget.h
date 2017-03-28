#ifndef LSHMINHASHRUNWIDGET_H
#define LSHMINHASHRUNWIDGET_H

#include <QWidget>
#include <QTextBrowser>
#include <QBoxLayout>

#include "lsh_minhash.h"

namespace Ui {
class LSHMinHashRunWidget;
}

class LSHMinHashRunWidget : public QWidget
{
    Q_OBJECT

public:
    LSH_MinHash * lshMinHashWidget;
    QTextBrowser * outputTextBrowser;
    QBoxLayout * layout;
    explicit LSHMinHashRunWidget(QWidget *parent = 0);
    ~LSHMinHashRunWidget();

private:
    Ui::LSHMinHashRunWidget *ui;
};

#endif // LSHMINHASHRUNWIDGET_H
