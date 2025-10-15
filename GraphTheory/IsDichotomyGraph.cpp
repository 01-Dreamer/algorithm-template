#include<iostream>
#include<cstring>

using namespace std;
const int N=1e5+10,M=2*N;
int h[N],e[M],ne[M],idx;
int color[N];
int n,m;

void add(int a,int b)
{
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}

bool dfs(int u,int c)
{
    color[u]=c;
    for(int i=h[u];~i;i=ne[i])
    {
        int j=e[i];
        if(!color[j])
        {
            if(!dfs(j,3-c)) return false;
        }
        else if(color[j]==c) return false;
    }
    return true;
}


int main()
{
    memset(h,-1,sizeof h);
    
    scanf("%d%d",&n,&m);
    
    int a,b;
    while(m--)
    {
        scanf("%d%d",&a,&b);
        add(a,b);
        add(b,a);
    }
    
    for(int i=1;i<=n;i++)
       if(!color[i])
       {
           if(!dfs(i,1))
           {
               puts("No");
               return 0;
           }
               
       }
          
    puts("Yes");
    
    
    return 0;
}
