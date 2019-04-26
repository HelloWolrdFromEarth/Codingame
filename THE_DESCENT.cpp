#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * The while loop represents the game.
 * Each iteration represents a turn of the game
 * where you are given inputs (the heights of the mountains)
 * and where you have to print an output (the index of the mountain to fire on)
 * The inputs you are given are automatically updated according to your last actions.
 **/
int main()
{
    int etc_int;
    int nb;
    // game loop
    while (1) {
        int mountainH=-1; // represents the height of one mountain.
        nb=-1;
        for (int i = 0; i < 8; i++) {
            cin >> etc_int; cin.ignore();
            if (etc_int>mountainH) { mountainH=etc_int; nb=i; }
        }

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        cout << nb << endl; // The index of the mountain to fire on.
    }
}
