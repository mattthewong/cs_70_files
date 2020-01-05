
#include <string>
#include <iostream>
#include "exchange.hpp"
using namespace std;


void exchange(string& s1,string& s2){

    string temp = s1; //temp variable to hold value of string s1
    s1 = s2; //assign s1 value to s2
    s2 = temp; //assign s2 value to temp (s1)
}
