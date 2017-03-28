/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Buckets.cpp
 * Author: Srikanth
 * 
 * Created on February 8, 2017, 1:59 AM
 */

#include "Buckets.h"
#include "Bucket.h"
#include "Sequence.h"
#include "SimilaritySet.h"
#include "algorithm"
#include <iostream>

Buckets::Buckets() {
    this->buckets = new vector< Bucket * >();
}

Buckets::Buckets(const Buckets& orig) {
}

Buckets::~Buckets() {
}

void Buckets::setMode(int mode){
    this->mode = mode;
}

int Buckets::getMode(){
    return this->mode;
}

void Buckets::setBucketsSize(int size){
    this->number_of_buckets = size;
}
int Buckets::getBucketsSize(){
    return this->number_of_buckets;
}
void Buckets::initializeBuckets(){
    Bucket * b;
    for(int index = 1; index <= this->number_of_buckets; ++index){
        b = new Bucket();
        this->buckets->push_back(b);
    }
    //cout << "\n buckets size: " << this->buckets->size() << "\n";
}

void Buckets::initializeBuckets(vector<Sequence *> * sequences){
    Bucket * b;
    Sequence * sequence;
    for(int index = 1; index <= this->number_of_buckets; ++index){
        sequence = (*sequences)[index - 1];
        b = new Bucket();
        b->setBucketSequence(sequence);
        b->setBucketSequenceSignature(sequence->getSignature());
        this->buckets->push_back(b);
    }
}

void Buckets::pushToBuckets(Sequence * sequence, int sequence_index){
    Signature * s = sequence->getSignature();
    int signature_size = s->getSize();
    vector<int> * segment;
    for(int index = 0; index < this->number_of_segments; ++index){
        segment = new vector<int>();
        segment->insert(segment->begin(), s->getSignature()->begin() + index*segment_size, s->getSignature()->begin() +  (index + 1)*segment_size);
        this->addToBucket(bucketMapper(segment), sequence_index);
    }
}

int Buckets::bucketMapper(vector<int> * segment){    
    int sum = 0;
    for(int i = 1; i <= segment->size(); ++i){
        sum = sum + (*segment)[i-1];
    }
    //cout << sum % this->number_of_buckets + 1 << "\n";
    return sum % this->number_of_buckets + 1;
}

void Buckets::pushToSequenceBuckets(Sequence * sequence, int sequence_index){
    //cout << "\n";
    Bucket * b;
    Signature * bucket_sequence_signature, * signature = sequence->getSignature();
    vector<int> *  buckets_list = new vector<int>();
    int total_count = signature->getSize(), matches;
    float ratio;
    for(int index = 1; index <= this->number_of_buckets; ++index){
        b = (*(this->buckets))[index - 1];
        matches = 0;
        bucket_sequence_signature = b->getBucketSequenceSignature();
        for(int index1 = 1; index1 <= signature->getSize(); ++index1 ){
            if(signature->getValueAt(index1 - 1) == bucket_sequence_signature->getValueAt(index1 - 1)){
                ++matches;
            }   
        }
        ratio = (float)matches/(float)(signature->getSize());
        this->addSequenceToBucketSequenceSimilarityRatioToBucket(b->getBucketSequence()->getIndex(), sequence_index, ratio);
        if(ratio >= this->min_signatures_similarity_ratio){
            this->addToBucket(index, sequence_index);
        }
        //cout << " Actual ratio: " << ratio << " threshold: " << this->min_signatures_similarity_ratio << "\n";
    }
}

void Buckets::addSequenceToBucketSequenceSimilarityRatioToBucket(int bucket_index, int sequence_index, float sequence_to_bucket_sequence_similarity_ratio){
    this->buckets->at(bucket_index-1)->setSequenceToBucketSequenceSimilarityRatio(sequence_index, sequence_to_bucket_sequence_similarity_ratio);
    //cout << "\nBucket Index: " << bucket_index << " Sequence Index: " << sequence_index << " Similarity Ratio: " << this->buckets->at(bucket_index-1)->getSequenceToBucketSequenceSimilarityRatio(sequence_index);
}

float Buckets::getSequenceToBucketSequenceSimilarityRatioToBucket(int bucket_index, int sequence_index)
{
    return this->buckets->at(bucket_index-1)->getSequenceToBucketSequenceSimilarityRatio(sequence_index);
}

void Buckets::addToBucket(int bucket_index, int sequence_index){
    //cout << "\nBI: " << bucket_index << " SI: " << sequence_index; 
    this->buckets->at(bucket_index - 1)->push_back(sequence_index);
}

void Buckets::setSegmentSize(int segment_size){
    this->segment_size = segment_size;
}

int Buckets::getSegmentSize(){
    return this->segment_size;
}

void Buckets::setNumberOfHashes(int number_of_hashes){
    this->number_of_hashes = number_of_hashes;
}

int Buckets::getNumberOfHashes(){
    return this->number_of_hashes;
}

void Buckets::setNumberOfSegments(int number_of_segments){
    this->number_of_segments = number_of_segments;
}

int Buckets::getNumberOfSegments(){
    return this->number_of_segments;
}

SimilaritySet * Buckets::getSimilaritySet(int sequence_index){
    SimilaritySet * similarityset = new SimilaritySet();
    Bucket * bucket;
    if(this->mode == 2){
        bucket = this->getSequenceBucketByIndex(sequence_index);
        similarityset->insert(bucket->begin(), bucket->end());

    }
    else{
        vector<int> * seqs_ids;
        for(vector<Bucket *>::iterator bit = this->buckets->begin(); bit != this->buckets->end(); ++bit){
            bucket = *bit;
            Bucket::iterator seq_id_pos = find(bucket->begin(), bucket->end(), sequence_index);
            if(seq_id_pos != bucket->end()){
                similarityset->insert(bucket->begin(), bucket->end());
            }
        }
    }

    similarityset->erase(sequence_index);
    similarityset->setSequenceIndex(sequence_index);
    return similarityset;
}

void Buckets::setMinSigSimRatio(float ratio){
    this->min_signatures_similarity_ratio = ratio;
}

float Buckets::getMinSigSimRatio(){
    return this->min_signatures_similarity_ratio;
}

Bucket * Buckets::getSequenceBucketByIndex(int sequenceIndex){
    Bucket * bucket;
    for(vector<Bucket *>::iterator bit = this->buckets->begin(); bit != this->buckets->end(); ++bit){
        bucket = *bit;
        if(bucket->getBucketSequence()->getIndex() == sequenceIndex){
            return bucket;
        }
    }
    return NULL;
}
