#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 * ---
 * Hint: You can use the debug stream to print initialTX and initialTY, if Thor seems not follow your orders.
 **/
int main()
{
    int lightX; // the X position of the light of power
    int lightY; // the Y position of the light of power
    int initialTX; // Thor's starting X position
    int initialTY; // Thor's starting Y position
    cin >> lightX >> lightY >> initialTX >> initialTY; cin.ignore();
cerr << lightX << " " << lightY << endl << initialTX << " " << initialTY << endl;

    map<int, string>D_x={{-1, "E"}, {0, ""}, {1, "W"}};
    map<int, string>D_y={{-1, "S"}, {0, ""}, {1, "N"}};

    // game loop
    while (1) {
        int remainingTurns; // The remaining amount of turns Thor can move. Do not remove this line.
        cin >> remainingTurns; cin.ignore();

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
cerr << lightX << " " << lightY << endl << initialTX << " " << initialTY << endl;

        string D_tt;
        int x, y;
        x=initialTX-lightX;
        x= x!=0 ? x/abs(x) : 0;
        
        y=initialTY-lightY;
        y= y!=0 ? y/abs(y) : 0;

cerr << x << " " << y << endl;

        D_tt=D_y[y]+D_x[x];

/*        if (initialTX>lightX) { D_x="W"; x=-1; }
        if (initialTX<lightX) { D_x="E"; x=1; }
        if (initialTX==lightX) { D_x=""; x=0; }

        if (initialTY>lightY) { D_y="N"; y=-1; }
        if (initialTY<lightY) { D_y="S"; y=1; }
        if (initialTY==lightY) { D_y=""; y=0; }
*/
        initialTX-=x;
        initialTY-=y;

//        D_tt=D_y+D_x;

        // A single line providing the move to be made: N NE E SE S SW W or NW
        cout << D_tt << endl;
    }
}
