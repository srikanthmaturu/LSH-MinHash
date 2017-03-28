/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Sequence.h
 * Author: Srikanth
 *
 * Created on February 5, 2017, 7:51 PM
 */

#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <cstdlib>
#include <iostream>
#include <string>

#include "SequencesSet.h"
#include "SequencesMap.h"
#include "Signature.h"
#include "SimilaritySet.h"

using namespace std;

class Sequence {
public:
    Sequence();
    Sequence(const Sequence& orig);
    virtual ~Sequence();
    void setSequence(string sequence);
    void setComment(string comment);
    void getComment();
    string getSequence();
    void appendSequence(string append_sequence);
    void setIndex(int sequenceIndex);
    int getIndex();
    void printSequence();
    void printRawSequence();
    void printSubSequences();
    void computeSubSequencesSet(int sub_sequence_width);
    SequencesSet * getSubSequencesSet();
    void setSubSequencesSet(SequencesSet * sub_sequences_set);
    void computeSubSequencesMap(SequencesMap * all_sub_sequences_map);
    void setSubSequencesMap(SequencesMap * sub_sequences_map);
    SequencesMap* getSubSequencesMap();
    void setSignature(Signature * signature);
    Signature* getSignature();
    SimilaritySet * getSimilairtySet();
    void setSimilaritySet(SimilaritySet * similarity_set);
    void printSimilaritySet();
    float getActualSimilarityRatio(SequencesSet * superSubSequencesSet, Sequence * inputSequence);
    int getSequenceSize();
    
private:
    string sequence;
    string sequence_comment;
    SequencesSet * sub_sequences_set;
    SequencesMap * sub_sequences_map;
    Signature * signature;
    SimilaritySet * similarity_set;
    int sequenceIndex;
};

#endif /* SEQUENCE_H */

