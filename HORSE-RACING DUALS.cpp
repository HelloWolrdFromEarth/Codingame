#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h> 

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int i, j, k, etc_int;
    
    int N;
    cin >> N; cin.ignore();
    int Pi[N];
    for (i = 0; i < N; i++) {
        cin >> Pi[i]; cin.ignore();
    }
    sort(Pi, Pi+N);

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    k=INT_MAX;
    for (i=1; i<N; i++) {
        etc_int=abs(Pi[i]-Pi[i-1]);
        if (etc_int<k) { k=etc_int; }
    }
            
    cout << k << endl;
}
