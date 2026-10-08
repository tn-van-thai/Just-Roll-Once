#include <iostream>
using namespace std;

#include "achievement.h"

Achievement::Achievement(const long long &trackedValue, string desciption, long long goal)
    : trackedValue(trackedValue), desciption(desciption), goal(goal) {}

void Achievement::Update(){
    unlocked |= (trackedValue >= goal);
}

bool Achievement::Unlocked() const{
    return unlocked;
}

string Achievement::ToString() const{
    return desciption + " " + GetUnlockedString();
}

string Achievement::GetUnlockedString() const{
    return (unlocked ? "[Unlocked]" : "[Locked]");
}




