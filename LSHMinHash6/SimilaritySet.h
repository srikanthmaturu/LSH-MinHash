/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SimilaritySet.h
 * Author: Srikanth
 *
 * Created on February 8, 2017, 10:34 AM
 */

#ifndef SIMILARITYSET_H
#define SIMILARITYSET_H

#include <set>

using namespace std;

class SimilaritySet :public set< int >{
public:
    SimilaritySet();
    SimilaritySet(const SimilaritySet& orig);
    virtual ~SimilaritySet();
    void setSequenceIndex(int sequence_index);
    int getSequenceIndex();
private:
    int sequence_index;

};

#endif /* SIMILARITYSET_H */

