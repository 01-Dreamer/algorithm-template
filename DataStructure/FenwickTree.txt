#include<iostream>

using namespace std;
const int N=100010;
int tr[N];
int n,m;

int lowbit(int x)
{
    return x&-x;
}

void add(int x,int v)
{
    for(int i=x;i<=n;i+=lowbit(i)) tr[i]+=v;
}

int query(int x)
{
    int res=0;
    for(int i=x;i>=1;i-=lowbit(i)) res+=tr[i];
    return res;
}

int main()
{
    scanf("%d%d",&n,&m);
    
    int x;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        add(i,x);
    }
    
    int k,a,b;
    while(m--)
    {
        scanf("%d%d%d",&k,&a,&b);
        if(k) add(a,b);
        else printf("%d\n",query(b)-query(a-1));
    }
    
    
    
    return 0;
}