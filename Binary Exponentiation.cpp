#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+2, MOD=1e9+7;

int binary_exponentiation(int a, int n)
{
    if(n==0)
        return 1;

    int p=(binary_exponentiation(a, n/2))%MOD;

    if(n&1)
    {
        return (((p*p)%MOD)*(a))%MOD;
    }
    else
    {
        return (p*p)%MOD;
    }
}
int32_t main()
{
    int a,n;
    cin>>a>>n;
    cout<<binary_exponentiation(a,n);
    return 0;
}
