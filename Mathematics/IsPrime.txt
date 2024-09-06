#include<iostream>

using namespace std;
int n;

bool is_prime(int x)
{
    if(x<2) return false;
    
    for(int i=2;i<=x/i;i++)
       if(x%i==0)
          return false;
    
    return true;      
}


int main()
{
    cin>>n;
    
    int x;
    while(n--)
    {
        cin>>x;
        if(is_prime(x)) cout<<"Yes";
        else cout<<"No";
        cout<<endl;
    }
    
    
    return 0;
}