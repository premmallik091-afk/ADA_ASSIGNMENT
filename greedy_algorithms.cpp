
#include <iostream>
#include <algorithm>
using namespace std;

// Fractional Knapsack
struct Item {
    int value, weight;
};

bool cmp(Item a, Item b) {
    return (double)a.value/a.weight > (double)b.value/b.weight;
}

void knapsack() {
    Item arr[]={{60,10},{100,20},{120,30}};
    int W=50;
    sort(arr,arr+3,cmp);

    double total=0;
    for(int i=0;i<3;i++){
        if(W>=arr[i].weight){
            W-=arr[i].weight;
            total+=arr[i].value;
        } else {
            total+=arr[i].value*((double)W/arr[i].weight);
            break;
        }
    }
    cout<<"Knapsack: "<<total<<endl;
}

// Activity Selection
void activity() {
    int start[]={1,3,0,5,8};
    int finish[]={2,4,6,7,9};

    cout<<"Activities: ";
    int last=0;
    cout<<0<<" ";

    for(int i=1;i<5;i++){
        if(start[i]>=finish[last]){
            cout<<i<<" ";
            last=i;
        }
    }
}

int main() {
    knapsack();
    activity();
    return 0;
}
