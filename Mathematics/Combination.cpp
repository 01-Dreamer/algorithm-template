#include<iostream>

using namespace std;
const int N=2010,MOD=1e9+7;
int C[N][N];

int main()
{
    for(int i=0;i<=2000;i++) C[i][0]=1;
    for(int i=1;i<=2000;i++)
       for(int j=1;j<=i;j++)
           C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
    
    int T;
    
    scanf("%d",&T);
    
    int n,m;
    while(T--)
    {
        scanf("%d%d",&n,&m);
        printf("%d\n",C[n][m]);
    }
    
    
    return 0;
}
///////////////////////////////////////////////
#include<iostream>

using namespace std;
typedef long long LL;
const int N=1e5+10,MOD=1e9+7;
int fact[N],infact[N];

int qmi(int a,int n)
{
    int res=1;
    while(n)
    {
        if(n&1)res=(LL)res*a%MOD;
        a=(LL)a*a%MOD;
        n>>=1;
    }
    return res;
}

inline int C(int n,int m)
{
    return (LL)fact[n]*infact[m]%MOD*infact[n-m]%MOD;
}

int main()
{
    int T;
    scanf("%d",&T);
    
    fact[0]=infact[0]=1;
    for(int i=1;i<N;i++)
    {
        fact[i]=(LL)fact[i-1]*i%MOD;
        infact[i]=(LL)infact[i-1]*qmi(i,MOD-2)%MOD;
    }
    
    int n,m;
    while(T--)
    {
        scanf("%d%d",&n,&m);
        printf("%d\n",C(n,m));
    }
    
    return 0;
}
///////////////////////////////////////////////
#include<iostream>

using namespace std;
typedef long long LL;

int qmi(int a,int n,int p)
{
    int res=1;
    while(n)
    {
        if(n&1) res=(LL)res*a%p;
        a=(LL)a*a%p;
        n>>=1;
    }
    return res;
}

int C(int n,int m,int p)
{
    if(n<m) return 0;
    if(m>n-m) m=n-m;
    int A=1,B=1;
    while(m)
    {
        A=(LL)A*n--%p;
        B=(LL)B*m--%p;
    }
    return (LL)A*qmi(B,p-2,p)%p;
}

int lucas(LL a,LL b,int p)
{
    if(a<p&&b<p) return C(a,b,p);
    return (LL)C(a%p,b%p,p)*lucas(a/p,b/p,p)%p;
}


int main()
{
    int T;
    scanf("%d",&T);
    LL a,b;
    int p;
    while(T--)
    {
        scanf("%lld%lld%d",&a,&b,&p);
        printf("%d\n",lucas(a,b,p));
        
    }
    
    
    
    return 0;
}
///////////////////////////////////////////////
#include<iostream>
#include<vector>

using namespace std;
const int N=5010;
int primes[N],k;
int cnt[N];
bool st[N];

void get_primes(int n)
{
    for(int i=2;i<=n;i++)
    {
        if(!st[i]) primes[k++]=i;
        for(int j=0;primes[j]<=n/i;j++)
        {
            st[i*primes[j]]=true;
            if(i%primes[j]==0) break;
        }
    }
}

int get(int a,int p)
{
    int res=0;
    while(a)
    {
        res+=a/p;
        a/=p;
    }
    return res;
}

vector<int> mul(vector<int>& A,int b)
{
    vector<int>C;
    int t=0;
    for(int i=0;i<A.size()||t;i++)
    {
        if(i<A.size()) t+=A[i]*b;
        C.push_back(t%10);
        t/=10;
    }
    while(C.size()>1&&C.back()==0) C.pop_back();
    return C;
}

int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    get_primes(a);

    for(int i=0;i<k;i++)
    {
        int p=primes[i];
        cnt[i]=get(a,p)-get(a-b,p)-get(b,p);
    }

    vector<int>res{1};
    for(int i=0;i<k;i++)
        for(int j=0;j<cnt[i];j++)
            res=mul(res,primes[i]);

    for(int i=res.size()-1;i>=0;i--) printf("%d",res[i]);


    return 0;
}
///////////////////////////////////////////////