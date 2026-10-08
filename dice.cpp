#include<iostream>
using namespace std;

#include "DEBUG.h"

#include "dice.h"

Dice::Dice(int count): dice(count) {}

int Dice::GetValue(uint ith) const{
    if (ith < dice.size()){
        return dice.at(ith).getValue();
    }else
        // debug("Invalid dice\n");
        return -1;
}


size_t Dice::GetSize() const{
    return dice.size();
}


long long Dice::CalcReward(const Player &player){
    long long reward = 0;

    for (const Die &die : dice){
        reward += die.getValue() * player.GetMultiplier();
    }

    return reward;
}


void Dice::AddDice(){
    dice.emplace_back();
}


void Dice::Roll(){
    for (Die &die : dice){
        die.roll();
    }
}


void Dice::Debug() const{
    for (Die die : dice){
        debug(die.getValue() << " ");
    }
    debug("\n");
}















