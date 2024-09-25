#include<iostream>
#include<unordered_map>

// h = g * f
// g(1)s(n)=h(i)(i:1,2,3,...,n)-g(i)s(n/i)(i:2,3,4,...,n)

using namespace std;
typedef long long LL;
const int N=1e6+10;
int primes[N],cnt;
LL sphi[N],smo[N];
bool st[N];

void get_primes(int n)
{
    sphi[1]=smo[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(!st[i])
        {
            primes[cnt++]=i;
            sphi[i]=i-1;
            smo[i]=-1;
        }
        for(int j=0;primes[j]<=n/i;j++)
        {
            st[i*primes[j]]=true;
            if(i%primes[j]==0)
            {
                sphi[i*primes[j]]=sphi[i]*primes[j];
                //mo[i*primes[j]]=0;
                break;
            }
            sphi[i*primes[j]]=sphi[i]*(primes[j]-1);
            smo[i*primes[j]]=-smo[i];
        }
    }
    for(int i=1;i<=n;i++)
    {
        sphi[i]+=sphi[i-1];
        smo[i]+=smo[i-1];
    }
}

unordered_map<LL,LL>sum_phi;
LL s_phi(LL n)
{
    if(n<N) return sphi[n];
    if(sum_phi.count(n)) return sum_phi[n];
    
    LL res=n*(n+1)/2;
    for(LL l=2,r;l<=n;l=r+1)
    {
        r=n/(n/l);
        res-=s_phi(n/l)*(r-l+1);
    }
    
    return sum_phi[n]=res;
}

unordered_map<LL,LL>sum_mo;
LL s_mo(LL n)
{
    if(n<N) return smo[n];
    if(sum_mo.count(n)) return sum_mo[n];
    
    LL res=1;
    for(LL l=2,r;l<=n;l=r+1)
    {
        r=n/(n/l);
        res-=s_mo(n/l)*(r-l+1);
    }
    
    return sum_mo[n]=res;
}


int main()
{
    get_primes(N-1);
    
    int T;
    scanf("%d",&T);
    
    LL n;
    while(T--)
    {
        scanf("%lld",&n);
        printf("%lld %lld\n",s_phi(n),s_mo(n));
    }
    
    
    return 0;
}