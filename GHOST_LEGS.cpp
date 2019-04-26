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
    int W;
    int H;
    cin >> W >> H; cin.ignore();
    int i, j, k, i1, j1, k1;
    string line[H];
    for (i = 0; i < H; i++) {
        getline(cin, line[i]);
    }

    string result;
    int test;
    for (i=0; i<W; i++) {
        if (line[0][i]!=' ') { 
            result.clear();
            result+=line[0][i]; 
            i1=i;
            for (j=0; j<H; j++) {
                // go to right side
                if (line[j][i1+1]=='-') {
                    k=i1+1;
                    while (k<W && line[j][k]=='-') { k+=1; }
                    i1=k;
                }
                else {
                    // go to left side
                    if (line[j][i1-1]=='-') {
                        k=i1-1;
                        while (k>-1 && line[j][k]=='-') { k-=1; }
                        i1=k;
                    }
                }
            }
            result+=line[H-1][k];
            cout << result << endl;
        }
    }

}
