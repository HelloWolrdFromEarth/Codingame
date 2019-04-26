#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <ctype.h>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int i, j, k, i1, j1, k1;
    
    int L;
    cin >> L; cin.ignore();
    int H;
    cin >> H; cin.ignore();
//cerr << L << " " << H << endl;

    string T;
    getline(cin, T);
//cerr << T << " " << T.size() << endl << endl;
    for (i=0; i<T.size(); i++) {
        T[i]=toupper(T[i]);
//cerr << T[i] << " " << (int)T[i] << endl;
    }

    string ROW[H];
    for (i = 0; i < H; i++) {
        getline(cin, ROW[i]);
cerr << ROW[i] << endl;
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    string answer;
    int nb;
    for (i=0; i<H; i++) {
        for (j=0; j<T.size(); j++) {
            nb=( (int)T[j]>64 && (int)T[j]<91 ) ? ((int)T[j]-65) : 26;
//cerr << T[j] << " " << (int)T[j] << " nb=" << nb << endl;
            answer.append(ROW[i], nb*L, L);
        }
        answer.push_back('\n');
    }        

    cout << answer << endl;
}
