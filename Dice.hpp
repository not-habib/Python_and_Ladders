#pragma once
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

class Dice {
public:
    Dice() {
        srand(time(0));  
    }

    int roll() {
        return rand() % 6 + 1;  
    }

    void rolldice(){
        cout<<"The dice rolled is: "<<roll()<<endl;
    }
};

