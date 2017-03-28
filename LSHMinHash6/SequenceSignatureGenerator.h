/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SequenceSignatureGenerator.h
 * Author: Srikanth
 *
 * Created on February 7, 2017, 3:57 PM
 */

#ifndef SEQUENCESIGNATUREGENERATOR_H
#define SEQUENCESIGNATUREGENERATOR_H

#include "Permutations.h"
#include "Sequence.h"

class SequenceSignatureGenerator {
public:
    SequenceSignatureGenerator();
    SequenceSignatureGenerator(const SequenceSignatureGenerator& orig);
    virtual ~SequenceSignatureGenerator();
    void set_signature_size(int size);
    int get_signature_size();
    void initializePermutations();
    void set_permutations(Permutations * permutations);
    Permutations * getPermutations();
    void setNumberOfSequences(int number_of_sequences);
    int getNumberOfSequences();
    void setNumberOfSubSequences(int number_of_sub_sequences);
    int getNumberOfSubSequences();
    void computeSignature(Sequence * sequence);
private:
    int signature_size;
    int number_of_sub_sequences;
    int number_of_sequences;
    Permutations * permutations;
};

#endif /* SEQUENCESIGNATUREGENERATOR_H */

