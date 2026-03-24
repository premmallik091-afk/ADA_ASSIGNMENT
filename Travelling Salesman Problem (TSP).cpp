#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int graph[4][4]={
        {0,10,15,20},
        {10,0,35,25},
        {15,35,0,30},
        {20,25,30,0}
    };

    int path[]={1,2,3};
    int min_cost=999;

    do {
        int cost=0, k=0;

        for(int i=0;i<3;i++){
            cost+=graph[k][path[i]];
            k=path[i];
        }

        cost+=graph[k][0];
        min_cost=min(min_cost,cost);

    } while(next_permutation(path,path+3));

    cout<<"TSP Cost: "<<min_cost;

    return 0;
}
