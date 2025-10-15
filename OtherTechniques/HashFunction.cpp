typedef unsigned long long ULL;
ULL h(ULL x)
{
    return x*x*x*14541*10086999;
}
ULL f(ULL x)
{
    return h(x&(1<<31)-1)+h(x>>31);
}