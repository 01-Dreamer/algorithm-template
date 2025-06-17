#include <iostream>

using namespace std;
typedef long long LL;
const int N=1e7+10;
const int MOD=1e9+7;
int primes[N],cnt;
bool st[N];
int n;

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
    cin>>n;
    get_primes(n);

    LL res=1;
    for(int i=0;i<cnt;i++)
    {
        LL p=primes[i];
        while(p*primes[i]<=n) p*=primes[i];
        res=(res*p)%MOD;
    }

    cout<<res<<'\n';


    return 0;
}


////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////


#include <iostream>

using namespace std;
typedef long long LL;
const int N=1e7+10;
const int MOD=1e9+7;
int primes[N],cnt;
LL power[N],L[N];
bool st[N];
int n;

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
    cin>>n;
    get_primes(n);

    for(int i=0;i<cnt;i++)
    {
        LL p=primes[i];
        power[p]=primes[i];
        while(p*primes[i]<=n)
        {
            p*=primes[i];
            power[p]=primes[i];
        }
    }
    
    L[1]=1;
    for(int i=2;i<=n;i++)
       if(power[i]) L[i]=L[i-1]*power[i]%MOD;
       else L[i]=L[i-1];
    

    for(int i=1;i<=n;i++) cout<<L[i]<<'\n';


    return 0;
}








