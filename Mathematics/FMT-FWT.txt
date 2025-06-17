#include <iostream>
#include <cstring>

using namespace std;
typedef long long LL;
const int N=(1<<17)+10;
LL A[N],B[N],a[N],b[N];
const int MOD=998244353;
int n;

LL qmi(LL a,LL n)
{
    LL res=1;
    while(n)
    {
        if(n&1) res=(res*a)%MOD;
        a=(a*a)%MOD;
        n>>=1;
    }
    return res;
}

void init()
{
    memcpy(a,A,sizeof A);
    memcpy(b,B,sizeof B);
}

void get()
{
    for(int i=0;i<n;i++) a[i]=(a[i]*b[i])%MOD;
}

void out()
{
    for(int i=0;i<n;i++) cout<<a[i]<<' ';
    cout<<'\n';
}

void OR(LL f[],int op)
{
    for(int o=2,k=1;o<=n;o<<=1,k<<=1)
        for(int i=0;i<n;i+=o)
            for(int j=0;j<k;j++)
                f[i+j+k]=(f[i+j+k]+f[i+j]*op)%MOD;
}

void AND(LL f[],int op)
{
    for(int o=2,k=1;o<=n;o<<=1,k<<=1)
        for(int i=0;i<n;i+=o)
            for(int j=0;j<k;j++)
                f[i+j]=(f[i+j]+f[i+j+k]*op)%MOD;
}

void XOR(LL f[],int op)
{
    for(int o=2,k=1;o<=n;o<<=1,k<<=1)
        for(int i=0;i<n;i+=o)
            for(int j=0;j<k;j++)
            {
                f[i+j]=(f[i+j]+f[i+j+k])%MOD;
                f[i+j+k]=(f[i+j]-f[i+j+k]-f[i+j+k]+MOD*2)%MOD;
                f[i+j]=f[i+j]*op%MOD;
                f[i+j+k]=f[i+j+k]*op%MOD;
            }
}

int main()
{
    cin>>n;
    n=1<<n;
    for(int i=0;i<n;i++) cin>>A[i];
    for(int i=0;i<n;i++) cin>>B[i];
    
    init(),OR(a,1),OR(b,1),get(),OR(a,MOD-1),out();
    init(),AND(a,1),AND(b,1),get(),AND(a,MOD-1),out();
    init(),XOR(a,1),XOR(b,1),get(),XOR(a,qmi(2,MOD-2)),out();
    
    
    return 0;
}