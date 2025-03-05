#include <iostream>
#include <string>
#include "Player.hpp"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define RESET "\033[0m" 

using namespace std;

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
        player.playerposition += roll; // Move player
        if (player.playerposition > 100) player.playerposition = 100; // Cap at 100
    }

    bool checkWin(Player &player) {
        return player.playerposition == 100;
    }
};
