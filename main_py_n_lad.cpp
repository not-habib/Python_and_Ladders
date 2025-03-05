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
    Dice d1;
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

    while (true) {
        // Player 1
        cout <<'\n'<<b.p1.getname()<<"'s turn (press Enter to roll)...";
        cin.ignore();
        int roll1 = d1.roll();
        b.traverseboard(b.p1, roll1);
        b.displayboard();
        cout <<'\n'<<b.p1.getname()<<" rolled: " << roll1 << endl;
        cout<<'\n'<<b.p1.getname()<<"'s position is: "<<b.p1.playerposition<<endl;
        if (b.checkWin(b.p1)) {
            cout << " Player "<<b.p1.getname()<<" wins! " << endl;
            break;
        }

        // Player Blue's turn
        cout <<'\n'<<b.p2.getname()<<"'s turn (press Enter to roll)...";
        cin.ignore();
        int roll2 = d1.roll();
        b.traverseboard(b.p2, roll2);
        b.displayboard();
        cout <<'\n'<<b.p2.getname()<<" rolled: " << roll2 << endl;
        cout<<'\n'<<b.p2.getname()<<"'s position is: "<<b.p2.playerposition<<endl;
        if (b.checkWin(b.p2)) {
            cout << " Player "<<b.p2.getname()<<" wins! " << endl;
            break;
        }
    }
    cout<<RESET;
    cout << "Press Enter to exit...";
    cin.get();

    return 0;
}
