/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Sequence.cpp
 * Author: Srikanth
 * 
 * Created on February 5, 2017, 7:51 PM
 */

#include "Sequence.h"
#include <string>
#include <iostream>

Sequence::Sequence() {
    this->sequence;
    this->sub_sequences_map = NULL;
}

Sequence::Sequence(const Sequence& orig) {
}

Sequence::~Sequence() {
}

void Sequence::setSequence(string sequence){
    this->sequence = sequence.substr(0);
}

string Sequence::getSequence(){
    return sequence;
}

void Sequence::setComment(string comment){
    this->sequence_comment = comment;
}

void Sequence::appendSequence(string append_sequence){
    int pos;
    if((pos=append_sequence.find('\n')) != string::npos){
        append_sequence.erase(pos);
    }
    if((pos=append_sequence.find('\r')) != string::npos){
        append_sequence.erase(pos);
    }
    
    string final_sequence = "";
    this->sequence.append(append_sequence);
}

void Sequence::setIndex(int sequenceIndex){
    this->sequenceIndex = sequenceIndex;
}

int Sequence::getIndex(){
    return this->sequenceIndex;
}

void Sequence::printSequence(){
    cout<< "\n seq: " << this->sequence ;
}

void Sequence::printRawSequence(){
    cout << this->sequence;
}

void Sequence::printSubSequences(){
    for(SequencesSet::iterator it = this->sub_sequences_set->begin(); it != this->sub_sequences_set->end(); ++it){
        cout << "\n" << *it;
    }
}

void Sequence::computeSubSequencesSet(int sub_sequence_width){
    this->sub_sequences_set = new SequencesSet();
    this->sub_sequences_set->setSubSequenceWidth(sub_sequence_width);
    this->sub_sequences_set->convertSequence(this->sequence);
}

SequencesSet* Sequence::getSubSequencesSet(){
    return this->sub_sequences_set;
}

void Sequence::setSubSequencesSet(SequencesSet* sub_sequences_set){
    this->sub_sequences_set = sub_sequences_set;
}

void Sequence::computeSubSequencesMap(SequencesMap * all_sub_sequences_map){
    int current_index;
    string current_string;
    if(!this->sub_sequences_map){
        this->sub_sequences_map = new SequencesMap();
    }
    for(SequencesSet::iterator it = this->sub_sequences_set->begin(); it != this->sub_sequences_set->end(); ++it){        
        current_string = *it;
        current_index = all_sub_sequences_map->at(current_string);
        this->sub_sequences_map->insert(pair<string, int> (current_string, current_index));
    }
}

void Sequence::setSubSequencesMap(SequencesMap * sub_sequences_map){
    this->sub_sequences_map = sub_sequences_map;
}

SequencesMap* Sequence::getSubSequencesMap(){
    return this->sub_sequences_map;
}

void Sequence::setSignature(Signature * signature){
    this->signature = signature;
}

Signature* Sequence::getSignature(){
    return this->signature;
}
   
SimilaritySet * Sequence::getSimilairtySet(){
    return this->similarity_set;
}

void Sequence::setSimilaritySet(SimilaritySet * similarity_set){
    this->similarity_set = similarity_set;
}

void Sequence::printSimilaritySet(){
    string print_string;
    print_string.append("Seq:"+to_string(similarity_set->getSequenceIndex())+"\t-->\t");
    for(SimilaritySet::iterator sit = similarity_set->begin(); sit != similarity_set->end(); ++sit){
        print_string.append("Seq:"+to_string((*sit))+"\t");
    }
    
    cout << "\n\n" << print_string; 
}

float Sequence::getActualSimilarityRatio(SequencesSet * superSubSequencesSet, Sequence * inputSequence){
    int intersectionCount = 0, unionCount = 0;
    bool containsInCurrentSequence, containInInputSequence;
    int index1 =0, index2 =0;
    for(SequencesSet::iterator ssit = superSubSequencesSet->begin(); ssit!=superSubSequencesSet->end(); ++ssit){
        containInInputSequence = this->sub_sequences_set->find(*ssit) != this->sub_sequences_set->end();
        containsInCurrentSequence = inputSequence->getSubSequencesSet()->find(*ssit) != inputSequence->getSubSequencesSet()->end();
        if(containInInputSequence && containsInCurrentSequence){
            intersectionCount++;
        }
        if(containInInputSequence || containsInCurrentSequence){
            unionCount++;
        }
       /** if(containInInputSequence){
            index1++;
        }

        if(containsInCurrentSequence){
            index2++;
        }
        **/
    }
    //cout << " IntersectionCount: "<< intersectionCount << " Index1: " << index1 << " Index2: " << index2 << "\n";
    return (float)intersectionCount/(float)unionCount;
}

int Sequence::getSequenceSize(){
    return this->sequence.size();
}
