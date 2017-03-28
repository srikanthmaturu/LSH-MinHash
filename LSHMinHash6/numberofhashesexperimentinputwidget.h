#ifndef NUMBEROFHASHESEXPERIMENTINPUTWIDGET_H
#define NUMBEROFHASHESEXPERIMENTINPUTWIDGET_H

#include <QWidget>
#include <QTextBrowser>

#include <string>

using namespace std;

namespace Ui {
class NumberOfHashesExperimentInputWidget;
}

class NumberOfHashesExperimentInputWidget : public QWidget
{
    Q_OBJECT

public:
    string * originalSequence;
    string * remoteSequence;
    int subSequenceWidth;
    int maxHashes;
    explicit NumberOfHashesExperimentInputWidget(QWidget *parent = 0);
    ~NumberOfHashesExperimentInputWidget();
    QTextBrowser * getTextBrowser();

private slots:
    void on_remoteLineEdit_textChanged(const QString &arg1);

    void on_originalLineEdit_textChanged(const QString &arg1);

    void on_subSequenceWidthLineEdit_textChanged(const QString &arg1);

    void on_maxHashesLineEdit_textChanged(const QString &arg1);

    void on_drawPlotPushButton_clicked();

signals:
    void drawButtonClicked(string * originalSequence, string * remoteSequence, int subSequenceWidth, int maxHashes);

private:
    Ui::NumberOfHashesExperimentInputWidget *ui;
};

#endif // NUMBEROFHASHESEXPERIMENTINPUTWIDGET_H
