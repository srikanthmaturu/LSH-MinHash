/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LSHHandler.cpp
 * Author: Srikanth
 * 
 * Created on February 8, 2017, 2:28 PM
 */

#include "LSHHandler.h"
#include "Sequences.h"
#include "Sequence.h"

LSHHandler::LSHHandler(Parameters *parameters){
    this->parameters = parameters;
    this->sequences = new Sequences();
}

LSHHandler::LSHHandler(const LSHHandler& orig) {
}

LSHHandler::~LSHHandler() {
}

void LSHHandler::execute(){
    if(this->parameters->number_of_files == 2){
         this->singleRemoteSimilarityCheck();
      }
     else if(this->parameters->number_of_files == 1){
         this->pairWiseSimilarityCheck();
    }
     else{
       sequences->readInputSequences(this->parameters->sequencesStrings, this->parameters->sub_sequence_width);
       this->run();
    }
}

void LSHHandler::singleRemoteSimilarityCheck(){
    
    if(this->parameters->printMode == 0){
        cout <<"\n Reading the remote sequence: \n";
    }

    sequences->readInputSequences(this->parameters->filenames[0], this->parameters->sub_sequence_width, this->parameters->number_of_sequences, this->parameters->sequence_min_length, this->parameters->file_type,
            this->parameters->printMode);
    //cout <<"\n\n Reading of the remote sequence is completed.";
    if(this->parameters->printMode == 0){
        cout <<"\n\n Reading the target sequences: \n";
    }
    this->parameters->number_of_query_sequences = this->sequences->getSequences()->size();
    sequences->readInputSequences(this->parameters->filenames[1], this->parameters->sub_sequence_width, this->parameters->number_of_sequences, this->parameters->sequence_min_length, this->parameters->file_type,
            this->parameters->printMode);
    this->parameters->number_of_input_sequences = this->sequences->getSequences()->size() - this->parameters->number_of_query_sequences;
    //cout <<"\n\n Reading of the target sequences is completed.";
    this->run();
}


void LSHHandler::pairWiseSimilarityCheck(){
    if(this->parameters->printMode == 0){
      cout <<"\n Reading the input sequences: \n";
    }

    sequences->readInputSequences(this->parameters->filenames[0], this->parameters->sub_sequence_width, this->parameters->number_of_sequences, this->parameters->sequence_min_length, this->parameters->file_type,
            this->parameters->printMode);
    //cout <<"\n\n Reading of the input sequences is completed.";
    this->run();
}

void LSHHandler::run(){
    /**

    Print Modes: 0 means detailed print mode.
    Print Modes: 1 means just output similar sequences for query sequences.
    **/
    sequences->indexSequences();
    sequences->computeSubSequencesSetsUnion();
    sequences->computeSubSequencesSetsUnionMap();
    sequences->computeSequencesMaps();
    
    sequences->initializeSequenceSignatureGenerator(this->parameters->number_of_hashes);
    sequences->initializeSignatures();
    sequences->computeSequencesSignatures();


    Sequence * firstSequence = (*(sequences->getSequences()->begin()));
    int firstSequenceSize = firstSequence->getSequenceSize();

    int numberOfKMERS = firstSequenceSize - this->parameters->sub_sequence_width + 1;

    float estimatedNumberOfDistinctKMERS = this->parameters->toleranceLimit*this->parameters->sub_sequence_width;
    float estimatedMinimumSimilarityRatio = (float)(numberOfKMERS - estimatedNumberOfDistinctKMERS)/(float)(numberOfKMERS + estimatedNumberOfDistinctKMERS);
    float reductionFactor = 0.95;
    estimatedMinimumSimilarityRatio *= reductionFactor;

    if(estimatedMinimumSimilarityRatio < this->parameters->min_signatures_similarity_ratio){
        this->parameters->setMinSignaturesSimilarityRatio(estimatedMinimumSimilarityRatio);
    }

    if(this->parameters->printMode == 0){
        cout << "\n\nPrinting Parameters: \n";
        cout << "\nSequence size: " << firstSequenceSize << "\n";
        cout << "\nNumber of k-mers: " << numberOfKMERS << "\n";
        cout << "\nTolerance limit: " << this->parameters->toleranceLimit << "\n";
        cout << "\nSubsequence Width: " << this->parameters->sub_sequence_width << "\n";
        cout << "\nEstimated Similarity Ratio: " << estimatedMinimumSimilarityRatio << "\n";
        cout << "\nMinimum Signature Similarity Ratio: " << this->parameters->min_signatures_similarity_ratio << "\n";
        sequences->printShinglesMatrix();
        sequences->printSignatures();
    }


    sequences->setLSHMode(this->parameters->hash_type);
    if(this->parameters->hash_type == 1){
        sequences->initializeBuckets(this->parameters->number_of_buckets, this->parameters->number_of_hashes, this->parameters->min_signatures_similarity_ratio);
        cout << "\nAdding sequences to buckets: \n" ;
        sequences->putSequencesToBuckets();
        sequences->computeSimilaritySets();
        if(this->parameters->printMode == 0){
            sequences->printSimilaritySets();
        }
        else{
            sequences->printSimilarSequences(this->parameters->number_of_input_sequences);
        }

    }
    else if(this->parameters->hash_type == 2){
        sequences->initializeBuckets(this->sequences->getSequences()->size(), this->parameters->number_of_hashes, this->parameters->min_signatures_similarity_ratio);
        if(this->parameters->printMode == 0){
            cout << "\nAdding sequences to buckets \n" ;
        }
        sequences->putSequencesToBuckets();
        sequences->computeSequencesSimilarityMatrix();
        if(this->parameters->printMode == 0){
        sequences->printSequencesSimilarityMatrix();
        }
        sequences->computeActualSequencesSimilarityMatrix();
        if(this->parameters->printMode == 0){
        sequences->printActualSequencesSimilarityMatrix();
        }
        sequences->computeSimilaritySets();
        if(this->parameters->printMode == 0){
            sequences->printSimilaritySets();
        }
        else{
            sequences->printSimilarSequences(this->parameters->number_of_query_sequences);
        }
    }
    this->parameters->setMinSignaturesSimilarityRatio(1);
}

Sequences * LSHHandler::getSequences(){
    return this->sequences;
}



