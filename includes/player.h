#pragma once

#include "achievements.h"

class Player{
    public:
        Player();

        // Getters
        int GetMoney() const;
        int GetMultiplier() const;
        int GetDiceCount() const;
        double GetCooldown() const;
        const Achievements& GetAchievements() const;
        
        bool SpendMoney(long long amount);
        void AddMoney(long long amount);

        // for multiplier
        void SetMultiplier(int value);

        // for diceCount
        void SetDiceCount(int count);
        
        // for cooldown
        void SetCooldown(double seconds);
        
        void UpdateAchievements();
        string ToString() const;
        
    public:
        // const base value, used for calculating 
        static constexpr double BASE_COOLDOWN = 3.0;

    private:
        // to calculate the value each roll
        long long money = 0;
        long long multiplier = 1;
        long long diceCount = 1; // amount of die rolling at once
        double cooldown = BASE_COOLDOWN; // seconds

        // for achievements
        long long totalMoneyEarned = 0;
        long long totalRolls = 0; // 1 roll each die
        long long highestRoll = 0; // total value of all dice in a roll

        // for stats
        long long lastAddedMoney = 0;

        //
        Achievements achievements; 

    private:
        void LoadAllAchievements();
};