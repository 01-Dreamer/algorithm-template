#include<iostream>
#include<cstring>

using namespace std;
const int N=510,M=1e5+10;
int h[N],e[M],ne[M],idx;
int match[N];
bool st[N];
int n1,n2,m;

void add(int a,int b)
{
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}

bool find(int u)
{
    for(int i=h[u];~i;i=ne[i])
    {
        int j=e[i];
        if(!st[j])
        {
            st[j]=true;
            if(!match[j]||find(match[j]))
            {
                match[j]=u;
                return true;
            }
        }
    }
    return false;
}


int main()
{
    scanf("%d%d%d",&n1,&n2,&m);
    
    int a,b;
    memset(h,-1,sizeof h);
    while(m--)
    {
        scanf("%d%d",&a,&b);
        add(a,b);
    }
    
    int res=0;
    for(int i=1;i<=n1;i++)
    {
        memset(st,0,sizeof st);
        if(find(i)) res++;
    }
    
    printf("%d",res);
    
    
    return 0;
}