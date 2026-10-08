#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <thread>
using namespace std;

// DEBUGGING
#include "DEBUG.h"

#include "animation.h"
#include "timer.h"
#include "utilities.h"


Animation::Animation(string name){
    this->name = name;
    Load(name);
}


void Animation::Print(int ithFrame) const{
    ithFrame = min(static_cast<int>(frames.size() - 1), ithFrame);

    cout << frames.at(ithFrame) << flush;
}


void Animation::Play(int fps) const{
    int delay = FpsToFS(fps);

    // clearScreen();
    for (const string &frame : frames){
        clearScreen();
        cout << frame << flush;
        Timer::Wait(delay);
    }
}

void Animation::Play(int fps, int frame) const{
    int delay = FpsToFS(fps);

    cout << frames.at(frame) << flush;
    Timer::Wait(delay);
}


void Animation::Load(const string &name){
    ifstream inFS("animations/" + name + ".txt");
    
    if (!inFS.is_open()){
        debug("animation.cpp::Load: failed to open " << name << ".txt\n");
        return;
    }

    debug("animation.cpp::Load: opens " << name << ".txt sucessfully\n");

    string frame;
    while(getline(inFS, frame)){
        if (frame == "__FRAME__"){
            frames.push_back(string());
        }else{
            frame.push_back('\n');
            frames.back() += frame;
        }    
    }
}


string Animation::GetFrame(uint ith) const{
    return frames.at(ith);
}


string Animation::GetName() const{
    return name;
}


size_t Animation::GetSize() const{
    return frames.size();
}


bool Animation::IsEmpty() const{
    return frames.size() == 0;
}


int Animation::FpsToFS(int fps) const{
    return 1000 / fps;
}