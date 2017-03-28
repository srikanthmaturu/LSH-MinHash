/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SequenceSignatureGenerator.cpp
 * Author: Srikanth
 * 
 * Created on February 7, 2017, 3:57 PM
 */

#include <functional>

#include "SequenceSignatureGenerator.h"
#include "Signature.h"
#include "Sequence.h"

SequenceSignatureGenerator::SequenceSignatureGenerator() {
}

SequenceSignatureGenerator::SequenceSignatureGenerator(const SequenceSignatureGenerator& orig) {
}

SequenceSignatureGenerator::~SequenceSignatureGenerator() {
}

void SequenceSignatureGenerator::set_signature_size(int size){
    this->signature_size = size;
}

int SequenceSignatureGenerator::get_signature_size(){
    return this->signature_size;
}

void SequenceSignatureGenerator::setNumberOfSequences(int number_of_sequences){
    this->number_of_sequences = number_of_sequences;
}

int SequenceSignatureGenerator::getNumberOfSequences(){
    return this->number_of_sub_sequences;
}

void SequenceSignatureGenerator::setNumberOfSubSequences(int number_of_sub_sequences){
    this->number_of_sub_sequences = number_of_sub_sequences;
}

int SequenceSignatureGenerator::getNumberOfSubSequences(){
    return this->number_of_sub_sequences;
}

void SequenceSignatureGenerator::initializePermutations(){
    this->permutations = new Permutations();
    this->permutations->generateRandomPermutations(this->signature_size, this->number_of_sub_sequences);
}

void SequenceSignatureGenerator::set_permutations(Permutations * permutations){
    this->permutations = permutations;
}

Permutations * SequenceSignatureGenerator::getPermutations(){
    return this->permutations;
}

void SequenceSignatureGenerator::computeSignature(Sequence * sequence){
    Signature * s = sequence->getSignature();
    int original_row_index, permuted_row_index;
    Permutation * p;
    //s->initializeSignature(this->signature_size);
    for(SequencesMap::iterator smit = sequence->getSubSequencesMap()->begin(); smit!=sequence->getSubSequencesMap()->end(); ++smit ){
        original_row_index = (*smit).second;
        for(int hi = 0; hi < this->permutations->getPermutations()->size(); ++hi){
            p = this->permutations->getPermutations()->at(hi);
            permuted_row_index = p->getMapValue(original_row_index);
            if(s->getValueAt(hi) < 0){
                s->setValueAt(hi, permuted_row_index);
            }
            else if(s->getValueAt(hi) > permuted_row_index){
                 s->setValueAt(hi, permuted_row_index);
            }
        }
    }
}
