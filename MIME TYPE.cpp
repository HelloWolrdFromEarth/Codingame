#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int i, j, k, i1, j1, k1;
    
    int N; // Number of elements which make up the association table.
    cin >> N; cin.ignore();
    int Q; // Number Q of file names to be analyzed.
    cin >> Q; cin.ignore();
cerr << N << " " << Q << endl;    

    map<string, string> map1;

    string EXT[N]; // file extension
    string MT[N]; // MIME type.
    int Numb[N]; // int ASCII number of the first letter of "file extension"
    string Letter;
    for (i = 0; i < N; i++) {
        cin >> EXT[i] >> MT[i]; cin.ignore();
        Numb[i]=(int)EXT[i].at(0);
cerr << EXT[i] << " " << MT[i] << " " << Numb[i] << endl;
        transform(EXT[i].begin(), EXT[i].end(), EXT[i].begin(), ::tolower);
        map1.insert(pair<string, string> (EXT[i], MT[i]));
    }
cerr << endl;

    for (i=0; i<N; i++) {
        cerr << map1[EXT[i]] << endl;        
    }

    string FNAME[Q]; // One file name per line.
    for (i = 0; i < Q; i++) {
        getline(cin, FNAME[i]);
cerr << FNAME[i] << endl;        
        transform(FNAME[i].begin(), FNAME[i].end(), FNAME[i].begin(), ::tolower);
    }
cerr << endl;

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    // For each of the Q filenames, display on a line the corresponding MIME type. If there is no corresponding type, then display UNKNOWN.
    int count;
    int first, last;
    string etc_str;
    for (i=0; i<Q; i++) {
        count=0;
        size_t found_ext=FNAME[i].rfind(".");
        if ((int)found_ext<0 || (int)found_ext==FNAME[i].size()-1) { cout << "UNKNOWN" << endl; }
        else {
            etc_str.clear();
            etc_str.append(FNAME[i], (int)found_ext+1, FNAME[i].size());
            if (map1.count(etc_str)>0) {
                cout << map1.find(etc_str)->second << endl;
            }
            else {
                cout << "UNKNOWN" << endl; 
            }
        }
    }

}
