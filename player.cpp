#include <iostream>
using namespace std;


// DEBUGGING
#include "DEBUG.h"


#include "player.h"


Player::Player(){
    LoadAllAchievements();
}


int Player::GetMoney() const{
    return money;
}


int Player::GetMultiplier() const{
    return multiplier;
}


int Player::GetDiceCount() const{
    return diceCount;
}


double Player::GetCooldown() const{
    return cooldown;
}


void Player::UpdateAchievements(){
    achievements.Update();
}


const Achievements& Player::GetAchievements() const{
    return achievements;
}


/// @brief Spend an amount of money if suffcient
/// @return True if successful; otherwise, returns false
bool Player::SpendMoney(long long amount){
    if (money < amount){
        debug("Insufficient amount of money" << '\n');
        return false;
    }else{
        money -= amount;
        lastAddedMoney = -amount;
        return true;
    }
}


void Player::AddMoney(long long amount){
    money += amount;
    debug("Added money, current player's money: $" << money << '\n');

    totalRolls++;
    highestRoll = max(highestRoll, amount);
    totalMoneyEarned += amount;
    
    lastAddedMoney = amount;
}


void Player::SetMultiplier(int value){
    multiplier = value;
}


void Player::SetDiceCount(int count){
    diceCount = count;
}


void Player::SetCooldown(double seconds){
    cooldown = seconds;
}


string Player::ToString() const{
    return "Money: $" + to_string(money) + "(" + to_string(lastAddedMoney) + ")\n"
        +  "Multiplier: " + to_string(multiplier) + '\n'
        +  "Dice Count: " + to_string(diceCount) + '\n'
        +  "Cooldown: " + to_string(cooldown) + '\n'
        +  "Total Rolls: " + to_string(totalRolls) + '\n'
        +  "Highest Value Roll: $" + to_string(highestRoll) + '\n'
        +  "Total Money Earned: $" + to_string(totalMoneyEarned);
}


void Player::LoadAllAchievements(){
    achievements.Add(Achievement(totalMoneyEarned, "First Coin, Reach $1", 1));
    achievements.Add(Achievement(totalMoneyEarned, "Pocket Change, Reach $100", 100));
    // achievements.Add(Achievement(totalMoneyEarned, "Rich, Reach $1,000", 1000));
    achievements.Add(Achievement(totalMoneyEarned, "Wealthy, Reach $10,000", 10000));
    achievements.Add(Achievement(totalMoneyEarned, "Millionaire, Reach $1,000,000", 1'000'000));
    achievements.Add(Achievement(totalMoneyEarned, "Billionaire, Reach $1,000,000,000", 1'000'000'000));
    // achievements.Add(Achievement(totalMoneyEarned, "Trillionaire, Reach $1,000,000,000,000", 1'000'000'000'000));

    achievements.Add(Achievement(totalRolls, "Dice Lover, 1000 rolls", 1'000));

    achievements.Add(Achievement(multiplier, "Powerhouse, x100", 100));

    achievements.Add(Achievement(diceCount, "Dice Army, Own 10 dice", 10));

    achievements.Add(Achievement(highestRoll, "Incredible, Roll Value >= 1000", 1000));
}

