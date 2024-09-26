#include<iostream>

using namespace std;
const int N=1e6+10;
int dp[N];

//f[n]=(f[n-1)+m)%n  公式下标从0开始

int main()
{
    int n,k;
    cin>>n>>k;
    
    //dp[1]=0;
    for(int i=2;i<=n;i++)
        dp[i]=(dp[i-1]+k)%i;

    cout<<dp[n]+1;
    
    
    return 0;
}