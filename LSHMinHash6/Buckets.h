/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Buckets.h
 * Author: Srikanth
 *
 * Created on February 8, 2017, 1:59 AM
 */

#ifndef BUCKETS_H
#define BUCKETS_H

#include <vector>

#include "Bucket.h"
#include "Sequence.h"
#include "SimilaritySet.h"

using namespace std;

class Buckets {
public:
    Buckets();
    Buckets(const Buckets& orig);
    virtual ~Buckets();
    void setBucketsSize(int size);
    int getBucketsSize();
    void initializeBuckets();
    void initializeBuckets(vector<Sequence *> * sequences);
    void pushToBuckets(Sequence* sequence, int sequence_index);
    int bucketMapper(vector<int> * segment);
    void pushToSequenceBuckets(Sequence * sequence, int sequence_index);
    void addToBucket(int bucket_index, int sequence_index);
    SimilaritySet* getSimilaritySet(int sequence_index);
    void setMode(int mode);
    int getMode();
    void setMinSigSimRatio(float ratio);
    float getMinSigSimRatio();
    void addSequenceToBucketSequenceSimilarityRatioToBucket(int bucket_index, int sequence_index, float sequence_to_bucket_sequence_similarity_ratio);
    float getSequenceToBucketSequenceSimilarityRatioToBucket(int bucket_index, int Sequence_index);
    vector< Bucket * > * buckets;
    void setNumberOfHashes(int number_of_hashes);
    int getNumberOfHashes();
    void setNumberOfSegments(int number_of_segments);
    int getNumberOfSegments();
    void setSegmentSize(int segment_size);
    int getSegmentSize();
    Bucket * getSequenceBucketByIndex(int sequenceIndex);

private:
    int number_of_buckets, number_of_hashes, number_of_segments, segment_size, mode;
    float min_signatures_similarity_ratio;

};

#endif /* BUCKETS_H */

