#include <iostream>
#include <string>
using namespace std;

#include "achievements.h"


void Achievements::Add(const Achievement &query){
    achievements.push_back(query);
}


void Achievements::Update(){
    for (Achievement &cur : achievements){
        cur.Update();
    }
}


string Achievements::ToString() const{
    string ans = string();

    for (const Achievement &cur : achievements){
        ans += cur.ToString() + '\n';
    }
    ans.pop_back();

    return ans;
}


// void Achievements::LoadAllAchievements(){
//     Add(achievement(totalMoneyEarned, "First Coin, Reach $1", 1));
//     Add(achievement(totalMoneyEarned, "Pocket Change, Reach $100", 100));
//     Add(achievement(totalMoneyEarned, "Rich, Reach $1,000", 1000));
//     Add(achievement(totalMoneyEarned, "Wealthy, Reach $10,000", 10000));
//     Add(achievement(totalMoneyEarned, "Millionaire, Reach $1,000,000", 1'000'000));
//     Add(achievement(totalMoneyEarned, "Billionaire, Reach $1,000,000,000", 1'000'000'000));
//     Add(achievement(totalMoneyEarned, "Trillionaire, Reach $1,000,000,000,000", 1'000'000'000'000));

//     Add(achievement(totalMoneyEarned, "Trillionaire, Reach $1,000,000,000,000", 1'000'000'000'000));
// }