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
    int i, j, k, i1, j1, k1, i2, j2, k2;
    int N;
    cin >> N; cin.ignore();
    int L;
    cin >> L; cin.ignore();

    string LINE[N];
    int LI[N][N]={};
    int etc_int;
    for (i = 0; i < N; i++) {
        getline(cin, LINE[i]);
        remove(LINE[i].begin(), LINE[i].end(), ' ');
        LINE[i].resize(N);
        for (j=0; j<LINE[i].size(); j++) {
            if (LINE[i][j]=='C') {
                LI[i][j]=L;
                // set the light level of cuddle's neighbor
                i1=i-L<0 ? 0: i-L;
                i2=i+L<N ? i+L: N;
                j1=j-L<0 ? 0: j-L;
                j2=j+L<N ? j+L: N;
                for (k1=i1; k1<i2; k1++) {
                    for (k2=j1; k2<j2; k2++) {
                        etc_int=L-max(abs(i-k1), abs(j-k2));
                        LI[k1][k2]=max(LI[k1][k2], etc_int);
                    }
                }
            }
            
        }
    }

    for (i=0; i<N; i++) {
        cerr << LINE[i] << " ";
        for (j=0; j<N; j++) {
            cerr << LI[i][j];
        }
        cerr << endl;
    }
    
    etc_int=0;
    for (i=0; i<N; i++) { etc_int+=count(LI[i], LI[i]+N, 0); }
    
    cout << etc_int << endl;
}
