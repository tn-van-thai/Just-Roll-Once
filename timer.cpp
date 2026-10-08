#include <thread>
using namespace std;

#include "timer.h"

void Timer::Wait(int delay){
    this_thread::sleep_for(std::chrono::milliseconds(delay));
}


void Timer::Start(){
    start = chrono::high_resolution_clock::now();
}


void Timer::End(){
    end = chrono::high_resolution_clock::now();
}


long long Timer::GetDurationInMS(){
    End();
    
    establish = end - start;
    return establish.count();
}



















