#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=100000;
vector<bool>mark(N+1);


void sieve()
{
    for(int i=2; i<=N; i++)
        mark[i]=true;

    for(int i=2; i*i<=N; i++)
    {
        if(mark[i]==true)
        {
            for(int j=i*i; j<=N; j+=i)
                mark[j]=false;
        }
    }
}
vector<int>generate_primes(int R)
{
    vector<int>Prime;
    for(int i=2; i<=R; i++)
    {
        if(mark[i]==true)
            Prime.push_back(i);
    }
    return Prime;
}
int32_t main()
{
    sieve();
    int t;
    cin>>t;
    while(t--)
    {
        int l,r;
        cin>>l>>r;
        vector<int>primes=generate_primes(sqrt(r));

        int segment[r-l+1];
        for(int i=0; i<r-l+1; i++)
            segment[i]=1;

        for(auto pr: primes)
        {
            int firstMultiple= (l/pr)*pr;
            if(firstMultiple<l)
                firstMultiple+=pr;
            //          int firstMultiple= ceil(l/pr)*pr;

            for(int j=max(firstMultiple, pr*pr); j<=r; j+=pr)
                segment[j-l]=0;
        }

        for(int i=l; i<=r; i++)
            if(segment[i-l]==true &&i!=1)
                cout<<i<<endl;
        cout<<endl;

    }
    return 0;
}
