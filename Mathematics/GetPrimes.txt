#include <iostream>

using namespace std;
const int N=1e6+10;
int primes[N],cnt;
bool st[N];


void get_primes(int x)
{
    for(int i=2;i<=x;i++)
    {
        if(!st[i]) primes[cnt++]=i;
        for(int j=0;primes[j]<=x/i;j++)
        {
            st[i*primes[j]]=true;
            if(i%primes[j]==0) break;
        }
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin>>n;
    
    get_primes(n);
    cout<<cnt<<'\n';
    
    
    return 0;
}