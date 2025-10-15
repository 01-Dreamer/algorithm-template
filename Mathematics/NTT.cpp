#include<iostream>


using namespace std;
typedef long long LL;
const int MOD=998244353,G=3,Gi=332748118;
const int N=3e5+10;
LL a[N],b[N];
int rev[N];
int bit,tot;
 int n,m;

LL qmi(LL a,LL n)
{
    LL res=1;
    while(n)
    {
        if(n&1) res=res*a%MOD;
        a=a*a%MOD;
        n>>=1;
    }
    return res;
}

void NTT(LL a[],int type)
{
    for(int i=0;i<tot;i++)
        if(i<rev[i]) swap(a[i],a[rev[i]]);

    for(int mid=1;mid<tot;mid*=2)
    {
        LL w1=qmi(type==1?G:Gi,(MOD-1)/(2*mid));
        for(int i=0;i<tot;i+=mid*2)
        {
            LL wk=1;
            for(int j=0;j<mid;j++,wk=wk*w1%MOD)
            {
                LL x=a[i+j];
                LL y=wk*a[i+j+mid]%MOD;
                a[i+j]=(x+y)%MOD;
                a[i+j+mid]=(x-y+MOD)%MOD;
            }
        }
    }
}


int main()
{
    cin>>n>>m;
    for(int i=0;i<=n;i++) cin>>a[i];
    for(int i=0;i<=m;i++) cin>>b[i];

    while((1<<bit)<n+m+1) bit++;
    tot=1<<bit;

    for(int i=0;i<tot;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(bit-1));
    
    NTT(a,1),NTT(b,1);
    for(int i=0;i<tot;i++) a[i]=a[i]*b[i]%MOD;
    NTT(a,-1);

    int inv_tot=qmi(tot,MOD-2);
    for(int i=0;i<n+m+1;i++) cout<<a[i]*inv_tot%MOD<<' ';
    
    
    return 0;
}