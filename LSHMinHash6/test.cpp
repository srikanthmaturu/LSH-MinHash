/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   test.cpp
 * Author: Srikanth
 * 
 * Created on February 6, 2017, 5:13 PM
 */

#include "test.h"
#include "Sequence.h"

test::test() {
}

test::test(const test& orig) {
}

test::~test() {
}

void test::setValue(string t){
    this->value = t;
}

string test::getValue(){
    return this->value;
}


test testfun(test t){
    t.setValue("kldajf;lajfdlsjvajboiejotjoaijsf'bosadike_lollollol'sfjdlakfdjklajvlkjwlek");
    cout<< "\n T1 value inside the function (after changed)):" <<t.getValue();
    return t;
}

int main1(int argc, char** argv) {
    test t1, t2;
    t1.setValue("kldajf;lajfdlsjvajboiejotjoaijsf'bosadike_hehehe_lollollol'sfjdlakfdjklajvlkjwlek");
    cout <<  "\n T1 value before function pass: " << t1.getValue();
    t2 = testfun(t1);
    cout << "\n T1 value after function return: " <<t1.getValue();
    
    return 0;
}