#include<iostream>
#include<cstring>

using namespace std;
const int N=510,M=10010;
struct Node
{
    int a,b,c;
}e[M];
int dist[N],last[N];
int n,m,k;

void bellman_ford()
{
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    
    for(int i=0;i<k;i++)
    {
        memcpy(last,dist,sizeof dist);
        for(int j=0;j<m;j++)
        {
            Node& t=e[j];
            dist[t.b]=min(dist[t.b],last[t.a]+t.c);
        }
    }
}


int main()
{
    scanf("%d%d%d",&n,&m,&k);
    
    int a,b,c;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        e[i]={a,b,c};
    }
    
    bellman_ford();
    
    if(dist[n]>0x3f3f3f3f/2) puts("impossible");
    else printf("%d",dist[n]);
    
    
    return 0;
}
