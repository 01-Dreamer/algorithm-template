#include <iostream>


using namespace std;
typedef pair<int,int> PII;
const int N=1e5+10;
int p[N],sz[N];
PII stk[N];
int top;
int n;

int find(int x)
{
    if(x!=p[x]) return find(p[x]);
    return x;
}

void merge(int x,int y)
{
    int rx=find(x),ry=find(y);
    if(rx==ry) return;
    if(sz[rx]>sz[ry]) swap(rx,ry);
    stk[++top]={rx,ry};

    p[rx]=ry;
    sz[ry]+=sz[rx];
}

void revoke()
{
    if(!top) return;

    PII t=stk[top--];
    p[t.first]=t.first;
    sz[t.second]-=sz[t.first];
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) p[i]=i,sz[i]=1;

    
    return 0;
}