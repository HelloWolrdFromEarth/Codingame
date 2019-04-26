#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int i, j, k;
    double LON, LAT;
    string etc_str;
    cin >> etc_str; cin.ignore();
    size_t found, found1;
    found=etc_str.find(',');
    replace(etc_str.begin(), etc_str.end(), ',', '.');
    LON=stod(etc_str);

    cin >> etc_str; cin.ignore();
    found=etc_str.find(',');
    replace(etc_str.begin(), etc_str.end(), ',', '.');
    LAT=stod(etc_str);
    
    int N;
    cin >> N; cin.ignore();

    string DEFIB;
    string DEFIB_data;
    string result;
    long double dist, dist_s, lon, lat, x, y;
    dist_s=numeric_limits<double>::max();
    for (i = 0; i < N; i++) {
        DEFIB.clear();
        getline(cin, DEFIB);
        found=DEFIB.rfind(";");
        DEFIB_data.clear();
        DEFIB_data=DEFIB.substr(found+1);
        replace(DEFIB_data.begin(), DEFIB_data.end(), ',', '.');
        lat=stod(DEFIB_data);

        DEFIB.erase(found);
        found=DEFIB.rfind(";");
        DEFIB_data.clear();
        DEFIB_data=DEFIB.substr(found+1);
        replace(DEFIB_data.begin(), DEFIB_data.end(), ',', '.');
        lon=stod(DEFIB_data);

        x=(lon-LON)*M_PI/180*cos((lat+LAT)/2*M_PI/180);
        y=(lat-LAT)*M_PI/180;
//        dist=sqrt(x*x+y*y)*6371;
        dist=x*x+y*y;
        if (dist<dist_s) {
//cerr << i << " " << dist << " " << dist_s << endl;
            dist_s=dist;
            
            found=DEFIB.find_first_of(";");
            found1=DEFIB.find(";", found+1);
            result=DEFIB.substr(found+1, found1-found-1);
        }        
    }
    

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;


    cout << result << endl;
}
