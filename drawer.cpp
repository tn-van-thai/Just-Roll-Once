#include <iostream>
#include <iomanip>
using namespace std;

// DEBUGGING
#include "DEBUG.h"

#include "drawer.h"
#include "player.h"
#include "timer.h"


Drawer::Drawer(){
    LoadAllAnimations();
}

void Drawer::Draw(const string &name, int fps) const{
    if (animations.count(name)){
        animations.at(name).Play(fps);
    }else{
        debug("drawer.cpp::Draw: " << name << " animation doesn't exist" << '\n');
    }
}


// draw the {name} animation and stats animation
void Drawer::Draw(const string &name, int fps, const Player &player){
    if (animations.count(name)){
        DrawCombinedScene(name, fps, player);
    }else{
        debug("drawer.cpp::Draw: " << name << " animation doesn't exist" << '\n');
    }
}

void Drawer::AddAnimation(const Animation &animation){
    animations.insert({animation.GetName(), animation});
}


void Drawer::LoadAllAnimations(){
    for (const string &name : animationNames){
        Animation animation(name);

        if (animation.IsEmpty()){
            continue;
        }
        
        AddAnimation(animation);
    }
}


void Drawer::DrawCombinedScene(const string &name, int fps, const Player &player){
    if (!animations.count("StatsScene")){
        debug("drawer.cpp::Draw: StatsScene animation doesn't exist");
        return; 
    }

    int delay_ms = FpsToFS(fps);
    int len = max(animations.at(name).GetSize(), animations.at("StatsScene").GetSize());

    debug(len);

    for (int i = 0; i < len; i++){
        canvas.Draw(0, 0, animations.at(name).GetFrame(i));
        canvas.Draw(45, 0, animations.at("StatsScene").GetFrame(i));

        if(i == len - 1){
            if (name == "AchievementScene"){
                canvas.Draw(0, 6, player.GetAchievements().ToString());
            }

            // update the the stats of player to the frame; 
            canvas.Draw(45, 6, player.ToString());
        }
        
        canvas.Render();
        canvas.Clear();
        Timer::Wait(delay_ms);

    }

    // canvas.Draw(0, 0, animations.at("GameScene"));
}

/// @briefly return the delay between every frame
int Drawer::FpsToFS(int fps) const{
    return 1000 / fps;
}