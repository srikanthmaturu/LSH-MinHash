#include "lsh_minhash.h"
#include "ui_lsh_minhash.h"

#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>

#include <cstdlib>
#include <string>
#include <iostream>

#include "LSHHandler.h"
#include "json.hpp"

LSH_MinHash::LSH_MinHash(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LSH_MinHash)
{
    ui->setupUi(this);
    outputStringStream = new stringstream();
    //outputStringStream->set_rdbuf(cout.rdbuf());
    //cout.set_rdbuf(cerr.rdbuf());
    cout.set_rdbuf(outputStringStream->rdbuf());
    lshParameters = new Parameters();
}

LSH_MinHash::~LSH_MinHash()
{
    delete ui;
}

void LSH_MinHash::setOutputTextBrowser(QTextBrowser * outputTextBrowser){
    this->outputTextBrowser = outputTextBrowser;
}

void LSH_MinHash::on_openParametersFilePushButton_clicked()
{   lshParameters->initialized = false;
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open Parameters File"), QString(),
         tr("JSON Files (*.json)"));

    if (fileName != "") {
        lshParameters = NULL;
        //ui->coutTextBrowser->append( (QString)"Parameters File Name: " + fileName + (QString)"\n");
        ifstream data_file (fileName.toStdString());
        j.clear();
        data_file >> j;
        int number_of_files = j["filenames"].size();
        string * filenames = new string[number_of_files];
        filenames[0] = j["filenames"][0];
        if(number_of_files > 1){
            filenames[1] = j["filenames"][1];
        }
        lshParameters = new Parameters(j["mode"], filenames, number_of_files, j["file_type"], j["number_of_sequences"], j["sequence_min_length"], j["sub_sequence_width"], j["hash_type"],
                                        j["number_of_buckets"], j["tolerance_limit"], j["number_of_hashes"], j["min_signatures_similarity_ratio"], 0);
        lshParameters->initialized = true;
        this->setParametersToDisplay(lshParameters);
    }
}

void LSH_MinHash::on_runPushButton_clicked()
{
    outputStringStream->str("");
    if(!lshParameters->initialized){
        return;
    }

    LSHHandler * lsh_handler = new LSHHandler(lshParameters);
    lsh_handler->execute();
    //ui->coutTextBrowser->setText(QString::fromStdString(outputStringStream->str()));
    this->outputTextBrowser->setText(QString::fromStdString(outputStringStream->str()));
    return;
}

void LSH_MinHash::on_modeLineEdit_textChanged(const QString &arg1)
{
    if(arg1.isEmpty()){
        return;
    }
    lshParameters->setMode(arg1.toStdString());
}

void LSH_MinHash::on_fileTypeLineEdit_textChanged(const QString &arg1)
{
    if(arg1.isEmpty()){
        return;
    }
    lshParameters->setFileType(stoi(arg1.toStdString()));
}

void LSH_MinHash::on_numberOfSequencesLineEdit_textChanged(const QString &arg1)
{
    if(arg1.isEmpty()){
        return;
    }
    lshParameters->setNumberOfSequences(stoi(arg1.toStdString()));
}

void LSH_MinHash::on_sequenceMinLengthLineEdit_textChanged(const QString &arg1)
{
    if(arg1.isEmpty()){
        return;
    }
    lshParameters->setSequenceMinLength(stoi(arg1.toStdString()));
}

void LSH_MinHash::on_subSequenceWidthLineEdit_textChanged(const QString &arg1)
{
    if(arg1.isEmpty()){
        return;
    }
    lshParameters->setSubSequenceWidth(stoi(arg1.toStdString()));
}


void LSH_MinHash::on_hashTypeLineEdit_textChanged(const QString &arg1)
{
    if(arg1.isEmpty()){
        return;
    }
    lshParameters->setHashType(stoi(arg1.toStdString()));
}

void LSH_MinHash::on_numberOfBucketsLineEdit_textChanged(const QString &arg1)
{
    if(arg1.isEmpty()){
        return;
    }
    lshParameters->setNumberOfBuckets(stoi(arg1.toStdString()));
}

void LSH_MinHash::on_numberOfHashesLineEdit_textChanged(const QString &arg1)
{
    if(arg1.isEmpty()){
        return;
    }
    lshParameters->setNumberOfHashes(stoi(arg1.toStdString()));
}

void LSH_MinHash::on_minSignaturesSimilarityRatioLineEdit_textChanged(const QString &arg1)
{
    if(arg1.isEmpty()){
        return;
    }
    lshParameters->setMinSignaturesSimilarityRatio(stof(arg1.toStdString()));
}

void LSH_MinHash::setParametersToDisplay(Parameters * lshParameters){
    ui->modeLineEdit->setText(QString::fromStdString(lshParameters->mode));
    ui->fileNamesLineEdit->setText(QString::fromStdString(lshParameters->filenames[0]));
    ui->fileTypeLineEdit->setText(QString::fromStdString(to_string(lshParameters->file_type)));
    ui->numberOfSequencesLineEdit->setText(QString::fromStdString(to_string(lshParameters->number_of_sequences)));
    ui->sequenceMinLengthLineEdit->setText(QString::fromStdString(to_string(lshParameters->sequence_min_length)));
    ui->subSequenceWidthLineEdit->setText(QString::fromStdString(to_string(lshParameters->sub_sequence_width)));
    ui->hashTypeLineEdit->setText(QString::fromStdString(to_string(lshParameters->hash_type)));
    ui->numberOfBucketsLineEdit->setText(QString::fromStdString(to_string(lshParameters->number_of_buckets)));
    ui->toleranceLineEdit->setText(QString::fromStdString(to_string(lshParameters->toleranceLimit)));
    ui->numberOfHashesLineEdit->setText(QString::fromStdString(to_string(lshParameters->number_of_hashes)));
    ui->minSignaturesSimilarityRatioLineEdit->setText(QString::fromStdString(to_string(lshParameters->min_signatures_similarity_ratio)));
}


void LSH_MinHash::on_toleranceLineEdit_textChanged(const QString &arg1)
{
    if(arg1.isEmpty()){
        return;
    }
    lshParameters->setToleranceLimit(stoi(arg1.toStdString()));
}



