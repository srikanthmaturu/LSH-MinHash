#include "lshminhashrunwidget.h"
#include "ui_lshminhashrunwidget.h"
#include <QPushButton>

LSHMinHashRunWidget::LSHMinHashRunWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LSHMinHashRunWidget)
{
    ui->setupUi(this);
    lshMinHashWidget = new LSH_MinHash();
    QSizePolicy lshMinHashWidgetSizePolicy = QSizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
    lshMinHashWidget->setSizePolicy(lshMinHashWidgetSizePolicy);
    outputTextBrowser = new QTextBrowser();
    outputTextBrowser->setLineWrapMode(QTextEdit::NoWrap);
    //outputTextBrowser->setGeometry(340, 0, 810, 670);
    //outputTextBrowser->setMaximumHeight(670);
    //outputTextBrowser->setMaximumWidth(810);
    QSizePolicy outputTextBrowserSizePolicy = QSizePolicy(QSizePolicy::Policy::MinimumExpanding, QSizePolicy::Policy::MinimumExpanding);
    //outputTextBrowserSizePolicy.setHorizontalStretch(0);
    outputTextBrowser->setSizePolicy(outputTextBrowserSizePolicy);
    lshMinHashWidget->setOutputTextBrowser(outputTextBrowser);
    layout = new QBoxLayout(QBoxLayout::LeftToRight);

    layout->addWidget(lshMinHashWidget);
    layout->addWidget(outputTextBrowser);
    setLayout(layout);
    show();
}

LSHMinHashRunWidget::~LSHMinHashRunWidget()
{
    delete ui;
}
