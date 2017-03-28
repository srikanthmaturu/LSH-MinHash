#include "numberofhashesexperimentinputwidget.h"
#include "ui_numberofhashesexperimentinputwidget.h"


#include <iostream>

NumberOfHashesExperimentInputWidget::NumberOfHashesExperimentInputWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NumberOfHashesExperimentInputWidget)
{
    ui->setupUi(this);
}

NumberOfHashesExperimentInputWidget::~NumberOfHashesExperimentInputWidget()
{
    delete ui;
}

void NumberOfHashesExperimentInputWidget::on_remoteLineEdit_textChanged(const QString &arg1)
{
    this->remoteSequence = new string();
    *(this->remoteSequence) = arg1.toStdString();
}

void NumberOfHashesExperimentInputWidget::on_originalLineEdit_textChanged(const QString &arg1)
{
    this->originalSequence = new string();
    *(this->originalSequence) = arg1.toStdString();
}

void NumberOfHashesExperimentInputWidget::on_subSequenceWidthLineEdit_textChanged(const QString &arg1)
{
    if(arg1.isEmpty()){
        return;
    }
    this->subSequenceWidth = (stoi(arg1.toStdString()));
}

void NumberOfHashesExperimentInputWidget::on_maxHashesLineEdit_textChanged(const QString &arg1)
{
    if(arg1.isEmpty()){
        return;
    }
    this->maxHashes = (stoi(arg1.toStdString()));
}

void NumberOfHashesExperimentInputWidget::on_drawPlotPushButton_clicked()
{
    emit drawButtonClicked(this->originalSequence, this->remoteSequence, this->subSequenceWidth, this->maxHashes);
}

QTextBrowser * NumberOfHashesExperimentInputWidget::getTextBrowser(){
    return this->ui->outputTextBrowser;
}
