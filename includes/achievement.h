#pragma once

#include <string>

class Achievement{
    public: 
        Achievement(const long long &trackedValue, string desciption, long long goal);

        void Update();
        bool Unlocked() const;
        string ToString() const;

    private:
        const long long &trackedValue;
        string desciption; 
        long long goal;

        bool unlocked = false;

    private:
        string GetUnlockedString() const;
};