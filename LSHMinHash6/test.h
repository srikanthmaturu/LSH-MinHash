/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   test.h
 * Author: Srikanth
 *
 * Created on February 6, 2017, 5:13 PM
 */

#ifndef TEST_H
#define TEST_H

#include <string>

using namespace std;


class test {
public:
    test();
    test(const test& orig);
    virtual ~test();
    void setValue(string t);
    string getValue();
private:
    string value;

};

#endif /* TEST_H */

