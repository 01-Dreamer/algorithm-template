#include<iostream>

using namespace std;
typedef long long LL;
const int N=1e5+10;
LL a[N];
int n;

int gauss()
{
    int k=0;
    for(int i=62;i>=0;i--)
    {
        for(int j=k;j<n;j++)
           if(a[j]>>i&1)
           {
               swap(a[j],a[k]);
               break;
           }
        
        if(!(a[k]>>i&1)) continue;
        
        for(int j=0;j<n;j++)
           if(j!=k&&(a[j]>>i&1))
              a[j]^=a[k];
              
        if(++k==n) break;      
    }
    
    return k;
}


int main()
{
    scanf("%d",&n);
    
    for(int i=0;i<n;i++) scanf("%lld",&a[i]);
    
    int k=gauss();
    
    LL res=0;
    for(int i=0;i<k;i++) res^=a[i];
    
    printf("%lld",res);
    
    
    return 0;
}