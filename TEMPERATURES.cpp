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
 
static bool abs_compare(int a, int b)
{
    return ( abs(a) < abs(b) || (abs(a)==abs(b) && a>b));
}

int main()
{
    int i, j, k, i1, j1, k1;
    
    int n; // the number of temperatures to analyse
    cin >> n; cin.ignore();
cerr << n << endl;

    if (n>0) {
        int input;
        vector<int> t; // a temperature expressed as an integer ranging from -273 to 5526
        for (i = 0; i < n; i++) {
            cin >> input; cin.ignore();
cerr << input << " ";
            t.push_back(input); // a temperature expressed as an integer ranging from -273 to 5526
        }
cerr << endl << t.size() << endl;
    
    
        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        int result;
        result=*min_element(t.begin(), t.end(), abs_compare);
cerr << result << endl;
        cout << result << endl;
    }
    else {
        cout << "0" << endl;
    }
}
