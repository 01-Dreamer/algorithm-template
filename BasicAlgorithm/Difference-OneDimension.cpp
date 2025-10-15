#include<iostream>

using namespace std;
const int N=100010;
int s[N];
int n,m;

void insert(int l,int r,int v)
{
    s[l]+=v,s[r+1]-=v;
}

int main()
{
    scanf("%d%d",&n,&m);
    
    int x;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        insert(i,i,x);
    }
    
    int l,r,v;
    while(m--)
    {
        scanf("%d%d%d",&l,&r,&v);
        insert(l,r,v);
    }
    
    for(int i=1;i<=n;i++)
    {
        s[i]+=s[i-1];
        printf("%d ",s[i]);
    }
    
    return 0;
}