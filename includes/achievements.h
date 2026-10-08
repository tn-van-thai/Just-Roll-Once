#pragma once

#include <vector>

#include <achievement.h>

class Achievements{
    public:
        // Achievements();

        void Add(const Achievement &query);
        void Update();

        string ToString() const;

    private:
        vector<Achievement> achievements;

        // void LoadAllAchievements();
};