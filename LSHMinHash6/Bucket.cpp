/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Bucket.cpp
 * Author: Srikanth
 * 
 * Created on February 8, 2017, 1:46 AM
 */

#include "Bucket.h"
#include <map>
using namespace std;

Bucket::Bucket() {
    this->bucket_sequence_signature = NULL;
    this->sequences_to_bucket_sequence_similarity_ratios_map = new map<int, float>();
}

Bucket::Bucket(const Bucket& orig) {
}

Bucket::~Bucket() {
}


void Bucket::setBucketSequenceSignature(Signature* bucket_sequence_signature){
    this->bucket_sequence_signature = bucket_sequence_signature;
}

Signature* Bucket::getBucketSequenceSignature(){
    return this->bucket_sequence_signature;
}

void Bucket::setSequenceToBucketSequenceSimilarityRatio(int sequence_index, float similarity_ratio){
    this->sequences_to_bucket_sequence_similarity_ratios_map->insert( pair<int, float>(sequence_index, similarity_ratio));
}

float Bucket::getSequenceToBucketSequenceSimilarityRatio(int sequence_index){
    return this->sequences_to_bucket_sequence_similarity_ratios_map->at(sequence_index);
}

void Bucket::setBucketSequence(Sequence * bucketSequence){
    this->bucketSequence = bucketSequence;
}

Sequence * Bucket::getBucketSequence(){
    return this->bucketSequence;
}
