#include <iostream>
using namespace std;

#include "canvas.h"
#include "utilities.h"

Canvas::Canvas(uint height, uint width): canvas(height, string(width, ' ')), height(height), width(width) {}

/// @brief draw the frame begins at top-left position: (x, y)
void Canvas::Draw(int x, int y, const string &frame){
    int row = y;
    int col = x;

    for (const char &c : frame){
        if (c == '\n'){
            row++;
            col = x;
        }else{
            if (isInside(row, col) == false){
                continue;
            }
            
            canvas[row][col] = c;
            col++;
        }
    } 
}


void Canvas::Render() const{
    clearScreen();
    for (const string &row : canvas){
        cout << row << '\n';
    }
    cout.flush();
}


void Canvas::Clear(){
    for (string &row : canvas){
        fill(row.begin(), row.end(), ' ');
    }
}


bool Canvas::isInside(uint row, uint col){
    return row >= 0 && row < height && col >= 0 && col < width;
}


