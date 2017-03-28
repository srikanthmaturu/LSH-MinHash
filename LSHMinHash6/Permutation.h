/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Permutation.h
 * Author: Srikanth
 *
 * Created on February 7, 2017, 1:26 PM
 */

#ifndef PERMUTATION_H
#define PERMUTATION_H

#include <vector>
#include <map>

using namespace std;

class Permutation : public map<int, int>{
public:
    Permutation();
    Permutation(const Permutation& orig);
    virtual ~Permutation();
    void permutate();
    void setPermutation(Permutation * p);
    void printPermutation();
    void setPermutationSize(int permutation_size);
    int getPermutationSize();
    void setInitialSequence(vector<int> * initial_sequence);
    int getMapValue(int key);
private:
    int permutation_size;
    vector<int> * initial_sequence;
    vector<int> * permuted_sequence;
};

#endif /* PERMUTATION_H */

