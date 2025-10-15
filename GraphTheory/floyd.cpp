#include<iostream>
#include<cstring>

using namespace std;
const int N=210;
int g[N][N];
int n,m,q;

void floyd()
{
    for(int k=1;k<=n;k++)
       for(int i=1;i<=n;i++)
          for(int j=1;j<=n;j++)
             g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
}


int main()
{
    scanf("%d%d%d",&n,&m,&q);
    
    int a,b,c;
    memset(g,0x3f,sizeof g);
    for(int i=1;i<=n;i++) g[i][i]=0;
    while(m--)
    {
        scanf("%d%d%d",&a,&b,&c);
        g[a][b]=min(g[a][b],c);
    }
    
    
    floyd();
    while(q--)
    {
        scanf("%d%d",&a,&b);
        if(g[a][b]>0x3f3f3f3/2) puts("impossible");
        else printf("%d\n",g[a][b]);
    }
    
    
    return 0;
}