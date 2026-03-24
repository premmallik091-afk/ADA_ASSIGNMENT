
#include <iostream>
using namespace std;

int fib(int n) {
    int dp[100];
    dp[0]=0; dp[1]=1;
    for(int i=2;i<=n;i++)
        dp[i]=dp[i-1]+dp[i-2];
    return dp[n];
}

int knapsack() {
    int wt[]={10,20,30}, val[]={60,100,120};
    int W=50, n=3;
    int dp[100][100]={0};

    for(int i=1;i<=n;i++){
        for(int w=1;w<=W;w++){
            if(wt[i-1]<=w)
                dp[i][w]=max(val[i-1]+dp[i-1][w-wt[i-1]], dp[i-1][w]);
            else
                dp[i][w]=dp[i-1][w];
        }
    }
    return dp[n][W];
}

int main() {
    cout<<"Fibonacci(10): "<<fib(10)<<endl;
    cout<<"Knapsack: "<<knapsack()<<endl;
    return 0;
}
