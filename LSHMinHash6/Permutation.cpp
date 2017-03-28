/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Permutation.cpp
 * Author: Srikanth
 * 
 * Created on February 7, 2017, 1:26 PM
 */

#include <algorithm>
#include <string>
#include <iostream>
#include <map>

#include "Permutation.h"

Permutation::Permutation() {
}

Permutation::Permutation(const Permutation& orig) {
}

Permutation::~Permutation() {
}

void Permutation::setPermutationSize(int permutation_size){
    this->permutation_size = permutation_size;
}

int Permutation::getPermutationSize(){
    return this->permutation_size;
}

void Permutation::permutate(){
    this->permuted_sequence = new vector<int>();
    this->permuted_sequence->insert(permuted_sequence->begin(), this->initial_sequence->begin(), this->initial_sequence->end());
    random_shuffle(this->permuted_sequence->begin(), this->permuted_sequence->end());
    for(int index = 1; index <= this->permutation_size; ++index){
        this->insert(pair<int, int>((this->initial_sequence->at(index - 1)), (this->permuted_sequence->at(index - 1))));
    }
}

void Permutation::setPermutation(Permutation * p){
    for(Permutation::iterator pit = p->begin(); pit != p->end(); ++pit){
        this->insert(*pit);
    }
}

void Permutation::printPermutation(){
    string permuted_string = "\n ", initial_string = "\n ";
    for(Permutation::iterator pit = this->begin(); pit != this->end(); ++pit){
        permuted_string.append(to_string((*pit).second) + " ");
        initial_string.append(to_string((*pit).first) + " ");
    }
    cout << "\n IS: "<< initial_string << "\n";
    cout << " PS: "<< permuted_string << "\n";
}

void Permutation::setInitialSequence(vector<int> * initial_sequence){
    this->initial_sequence = initial_sequence;
}

int Permutation::getMapValue(int key){
    return (*(this->find(key))).second;
}