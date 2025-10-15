#include<iostream>

using namespace std;
const int N=100010;
int s[N];
int n,m;


int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&s[i]);
        s[i]+=s[i-1];
    }
    
    int l,r;
    while(m--)
    {
        scanf("%d%d",&l,&r);
        cout<<s[r]-s[l-1]<<endl;
    }

    
    return 0;
}