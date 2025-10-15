#include<iostream>

using namespace std;
typedef long long LL;
const int N=70;
LL p[N];
int n;

void insert(LL x)
{
    for(int i=62;i>=0;i--)
       if(x>>i&1)
       {
           if(p[i]) x^=p[i];
           else
           {
               p[i]=x;
               break;
           }
       }
}


int main()
{
    scanf("%d",&n);
    
    LL x;
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&x);
        insert(x);
    }
    
    LL res=0;
    for(int i=62;i>=0;i--) res=max(res,res^p[i]);
    
    printf("%lld",res);
    
    
    return 0;
}