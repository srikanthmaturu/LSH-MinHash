/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SequenceSet.h
 * Author: Srikanth
 *
 * Created on February 6, 2017, 12:58 PM
 */

#ifndef SEQUENCESSET_H
#define SEQUENCESSET_H

#include <set>
#include <string>
#include <iostream>

using namespace std;

class SequencesSet : public set<string>{
public:
    SequencesSet();
    SequencesSet(const SequencesSet& orig);
    virtual ~SequencesSet();
    void convertSequence(string sequence);
    void setSubSequenceWidth(int width);
    int getSubSequenceWidth(int width);
    void appendSequences(SequencesSet* append_sequences);
    void printSequencesSet();
private:
    int sub_sequence_width;
};

#endif /* SEQUENCESET_H */

