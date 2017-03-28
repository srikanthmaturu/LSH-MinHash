/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SequencesMap.cpp
 * Author: Srikanth
 * 
 * Created on February 6, 2017, 2:30 PM
 */

#include "SequencesMap.h"

#include "SequencesSet.h"

SequencesMap::SequencesMap() {
}

SequencesMap::SequencesMap(const SequencesMap& orig) {
}

SequencesMap::~SequencesMap() {
}

void SequencesMap::setSequencesSet(SequencesSet* sequences_set){
    this->sequences_set = sequences_set;
}
SequencesSet* SequencesMap::getSequencesSet(){
    return this->sequences_set;
}

void SequencesMap::computeSequencesMap(){
    int index = 1;
    
    for(SequencesSet::iterator it = this->sequences_set->begin(); it != this->sequences_set->end(); ++it, ++index){
        this->insert(pair<string, int> (*it, index));
    }
}

void SequencesMap::printSequencesMap(){
    cout << "\nPrinting Map: ";
    for(SequencesMap::iterator it = this->begin(); it != this->end(); ++it){
        cout<< "\n Seq: " << it->first << "\t Ind: " << it->second;
    }
}