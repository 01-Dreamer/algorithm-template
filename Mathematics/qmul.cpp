typedef long long ll;
ll qmul(ll a, ll k, ll b)
{
    ll res = 0;
    while (k)
    {
        if (k & 1) res = (res + a) % b;
        a = (a + a) % b;
        k >>= 1;
    }
    return res;
}