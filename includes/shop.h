#pragma once

#include "player.h"
#include "dice.h"

class Shop{
    public: 
        void BuyMultiplierUpgrade(Player &player);
        void BuyDiceCountUpgrade(Player &player, Dice &dice);
        void BuyCooldownUpgrade(Player &player);

    private:
        int multiplierLevel = 0; // amount of upgrades for multiplier
        int diceCountLevel = 0; 
        int cooldownLevel = 0;

        // return {stats of upgrade at level, cost}
        tuple<int, int> CalculateMultiplier(int level);
        tuple<int, int> CalculateDiceCount(int level);
        tuple<double, int> CalculateCooldown(int level);

};