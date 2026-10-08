#pragma once
#include <string>
#include <vector>


class Canvas{
    public:
        Canvas(uint height = 22, uint width = 80);

        void Draw(int x, int y, const string &frame);
        void Render() const;
        void Clear();

    private:
        vector<string> canvas;
        uint height;
        uint width;

    private:
        bool isInside(uint row, uint col);
};



