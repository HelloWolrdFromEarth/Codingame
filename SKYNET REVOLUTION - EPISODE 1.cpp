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
    int i, j, k, i1, j1, k1;
    
    int N; // the total number of nodes in the level, including the gateways
    int L; // the number of links
    int E; // the number of exit gateways
    cin >> N >> L >> E; cin.ignore();
//cerr << N << " " << L << " " << E << endl <<endl;

    int N1[L]; // N1 and N2 defines a link between these nodes
    int N2[L];
    for (i = 0; i < L; i++) {
        cin >> N1[i] >> N2[i]; cin.ignore();
//cerr << N1[i] << " " << N2[i] << endl;        
    }
//cerr << endl;

    int NB_count[N]; // nb of neighbor
    int NB[N][L]; // neighbor of each node
    for (i=0; i<N; i++) {
        NB_count[i]=0;
        for (j=0; j<L; j++) {
            if (N1[j]==i) { 
                NB[i][NB_count[i]]=N2[j];
                NB_count[i]+=1;
            }
            if (N2[j]==i) { 
                NB[i][NB_count[i]]=N1[j];
                NB_count[i]+=1;
            }
        }
//cerr << i << " " << NB_count[i] << endl;        
for (j=0; j<NB_count[i]; j++) { cerr << NB[i][j] << endl; }
    }

    int EI[E]; // the index of a gateway node
    for (i = 0; i < E; i++) {
        cin >> EI[i]; cin.ignore();
//cerr << EI[i] << endl;
    }
//cerr << endl;

    // calculate the shortest path to each getway node from every other nodes
    int P_count[E][N]; // record the step number to the getway node
    for (i=0; i<E; i++) {
        for (j=0; j<N; j++) {
            P_count[i][j]=L; 
        }
    }
    
    // calculate the step number 
    int count, count1, count2;
    int NB_lvl[N], NB_lvl_count;
    int NB_lvl0[N], NB_lvl_count0;
    int nb_lvl; // limit level nb in one path
    int test;
    nb_lvl=min(5, L/2);
    if (nb_lvl<1) { nb_lvl=1; }
//cerr << nb_lvl << " " << L << endl << endl;

    for (i=0; i<E; i++) {
        count=0;
        P_count[i][EI[i]]=count; 
//cerr << i << " " << EI[i] << " " << P_count[i][EI[i]] << endl;

        NB_lvl_count=NB_count[EI[i]];
        for (j=0; j<NB_lvl_count; j++) {
            NB_lvl[j]=NB[EI[i]][j];
        }
        for (j=0; j<N; j++) {
            NB_lvl0[j]=-1;
        }
        NB_lvl_count0=0;
    
//cerr << endl << "0 0 " << P_count[0][0] << endl << endl;
        for (j=0; j<nb_lvl; j++) {
            count+=1;
            for (k=0; k<NB_lvl_count; k++) {
                if (count<P_count[i][NB_lvl[k]]) {
//cerr << i << " " << NB_lvl[k] << " " << count << " " << P_count[i][NB_lvl[k]] << endl;   
                    P_count[i][NB_lvl[k]]=count; 
//cerr << i << " " << NB_lvl[k] << " " << count << " " << P_count[i][NB_lvl[k]] << endl;   
                }
//cerr << "0 0 " << P_count[0][0] << endl;
                for (i1=0; i1<NB_count[NB_lvl[k]]; i1++) {
                    test=1;
                    for (j1=0; j1<NB_lvl_count0; j1++) {
                        if (NB[NB_lvl[k]][i1]==NB_lvl0[j1]) { test=0; }
                    }
                    if (test>0) {
                        NB_lvl0[NB_lvl_count0]=NB[NB_lvl[k]][i1];
                        NB_lvl_count0+=1;
                    }
                }
            }
            
//cerr << endl << "0 0 " << P_count[0][0] << endl << endl;
//cerr << endl << "before: 0 1 " << P_count[0][1] << endl << endl;


            for (k=0; k<NB_lvl_count0; k++) {
                NB_lvl[k]=NB_lvl0[k];
                NB_lvl0[k]=-1;
//cerr << endl << "here: 0 1 " << P_count[0][1] << " NB_lvl_count0=" << NB_lvl_count0 << " " << k << endl << endl;
            }
            NB_lvl_count=NB_lvl_count0;
            NB_lvl_count0=0;

//cerr << endl << "here: 0 0 " << P_count[0][0] << " NB_lvl_count0=" << NB_lvl_count0 << endl << endl;

        }
//cerr << endl << "0 0 " << P_count[0][0] << endl << endl;
   }

//cerr << endl << "0 0 " << P_count[0][0] << endl << endl;

/*    for (i=0; i<E; i++) {
        for (j=0; j<N; j++) {
            cerr << i << " " << j << " " << P_count[i][j] << endl;
        }
        cerr << endl;
    }
*/
    int SI; // The index of the node on which the Skynet agent is positioned this turn
    int P_min[E], S1[E][N], S_out[E], S2, P_min2;
    
    // game loop
    while (1) {
        cin >> SI; cin.ignore();

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;
        for (i=0; i<E; i++) {
            P_min[i]=P_count[i][NB[SI][0]];
            S_out[i]=NB[SI][0];
            // minimum value
            for (j=0; j<NB_count[SI]; j++) {
                if (P_count[i][NB[SI][j]]<P_min[i]) { 
                    P_min[i]=P_count[i][NB[SI][j]]; 
                    S_out[i]=NB[SI][j];
                }
            }
        }

        S2=S_out[0];
        P_min2=P_min[0];
        for (i=0; i<E; i++) {
            if (P_min[i]<P_min2) { 
                P_min2=P_min[i];
                S2=S_out[i]; 
            }
        }
   
        // Example: 0 1 are the indices of the nodes you wish to sever the link between
        cout << SI << " " << S2 << endl;
    }
}
