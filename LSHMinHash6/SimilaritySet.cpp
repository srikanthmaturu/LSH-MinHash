/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SimilaritySet.cpp
 * Author: Srikanth
 * 
 * Created on February 8, 2017, 10:34 AM
 */

#include "SimilaritySet.h"

SimilaritySet::SimilaritySet() {
}

SimilaritySet::SimilaritySet(const SimilaritySet& orig) {
}

SimilaritySet::~SimilaritySet() {
}

void SimilaritySet::setSequenceIndex(int sequence_index){
    this->sequence_index = sequence_index;
}
    
int SimilaritySet::getSequenceIndex(){
    return this->sequence_index;
}
