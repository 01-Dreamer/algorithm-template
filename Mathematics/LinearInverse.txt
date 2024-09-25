#include<iostream>

using namespace std;
typedef long long LL;
const int N=3e6+10;
int inv[N];
int n,p;


int main()
{
    cin>>n>>p;
    
    inv[1]=1;
    for(int i=2;i<=n;i++)
       inv[i]=(LL)(p-p/i)*inv[p%i]%p;
    
    for(int i=1;i<=n;i++)
       printf("%d\n",inv[i]);
       
    
    return 0;
}