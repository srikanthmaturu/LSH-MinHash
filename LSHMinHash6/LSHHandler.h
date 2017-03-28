/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LSHHandler.h
 * Author: Srikanth
 *
 * Created on February 8, 2017, 2:28 PM
 */

#ifndef LSHHANDLER_H
#define LSHHANDLER_H


#include <string>

#include "Sequences.h"
#include "Parameters.h"

using namespace std;

class LSHHandler {
public:
    LSHHandler(const LSHHandler& orig);
    LSHHandler(Parameters * parameters);
    virtual ~LSHHandler();
    void setMode(int mode);
    void singleRemoteSimilarityCheck();
    void pairWiseSimilarityCheck();
    void run();
    void execute();
    Sequences * getSequences();
private:
    int number_of_hashes, mode, segment_size, number_of_buckets;
    float min_signatures_similarity_ratio;
    Sequences * sequences;
    Parameters * parameters;
};

#endif /* LSHHANDLER_H */

