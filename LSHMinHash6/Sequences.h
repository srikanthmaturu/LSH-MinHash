/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Sequences.h
 * Author: Srikanth
 *
 * Created on February 6, 2017, 10:37 PM
 */

#ifndef SEQUENCES_H
#define SEQUENCES_H

#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <regex>


#include "Sequence.h"
#include "SequencesMap.h"
#include "SequencesSet.h"
#include "SequenceSignatureGenerator.h"
#include "Buckets.h"
#include "math.h"

using namespace std;

class Sequences {
public:
    Sequences();
    Sequences(const Sequences& orig);
    virtual ~Sequences();
    void setSequences(vector<Sequence *> * sequences);
    vector<Sequence *> * getSequences();
    void readInputSequences(string filename, int sub_sequence_width, int number_of_sequences, int sequence_min_length , int type, int printMode);
    void readInputSequences(vector<string> * sequenceStrings, int sub_sequence_width);
    void indexSequences();
    void computeSubSequencesSetsUnion();
    SequencesSet * getSubSequencesSetsUnion();
    void computeSubSequencesSetsUnionMap();
    SequencesMap * getSubSequencesSetsUnionMap();
    void computeSequencesMaps();
    void initializeSignatures();
    void computeSequencesSignatures();
    void printShinglesMatrix();
    void printSignatures();
    void initializeSequenceSignatureGenerator(int signature_size);
    void initializeBuckets(int number_of_buckets, int segment_size, float min_signatures_similarity_ratio = 0.0);
    void putSequencesToBuckets();
    void computeSimilaritySets();
    void printSimilaritySets();
    void printSimilarSequences(int numberOfSequences);
    void readRemoteSequence(string filename);
    void appendSequences(vector< Sequence * > * sequences);
    void setLSHMode(int mode);
    int getLSHMode();
    void computeSequencesSimilarityMatrix();
    void printSequencesSimilarityMatrix();
    vector< vector< float> * > * getSequencesSimilarityMatrix();
    void computeActualSequencesSimilarityMatrix();
    void printActualSequencesSimilarityMatrix();
    vector< vector< float> * > * getActualSequencesSimilarityMatrix();

private:
    vector< Sequence * > * sequences;
    SequencesSet * sub_sequences_sets_union;
    SequencesMap * sub_sequences_sets_union_map;
    SequenceSignatureGenerator * signaturegenerator;
    Buckets * buckets;
    vector< vector< float > * > * SequencesSimilarityMatrix;
    vector< vector< float > * > * ActualSequencesSimilarityMatrix;
    int lsh_mode;
};

#endif /* SEQUENCES_H */

