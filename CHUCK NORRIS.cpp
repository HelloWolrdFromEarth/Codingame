#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <map>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
 
map<string, string> BiToUn { 
    {"0", "00 0"}, {"1", "0 0"}, {"01", " 0 0"}, {"10", " 00 0"}, {"11", "0"}, {"00", "0"}
};
    
int main()
{
    string MESSAGE;
    getline(cin, MESSAGE);
cerr << MESSAGE << endl;

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    int i, j, k;
    string binary, unary;
    bitset<7> myByte;
    for (i=0; i<MESSAGE.size(); i++) {
        myByte=bitset<7>(MESSAGE[i]); 
//cerr << myByte << endl;
        binary.append(myByte.to_string());
//cerr << binary << endl;
    }
    
    char a;
    string b;
    b.clear();
    unary.clear();
    for (i=0; i<binary.size(); i++) {
        a=binary[i];
        unary.append(BiToUn[b+a]);
//cerr << BiToUn[b+a] << endl;
        b=a;
    }
//cerr << unary << endl;

    cout << unary << endl;
}
