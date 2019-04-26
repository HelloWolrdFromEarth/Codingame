#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int W; // width of the building.
    int H; // height of the building.
    cin >> W >> H; cin.ignore();
    int N; // maximum number of turns before game over.
    cin >> N; cin.ignore();
    int X0;
    int Y0;
    cin >> X0 >> Y0; cin.ignore();
    // X0, Y0 record the initial step before each jump
    // then, one can avoid the jump-back action

    // indice of the forward direction (x=+1, positive x; x=-1, negative x)
    // Dx: orientation direction (left/right)
    // Dy: verticular direction (up/down)
    int Dx=0, Dy=0;
    int Dx0=Dx, Dy0=Dy;
    // jump via mid-point method
    // X1, Y1 : the nb of windows to the mid-point 
    int X1, Y1;

    int X2, Y2;
    int X3, Y3, X4, Y4;
    X2=0;
    Y2=0;
    X3=W-1;
    Y3=H-1;

    int X=X0, Y=Y0;
    int test_x=0, test_y=0;
    int symbol_x, symbol_y;
    
    int etc_int;
    
    // game loop
    while (1) {
        string bombDir; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        cin >> bombDir; cin.ignore();

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        Dx0=Dx;
        Dy0=Dy;

        Dx=0; 
        Dy=0;
        if (bombDir=="U") { Dy=-1; }
        if (bombDir=="UR") { Dx=1; Dy=-1; }
        if (bombDir=="UL") { Dx=-1; Dy=-1; }
        if (bombDir=="D") { Dy=1; }
        if (bombDir=="DL") { Dx=-1; Dy=1; }
        if (bombDir=="DR") { Dx=1; Dy=1; }
        if (bombDir=="L") { Dx=-1; }
        if (bombDir=="R") { Dx=1; }

        if (Dx==0 && Dy==0) { break; }

        X1=0;
        Y1=0;
        symbol_x=0;
        symbol_y=0;
        
        if (Dx>0) { X2=X; symbol_x=1; }
        if (Dx<0) { X3=X; symbol_x=-1; }
        if (Dy>0) { Y2=Y; symbol_y=1; }
        if (Dy<0) { Y3=Y; symbol_y=-1; }

        if (Dx*Dx0<0) { 
            if (Dx>0) { X2=X; X3=X0; symbol_x=1; }
            else { X2=X0; X3=X; symbol_x=-1; }
        }
        if (Dy*Dy0<0) { 
            if (Dy>0) { Y2=Y; Y3=Y0; symbol_y=1; }
            else { Y2=Y0; Y3=Y; symbol_y=-1; }
        }

        if (Dx!=0) {
            etc_int=abs(X3-X2);
            if (etc_int==1) { X1=(X3-X2)*symbol_x; }
            else { X1=(X3-X2+1)/2*symbol_x; }
        }
        if (Dy!=0) {
            etc_int=abs(Y3-Y2);
            if (etc_int==1) { Y1=(Y3-Y2)*symbol_y; }
            else { Y1=(Y3-Y2+1)/2*symbol_y; }
        }

        X0=X;
        Y0=Y;
      
        X+=X1;
        Y+=Y1;
            
        // the location of the next window Batman should jump to.
        cout << X << ' ' << Y << endl;
    }
    
    cout << "Gotta it!!" << endl;
}
