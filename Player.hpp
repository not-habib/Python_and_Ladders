#pragma once
#include <string>
class Player{
    public:
    std::string playername;
    int playerposition = 0;
    void setname(std::string name){
        playername = name;
    }
    std::string getname(){
        return playername;
    }
    char getinit(){
        return playername[0];
    }
};