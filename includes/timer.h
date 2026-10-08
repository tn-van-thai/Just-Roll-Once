#pragma once

#include <chrono>

class Timer{
    public:
        static void Wait(int delay);

        void Start();
        void End();

        long long GetDurationInMS();

    private:
        // type: chrono::high_resolution_clock::time_point
        chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
        chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();

        chrono::duration<double, std::milli> establish;
};