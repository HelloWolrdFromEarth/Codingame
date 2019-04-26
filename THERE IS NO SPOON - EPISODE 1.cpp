#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Don't let the machines win. You are humanity's last hope...
 **/
string set_node(int x, int y) {
    string str;

    str.clear();
    str+=to_string(x);
    str+=" ";
    str+=to_string(y);
    str+=" ";

    return str;
}
 
int main()
{
    int width; // the number of cells on the X axis
    cin >> width; cin.ignore();
    int height; // the number of cells on the Y axis
    cin >> height; cin.ignore();
    cerr << "width, height: " << width << " " << height << endl;
    
    int i, j, k, i1, j1;
    string line[height]; // width characters, each either 0 or .
    for (i = 0; i < height; i++) {
        getline(cin, line[i]);
        cerr << line[i] << endl;
    }
        cerr << endl;

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    string output;
    for (i=0; i<width; i++) {
        for (j=0; j<height; j++) {
            if (line[j][i]=='0') {
                output.clear();
                if (line[j][i]=='0') { output+=set_node(i, j); }
                else { output+=set_node(-1, -1); }
    
                i1=i+1;
                while (i1<width) {
                    if (line[j][i1]=='0') {
                        output+=set_node(i1, j); 
                        break;
                    }
                    i1+=1;
                }
                if (i1==width) {
                    output+=set_node(-1, -1); 
                }
//cerr << endl << output << endl;
    
                j1=j+1;
                while (j1<height) {
                    if (line[j1][i]=='0') {
                        output+=set_node(i, j1);
                        break;
                    }
                    j1+=1;
                }
                if (j1==height) {
                    output+=set_node(-1, -1); 
                }
//cerr << endl << output << endl;
    
                cout << output << endl;
            }
        }
    }

    // Three coordinates: a node, its right neighbor, its bottom neighbor
    //cout << "0 0 1 0 0 1" << endl;
}
