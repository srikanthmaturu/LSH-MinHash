/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SequencesSet.cpp
 * Author: Srikanth
 * 
 * Created on February 6, 2017, 12:58 PM
 */

#include "SequencesSet.h"
#include "Sequence.h"

SequencesSet::SequencesSet() {
}

SequencesSet::SequencesSet(const SequencesSet& orig) {
}

SequencesSet::~SequencesSet() {
}

void SequencesSet::convertSequence(string sequence){
    int length = sequence.size(), steps = length - (this->sub_sequence_width - 1);
    //cout << "\n" << sequence;
    //cout << "\nSize: " << length << " Steps: " << steps << "\n";
    int count = 0;
    string sub_string;
    
    while(count < steps){
        sub_string = sequence.substr(count, this->sub_sequence_width);
        this->insert(sub_string);
        ++count;
    }
}

void SequencesSet::setSubSequenceWidth(int width){
    this->sub_sequence_width = width;
}

int SequencesSet::getSubSequenceWidth(int width){
    return this->sub_sequence_width;
}

void SequencesSet::appendSequences(SequencesSet* append_sequences){
    for(SequencesSet::iterator it = append_sequences->begin(); it != append_sequences->end(); ++it){
        this->insert(*it);
    }
}

void SequencesSet::printSequencesSet(){
    cout << "\nPrinting Set: ";
    for(SequencesSet::iterator it = this->begin(); it != this->end(); ++it){
        cout<< "\n Seq: " << *it ;
        string s = *it;
    }    
}

