#include<iostream>
#include<cstring>

using namespace std;
const int N=110;
int h[N],e[N],ne[N],idx;
int v[N],w[N],f[N][N];
int n,m,root;

void add(int a,int b)
{
    e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

void dfs(int u)
{
    for(int i=h[u];~i;i=ne[i])
    {
        int son=e[i];
        dfs(son);
        
        for(int j=m-v[u];j>=1;j--)
           for(int k=0;k<=j;k++)
              f[u][j]=max(f[u][j],f[u][j-k]+f[son][k]);
    }
    
    for(int i=m;i>=v[u];i--) f[u][i]=f[u][i-v[u]]+w[u];
    for(int i=1;i<v[u];i++) f[u][i]=0;
}


int main()
{
    scanf("%d%d",&n,&m);
    
    memset(h,-1,sizeof h);
    int p;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d",&v[i],&w[i],&p);
        if(p==-1) root=i;
        else add(p,i);
    }
    
    dfs(root);
    printf("%d",f[root][m]);
    
    
    return 0;
}