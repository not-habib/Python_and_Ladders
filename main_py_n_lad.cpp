#include "Dice.hpp"
#include "Board.hpp"
#include "Player.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RESET "\033[0m" 

using namespace std;

int main() {
    Board b;

    cout << "Welcome to Python and Ladders!" << endl;
    cout << "Press Enter to roll the dice." << endl;
    string pl1,pl2;
    cout<<"please enter name of player 1"<<endl;
    cin>>pl1;
    cout<<"please enter name of player 2"<<endl;
    cin>>pl2;
        b.p1.setname(pl1);
        b.p2.setname(pl2);
        cin.ignore();
        b.pvp();
    
    cout<<RESET;
    cout<<"Press Enter to exit...";
    cin.get();

    return 0;
}