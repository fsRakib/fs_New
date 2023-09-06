#include<bits/stdc++.h>
using namespace std;
const int N=10000000;
vector<int>spf(N+1,0), prime;
void linear_sieve(int n)
{
    for(int i=2; i<=n; i++)
    {
        if(spf[i]==0)
        {
            spf[i]=i;
            prime.push_back(i);
        }
        for(int j=0; i*prime[j]<=n; j++)
        {
            spf[i* prime[j]]=prime[j];
            if(prime[j]==spf[i])
                break;
        }
    }

}
int main()
{
    int t;
    cin>>t;
    linear_sieve(N);
    while(t--)
    {
        int m, n;
        cin>>m>>n;

        for(int x: prime)
        {
            if(x>=m&&x<=n)
                cout<<x<<endl;
                if(x>n)
                    break;

        }
        cout<<endl;
    }

    return 0;
}
