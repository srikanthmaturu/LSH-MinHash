/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Permutations.h
 * Author: Srikanth
 *
 * Created on February 7, 2017, 1:44 PM
 */

#ifndef PERMUTATIONS_H
#define PERMUTATIONS_H

#include <vector>
#include "Permutation.h"

using namespace std;

class Permutations {
public:
    Permutations();
    Permutations(const Permutations& orig);
    virtual ~Permutations();
    vector< Permutation *>* getPermutations();
    void setPermutations(vector< Permutation *>* permutations);
    void generateRandomPermutations(int size, int length);
    void printPermutations();
private:
    vector< Permutation *>* permutations;
};

#endif /* PERMUTATIONS_H */

