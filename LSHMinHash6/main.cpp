/* 
 * File:   main.cpp
 * Author: Srikanth
 *
 * Created on November 19, 2016, 11:43 PM
 */

#include <cstdlib>
#include <string>
#include <iostream>

#include "test.h"
#include "LSHHandler.h"

#include "json.hpp"


#include <QApplication>
#include "lsh_minhash.h"
#include "mainwindow.h"

#include "commandrun.h"

using namespace std;
using json = nlohmann::json;

void run(int argc, char** argv){
    string filename;

    if(argc < 2){
        cout << "Parameters file not specified. To specify use main.o paramters.json";
        //return 0;
    } else{
        filename = argv[1];
    }

    filename = "datafiles/parameters.json";

    ifstream data_file (filename);
    json j;

    data_file >> j;

//    LSHHandler * lsh_handler = new LSHHandler(j["number_of_hashes"], j["segment_size"], j["number_of_buckets"], j["min_signatures_similarity_ratio"]);
//    lsh_handler->setMode(j["hash_type"]);

//    if(j["filenames"].size() > 1){
//        lsh_handler->singleRemoteSimilarityCheck(j["filenames"][0], j["filenames"][1], j["number_of_sequences"], j["sequence_min_length"], j["sub_sequence_width"], j["file_type"]);
//    }
//    else{
//        cout << j["filenames"][0] << "\n";
//        lsh_handler->pairWiseSimilarityCheck(j["filenames"][0], j["number_of_sequences"], j["sequence_min_length"], j["sub_sequence_width"], j["file_type"]);
//    }

}

/*
 * 
 */
int main(int argc, char** argv) {
	QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}



