#include<iostream>
using namespace std;

#include "input_handler.h"

// DEBUGGING
#include "DEBUG.h"

int InputHandler::GetChoice(int low, int high){
    int choice;
    cout << "Choose an option: ";

    while(true){
        if (cin >> choice && choice >= low && choice <= high){
            return choice;
        }

        if (cin.fail()){
            cin.clear();
            cin.ignore(10000, '\n');
        }

        cout << "Invalid input. Please input a number between " << low << " and " << high << ": ";
    }
}