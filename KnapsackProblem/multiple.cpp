#include<iostream>

using namespace std;
const int N=12010,M=2010;
int v[N],w[N],f[N];
int n,m;


int main()
{
    scanf("%d%d",&n,&m);
    
    int cnt=0;
    int a,b,s;
    while(n--)
    {
        scanf("%d%d%d",&a,&b,&s);
        
        int k=1;
        while(s>=k)
        {
            cnt++;
            v[cnt]=a*k;
            w[cnt]=b*k;
            s-=k;
            k<<=1;
        }
        if(s)
        {
            cnt++;
            v[cnt]=a*s;
            w[cnt]=b*s;
        }
    }

    n=cnt;
    for(int i=1;i<=n;i++)
       for(int j=m;j>=v[i];j--)
          f[j]=max(f[j],f[j-v[i]]+w[i]);
          
    printf("%d",f[m]);      

    
    return 0;
}