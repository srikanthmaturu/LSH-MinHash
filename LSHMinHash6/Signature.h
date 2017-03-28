/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Signature.h
 * Author: Srikanth
 *
 * Created on February 7, 2017, 2:48 PM
 */

#ifndef SIGNATURE_H
#define SIGNATURE_H

#include <vector>
using namespace std;

class Signature {
public:
    Signature();
    Signature(const Signature& orig);
    virtual ~Signature();
    vector<int>* getSignature();
    void setSignature(vector<int> * signature);
    int getValueAt(int index);
    int getSize();
    void initializeSignature(int size);
    void setValueAt(int index, int value);
private:
    vector<int>* signature;
};

#endif /* SIGNATURE_H */

