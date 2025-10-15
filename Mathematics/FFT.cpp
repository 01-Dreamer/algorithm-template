#include <iostream>
#include <complex>
#include <cmath>

using namespace std;
const int N=3e5+10;
const double PI=acos(-1);
complex<double> a[N],b[N];
int rev[N],bit,tot;
int n,m;

void fft(complex<double> a[],int type)
{
    for(int i=0;i<tot;i++)
       if(i<rev[i]) swap(a[i],a[rev[i]]);
       
    for(int mid=1;mid<tot;mid<<=1)
    {
        complex<double> w(cos(PI/mid),type*sin(PI/mid));
        for(int i=0;i<tot;i+=mid*2)
        {
            complex<double> wk(1,0);
            for(int j=0;j<mid;j++,wk*=w)
            {
                complex<double> x=a[i+j],y=wk*a[i+j+mid];
                a[i+j]=x+y,a[i+j+mid]=x-y;
            }
        }
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    
    cin>>n>>m;
    for(int i=0;i<=n;i++)
    {
        int x;
        cin>>x;
        a[i].real(x);
    }
    for(int i=0;i<=m;i++)
    {
        int x;
        cin>>x;
        b[i].real(x);
    }
    
    while((1<<bit)<n+m+1) bit++;
    tot=1<<bit;
    
    for(int i=0;i<tot;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(bit-1));
    
    fft(a,1),fft(b,1);
    for(int i=0;i<tot;i++) a[i]*=b[i];
    fft(a,-1);
    
    for(int i=0;i<n+m+1;i++) cout<<(int)(a[i].real()/tot+0.5)<<' ';
    
    
    return 0;
}