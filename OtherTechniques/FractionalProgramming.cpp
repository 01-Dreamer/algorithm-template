#include <bits/stdc++.h>

#define int long long
#define double long double
using namespace std;
typedef pair<int,int> PII;
const int N=1010;
double eps=1e-9;
int a[N],b[N];
double c[N];
int n,k;

bool check(double mid)
{
    vector<double>v;
    for(int i=0;i<n;i++) c[i]=a[i]-mid*b[i];
    sort(c,c+n,[&](double a,double b){return a>b;});
    double res=0;
    for(int i=0;i<n-k;i++) res+=c[i];
    return res>=0;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while(cin>>n>>k,n||k)
    {
        for(int i=0;i<n;i++) cin>>a[i];
        for(int i=0;i<n;i++) cin>>b[i];

        double l=0,r=1;
        while(r-l>eps)
        {
            double mid=(l+r)/2;
            if(check(mid)) l=mid;
            else r=mid;
        }
        cout<<(int)(r*100+0.5)<<'\n';
    }

    return 0;
}
