#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int i, j;
    int R;
    cin >> R; cin.ignore();
    int V;
    cin >> V; cin.ignore();
//cerr << R << endl << V << endl;
    int C;
    int N;
    int r_time[R]={};
    for (i = 0; i < V; i++) {
        cin >> C >> N; cin.ignore();
//cerr << C[i] << " " << N[i] << endl;        
        *min_element(r_time, r_time+R)+=(int)pow(10,N)*(int)pow(5,C-N);
    }
   
    cout << *max_element(r_time, r_time+R); 
}
