#include<iostream>

using namespace std;
int n;


int main()
{
    cin>>n;
    
    int res=0;
    int x;
    while(n--) cin>>x,res^=x;
    
    if(res) puts("Yes");
    else puts("No");
    
    
    return 0;
}