#pragma once

#include <vector>

// Animation Handler
class Animation{
    public:
        Animation(string name);
        void Print(int ithFrame) const;
        void Play(int fps) const;
        void Play(int fps, int frame) const;
        void Load(const string &name);

        string GetFrame(uint ith) const;
        string GetName() const;
        size_t GetSize() const;
        
        bool IsEmpty() const;

    private:
        string name;
        vector<string> frames;

        int FpsToFS(int fps) const; // Unit : ms
};