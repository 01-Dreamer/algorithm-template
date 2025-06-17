/*

ax+by=gcd(a,b);

*/

#include<iostream>

using namespace std;

int extend_gcd(int a,int b,int& x,int& y)
{
    if(b==0)
    {
        x=1,y=0;
        return a;
    }
    
    int res=extend_gcd(b,a%b,y,x);
    y-=a/b*x;
    return res;
}


int main()
{
    int t;
    cin>>t;
    int a,b,x,y;
    while(t--)
    {
        cin>>a>>b;
        extend_gcd(a,b,x,y);
        cout<<x<<" "<<y<<endl;
    }
}