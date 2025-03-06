#pragma once
#include <iostream>
#include <string>
#include "Dice.hpp"
#include "Player.hpp"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RESET "\033[0m" 

using namespace std;
Dice d1;
class Board {
public:
    Player p1, p2; // Two players
    int board[10][10];

    Board() {
        constructboard();
    }

    void constructboard() {
        int x = 100;
        for (int i = 0; i <= 9; i++) {
            if (i % 2 == 0) {  // Left to right
                for (int j = 0; j < 10; j++) {
                    board[i][j] = x--;
                }
            } else {  // Right to left
                for (int j = 9; j >= 0; j--) {
                    board[i][j] = x--;
                }
            }
        }
    }

    void displayboard() {
        cout <<GREEN<< "______________________________________________________________________________\n" <<RESET<< endl;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (board[i][j] == p1.playerposition && board[i][j] == p2.playerposition) {
                cout <<RED<< "/"<<p1.getinit()<<RESET<<"  "<<BLUE<<p2.getinit()<<"\\\t"<<RESET; // Display both players
                } else if (board[i][j] == p1.playerposition) {
                    cout <<RED<< "/ "<<p1.getinit()<<" \\\t"<<RESET; // Display player Red
                } else if (board[i][j] == p2.playerposition) {
                    cout <<BLUE<< "/ "<<p2.getinit()<<" \\\t"<<RESET; // Display player Blue
                } else {
                    cout <<GREEN<< "| " << board[i][j] << " |\t"<<RESET;
                }
            }
            cout << endl;
            cout <<GREEN<< "______________________________________________________________________________\n" <<RESET<< endl;
        }
    }

    void traverseboard(Player &player, int roll) {
    int needed = 100 - player.playerposition; // Steps needed to reach 100

    if (roll > needed) {
        cout <<RED<< player.getname() << " rolled a " << roll << ", which is too high! " 
             << "You need " << needed << " or less to win. Turn skipped.\n" <<RESET;
        return; // Skip turn
    }

    player.playerposition += roll; // Move player
    cout <<GREEN<< player.getname() << " moves to position " << player.playerposition << ".\n" <<RESET;
}

    bool checkWin(Player &player) {
        return player.playerposition == 100;
    }

    void pvp(){
        while (true) {
        // Player 1
        cout <<'\n'<<p1.getname()<<"'s turn (press Enter to roll)...";
        cin.ignore();
        int roll1 = d1.roll();
        traverseboard(p1, roll1);
        displayboard();
        cout <<'\n'<<p1.getname()<<" rolled: " << roll1 << endl;
        cout<<'\n'<<p1.getname()<<"'s position is: "<<p1.playerposition<<endl;
        if (checkWin(p1)) {
            cout << " Player "<<p1.getname()<<" wins! " << endl;
            break;
        }

        // Player Blue's turn
        cout <<'\n'<<p2.getname()<<"'s turn (press Enter to roll)...";
        cin.ignore();
        int roll2 = d1.roll();
        traverseboard(p2, roll2);
        displayboard();
        cout <<'\n'<<p2.getname()<<" rolled: " << roll2 << endl;
        cout<<'\n'<<p2.getname()<<"'s position is: "<<p2.playerposition<<endl;
        if (checkWin(p2)) {
            cout << " Player "<<p2.getname()<<" wins! " << endl;
            break;
        }
    }
    }

};