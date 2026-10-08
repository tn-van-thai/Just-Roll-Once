#pragma once

#include "player.h"
#include "shop.h"
#include "input_handler.h"
#include "drawer.h"
#include "dice.h"
#include "timer.h"
// #include "json.hpp"


enum class Scene{
    MainMenu,
    Game,
    Shop,
    Stats,
    Achievement,
    Quit,

    DiceRolling,

    // debug Scene
    Debug
};


class Game{
    public: 
        void Run(); // controls what the game to display

    private:
        Player player; // holding player's stats
        Shop shop; // handles upgrades
        Drawer drawer;
        Dice dice;
        Timer timer;

        Scene currentScene = Scene::MainMenu;

        void MainMenuScene();
        void GameScene();
        void ShopScene();
        void AchievementScene();

        void DebugScene();

        // 
        void RollAction();
        long long CalculateDiceReward();
};