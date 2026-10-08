#pragma once

#include "die.h"
#include "player.h"

class Dice{
    public:
        Dice(int count = 1);

        int GetValue(uint ith) const;
        size_t GetSize() const;

        long long CalcReward(const Player &player);

        void AddDice();
        void Roll();

        void Debug() const;

    private:
        vector<Die> dice;

};