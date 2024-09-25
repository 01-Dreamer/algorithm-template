#include<iostream>

using namespace std;
typedef long long LL;

//  k%i = k-k/i*i;    i->(1,2,3,...,n)

int main()
{
    LL n,k;
    cin>>n>>k;
    
    LL res=n*k;
    for(int l=1,r;l<=n;l=r+1)
    {
        if(k/l==0) break;
        r=min(k/(k/l),n);
        res-=(r-l+1)*(k/l)*(l+r)/2;
    }
    
    cout<<res;
    
    
    return 0;
}