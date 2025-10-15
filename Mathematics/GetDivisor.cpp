#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int n;

void get_divisors(int x)
{
    vector<int>res;
    for(int i=1;i<=x/i;i++)
       if(x%i==0)
       {
           res.push_back(i);
           if(i!=x/i) res.push_back(x/i);
       }
       
    sort(res.begin(),res.end());
    for(int i:res) cout<<i<<" ";
    cout<<endl;
}


int main()
{
    cin>>n;
    
    int x;
    while(n--) cin>>x,get_divisors(x);
    
    
    return 0;
}