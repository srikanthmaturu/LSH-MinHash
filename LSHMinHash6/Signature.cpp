/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Signature.cpp
 * Author: Srikanth
 * 
 * Created on February 7, 2017, 2:48 PM
 */

#include "Signature.h"

Signature::Signature() {
    this->signature = new vector<int>();
}

Signature::Signature(const Signature& orig) {
}

Signature::~Signature() {
}

vector<int> * Signature::getSignature(){
    return this->signature;
}

void Signature::setSignature(vector<int> * signature){
    this->signature = signature;
}

int Signature::getValueAt(int index){
    return this->signature->at(index);
}

void Signature::setValueAt(int index, int value){
    (*signature)[index] = value;
}

int Signature::getSize(){
    return this->signature->size();
}

void Signature::initializeSignature(int size){
    for(int index = 1; index <= size; ++index){
        this->signature->push_back(-1);
    }
}