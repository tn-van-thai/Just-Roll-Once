#include <cmath>
#include <iostream>
using namespace std;

// DEBUGGING
#include "DEBUG.h"

#include "shop.h"
#include "timer.h"

void Shop::BuyMultiplierUpgrade(Player &player){
    auto [value, cost] = CalculateMultiplier(multiplierLevel + 1);

    if (player.SpendMoney(cost)){
        player.SetMultiplier(value);
        multiplierLevel++;
        debug("bought multiplier upgrade level " << multiplierLevel << " for $" << cost << '\n');
    }else{
        cout << "This upgrade costs: $" << cost << '\n'; 
        Timer::Wait(1000);
    }
}


void Shop::BuyDiceCountUpgrade(Player &player, Dice &dice){
    auto [value, cost] = CalculateDiceCount(diceCountLevel + 1);

    if (player.SpendMoney(cost)){
        player.SetDiceCount(value);
        dice.AddDice();
        diceCountLevel++;
        debug("bought dice count upgrade level " << diceCountLevel << " for $" << cost << '\n');
    }else{
        cout << "This upgrade costs: $" << cost << '\n'; 
        Timer::Wait(1000);
    }
}


void Shop::BuyCooldownUpgrade(Player &player){
    auto [value, cost] = CalculateCooldown(cooldownLevel + 1);

    if (player.SpendMoney(cost)){
        player.SetCooldown(value);
        cooldownLevel++;
        debug("bought cooldown upgrade level " << cooldownLevel << " for $" << cost << '\n');
    }else{
        cout << "This upgrade costs: $" << cost << '\n'; 
        Timer::Wait(1000);
    }

}

// value, cost
tuple<int, int> Shop::CalculateMultiplier(int level){
    return {1 + level + level * (level / 20), 10 * level};
} 


// value, cost
tuple<int, int> Shop::CalculateDiceCount(int level){
    return {1 + level, 100 * pow(1.3, level)};
}


// value, cost
tuple<double, int> Shop::CalculateCooldown(int level){
    return {Player::BASE_COOLDOWN * pow(0.9, level), 20 * level * level};
}


