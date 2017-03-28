/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Permutations.cpp
 * Author: Srikanth
 * 
 * Created on February 7, 2017, 1:44 PM
 */


#include "Permutations.h"

#include <iostream>
#include "Permutation.h"


Permutations::Permutations() {
    this->permutations = new vector< Permutation *> ();
}

Permutations::Permutations(const Permutations& orig) {
}

Permutations::~Permutations() {
}

vector< Permutation *>* Permutations::getPermutations(){
    return this->permutations;
}
void Permutations::setPermutations(vector< Permutation *>* permutations){
    this->permutations = permutations;
}
void Permutations::generateRandomPermutations(int size, int length){
    vector<int> * initial_permutation = new vector<int>();
    for( int i = 1; i <= length; ++i){
        initial_permutation->push_back(i);
    }
    
    Permutation * permutation;
    for (int i = 1; i <= size; ++i){
        permutation = new Permutation();
        permutation->setPermutationSize(length);
        permutation->setInitialSequence(initial_permutation);
        permutation->permutate();
        //permutation->printPermutation();
        this->permutations->push_back(permutation);
    }
}

void Permutations::printPermutations(){
    cout <<"here";
    for(vector<Permutation *>::iterator psit = this->permutations->begin(); psit != this->permutations->end(); ++psit){
        (*psit)->printPermutation();
    }
}

