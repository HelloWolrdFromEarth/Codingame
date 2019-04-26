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
    int speed;
    cin >> speed; cin.ignore();
    int lightCount;
    cin >> lightCount; cin.ignore();
    int i, j, k;
    int distance[lightCount];
    int duration[lightCount];
    cerr << speed << endl;
    cerr << lightCount << endl;
    for (i = 0; i < lightCount; i++) {
        cin >> distance[i] >> duration[i]; cin.ignore();
        cerr << distance[i] << " " << duration[i] << endl;
    }
    cerr << endl;

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    double spd=(double)speed;
    double nb;
    double dist[lightCount];
    double durat[lightCount];
    int nb_int;
    double etc;
    
    for (i=0; i<lightCount; i++) {
        durat[i]=(double)duration[i];
        dist[i]=(double)distance[i];
    }
    
    speed+=1;
    int test=0;
    while (test==0) {
        speed-=1;
        cerr << "speed=" << speed << endl;
        spd=(double)(speed)*1000.0/3600.0;

        test=1;
        for (i=0; i<lightCount; i++) {
            nb=dist[i]/spd/durat[i];
            nb_int=(int)nb;
//            nb+=0.01;
            etc=nb-(double)(nb_int);
            if (etc>0.99999) { nb_int+=1; }
            
            if (nb_int%2!=0) { test=0; }
            else { cerr << "i=" << i << " nb=" << nb << " nb_int=" << nb_int << " spd=" << speed << " test=" << test << endl; }
        }
    }       
        
    cout << speed << endl;
}
