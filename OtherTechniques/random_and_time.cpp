#include <iostream>
#include <chrono>
#include <random>

using namespace std;


int main()
{
    // random
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int>dis_int(1,10);
    uniform_real_distribution<double>dis_real(0.0,1.0);
    for(int i=0;i<100;i++) cout<<dis_int(gen)<<'\n';
    for(int i=0;i<100;i++) cout<<dis_real(gen)<<'\n';

    // time
    auto _start = chrono::system_clock::now();
    auto _end = chrono::system_clock::now();
    while(_end - _start < chrono::milliseconds(1000)) _end = chrono::system_clock::now();


    return 0;
}
