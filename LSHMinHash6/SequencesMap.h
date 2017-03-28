/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SequencesMap.h
 * Author: Srikanth
 *
 * Created on February 6, 2017, 2:30 PM
 */

#ifndef SEQUENCESSETHASH_H
#define SEQUENCESSETHASH_H

using namespace std;

#include <map>
#include <string>
#include <iostream>

#include "SequencesSet.h"

class SequencesMap : public map<string,int>{
public:
    SequencesMap();
    SequencesMap(const SequencesMap& orig);
    virtual ~SequencesMap();
    void setSequencesSet(SequencesSet * sequences_set);
    SequencesSet* getSequencesSet();
    void computeSequencesMap();
    void printSequencesMap();
private:
    SequencesSet * sequences_set;

};

#endif /* SEQUENCESETHASH_H */

