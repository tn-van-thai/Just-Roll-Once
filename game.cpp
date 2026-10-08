/// @file game.cpp
/// @brief game launcher
#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

// DEBUGGING
#include "DEBUG.h"

#include "game.h"
#include "animation.h"
#include "utilities.h"

// example of Input InputHandler
// int playerChoice = InputHandler::GetChoice(1, 6);
// cout << "The player choice is: " << playerChoice;
void Game::MainMenuScene(){
    drawer.Draw("MainMenu", 10);

    int choice = InputHandler::GetChoice(1, 4);
    
    switch (choice){
        case 1:
            currentScene = Scene::Game;
            break;

        case 2:
            currentScene = Scene::Shop;
            break;

        case 3:
            currentScene = Scene::Achievement;
            break;

        case 4:
            currentScene = Scene::Quit;
            break;
        default:
            debug("game.cpp::MainMenuScene: Switch default case\n");
            break;
    }
    // Yuhao
    // use clearScreen(); to clear the cmd screen
    // use InputHandler::GetChoice(low, high) to get the user choice between [low, high] (more detail in input_handler.h);
}


void Game::GameScene(){
    // drawer.Draw("GameScene", 5);
    drawer.Draw("GameScene", 5, player);

    int choice = InputHandler::GetChoice(1, 5);

    switch (choice){
        case 1:
            RollAction();

            currentScene = Scene::Game;
            break;

        case 2:
            currentScene = Scene::Shop;
            break;

        case 3:
            currentScene = Scene::Achievement;
            break;

        case 4:
            currentScene = Scene::MainMenu;
            break;

        case 5:
            currentScene = Scene::Quit;
            break;
        
        default:
            debug("game.cpp::GameScene: Switch default case\n");
            break;
    }
}


void Game::ShopScene(){
    drawer.Draw("ShopScene", 5, player);
    
    int choice = InputHandler::GetChoice(1, 6);

    switch(choice){
        case 1:
            shop.BuyMultiplierUpgrade(player);
            break;

        case 2:
            shop.BuyDiceCountUpgrade(player, dice);
            break;

        case 3:
            shop.BuyCooldownUpgrade(player);
            break;

        case 4:
            currentScene = Scene::Game;
            break;

        case 5:
            currentScene = Scene::MainMenu;
            break;

        case 6:
            currentScene = Scene::Quit;
            break;
    
        default:
            debug("game.cpp::ShopScene: Switch default case\n");
            break;
    }
}

void Game::AchievementScene(){
    player.UpdateAchievements();
    drawer.Draw("AchievementScene", 5, player);

    int choice = InputHandler::GetChoice(1, 2);

    switch(choice){
        case 1: 
            currentScene = Scene::Game;
            break; 
        case 2:
            currentScene = Scene::MainMenu;
            break; 
        default:
            debug("game.cpp::AchievementScene: Switch default case\n");
            break;
    }
}


void Game::DebugScene(){
    drawer.Draw("GameScene", 5, player);
    
    
    // drawer.Draw("DiceRolling", 5);

    // RollAction();
    // RollAction();
    // RollAction();
}


void Game::Run(){
    // LoadSavedAchievement();
    // player.AddMoney(10000);

    drawer.Draw("TitleScene", 7);
    Timer::Wait(1000);

    while(currentScene != Scene::Quit){
        switch(currentScene){
            case Scene::MainMenu:
                debug("Entered main menu\n");
                MainMenuScene();
                break;
                
            case Scene::Game:
                debug("Entered game scene\n");
                GameScene();
                break;

            case Scene::Shop:
                debug("Entered shop scene\n");
                ShopScene();
                break;

            case Scene::Stats:
                debug("Entered stats scene\n");
                // StatsScene();
                break;

            case Scene::Achievement:
                debug("Entered achievement scene\n");
                AchievementScene();
                break;

            default: // Debugging scene
                debug("game.cpp::Run: DEBUG: Switch default case, Debugging\n");
                DebugScene();
                return;
        }
        
        debug('\n');
        clearScreen();
    }
    
    // SaveAchievement();

    drawer.Draw("QuitScene", 5);
}


int main()
{
    // freopen("err_log.out", "w", stderr); // write err output to a file

    Game game;
    game.Run();

    // fclose(stderr);

    return 0;
}


void Game::RollAction(){
    if (timer.GetDurationInMS() < player.GetCooldown() * 1000){
        cout << "The roll is on cooldown\n";
        Timer::Wait(500);
        return;
    }
    
    dice.Roll();
    player.AddMoney(dice.CalcReward(player));
    
    debug(dice.CalcReward(player));
    dice.Debug();
    
    drawer.Draw("DiceRolling", 8 * (3.0 / player.GetCooldown()));
    
    timer.Start();
}