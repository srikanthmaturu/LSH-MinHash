#ifndef LSH_MINHASH_H
#define LSH_MINHASH_H

#include <QWidget>
#include <iostream>

using namespace std;

#include "json.hpp"
#include "Parameters.h"
#include <QTextBrowser>

using json = nlohmann::json;

namespace Ui {
class LSH_MinHash;
}

class LSH_MinHash : public QWidget
{
    Q_OBJECT

public:
    json j;
    stringstream * outputStringStream;
    Parameters * lshParameters;
    QTextBrowser * outputTextBrowser;
    explicit LSH_MinHash(QWidget *parent = 0);
    ~LSH_MinHash();
    void setOutputTextBrowser(QTextBrowser * outputTextBrowser);

private slots:
    void on_openParametersFilePushButton_clicked();

    void on_runPushButton_clicked();

    void on_modeLineEdit_textChanged(const QString &arg1);

    void on_fileTypeLineEdit_textChanged(const QString &arg1);

    void on_numberOfSequencesLineEdit_textChanged(const QString &arg1);

    void on_sequenceMinLengthLineEdit_textChanged(const QString &arg1);

    void on_subSequenceWidthLineEdit_textChanged(const QString &arg1);

    void on_hashTypeLineEdit_textChanged(const QString &arg1);

    void on_numberOfBucketsLineEdit_textChanged(const QString &arg1);

    void on_numberOfHashesLineEdit_textChanged(const QString &arg1);

    void on_minSignaturesSimilarityRatioLineEdit_textChanged(const QString &arg1);

    void setParametersToDisplay(Parameters * lshParameters);

    void on_toleranceLineEdit_textChanged(const QString &arg1);

private:
    Ui::LSH_MinHash *ui;
};

#endif // LSH_MINHASH_H
