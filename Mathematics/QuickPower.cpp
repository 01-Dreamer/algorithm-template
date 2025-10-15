#include<iostream>

using namespace std;
typedef long long LL;
int n;

int qmi(int a,int n,int p)
{
    int res=1;
    while(n)
    {
        if(n&1) res=(LL)res*a%p;
        a=(LL)a*a%p;
        n>>=1;
    }
    return res;
}


int main()
{
    cin>>n;
    
    int a,b,p;
    while(n--)
    {
        cin>>a>>b>>p;
        cout<<qmi(a,b,p)<<endl;
    }
    
    
    return 0;
}