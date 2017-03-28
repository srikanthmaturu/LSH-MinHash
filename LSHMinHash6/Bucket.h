/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Bucket.h
 * Author: Srikanth
 *
 * Created on February 8, 2017, 1:46 AM
 */

#ifndef BUCKET_H
#define BUCKET_H

#include <iostream>
#include <vector>

#include <map>

#include "Signature.h"
#include "Sequence.h"

using namespace std;

class Bucket : public vector<int>{
public:
    Bucket();
    Bucket(const Bucket& orig);
    virtual ~Bucket();
    void setBucketSequenceSignature(Signature * bucket_sequence_signature);
    Signature * getBucketSequenceSignature();
    float getSequenceToBucketSequenceSimilarityRatio(int sequence_index);
    void setSequenceToBucketSequenceSimilarityRatio(int sequence_index, float similarity_ratio);
    map<int, float> * sequences_to_bucket_sequence_similarity_ratios_map;
    void setBucketSequence(Sequence * bucketSequence);
    Sequence * getBucketSequence();
private:
    Signature * bucket_sequence_signature;
    Sequence * bucketSequence;
};

#endif /* BUCKET_H */

