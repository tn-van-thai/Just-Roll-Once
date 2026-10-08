#pragma once
#include <unordered_map>

#include "animation.h"
#include "canvas.h"
#include "player.h"

class Drawer{
    public:
        Drawer();

        void Draw(const string &name, int fps) const;
        void Draw(const string &name, int fps, const Player &player);
        
        void AddAnimation(const Animation &animation);

    private:
        unordered_map<string, Animation> animations;
        Canvas canvas;

        const string animationNames[8] = {
            "DiceRolling",
            "GameScene",
            "MainMenu",
            "QuitScene",
            "ShopScene",
            "StatsScene",
            "TitleScene",
            "AchievementScene"
        };
    
    private:
        void LoadAllAnimations();
        
        void DrawCombinedScene(const string &name, int fps, const Player &player);
        int FpsToFS(int fps) const;

};