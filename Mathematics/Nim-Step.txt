#include<iostream>

using namespace std;
int n;


int main()
{
    cin>>n;
    int res=0;
    int x;
    
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        if(i&1) res^=x;
    }
    
    if(res) puts("Yes");
    else puts("No");
    
    
    return 0;
}