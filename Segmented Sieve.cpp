#include<bits/stdc++.h>
using namespace std;

const int N=100000;
vector<bool>mark(N+1);  ///By defaul all element are assined as "False"

void sieve()
{
    for(int i=2; i*i<=N; i++)
    {
        if(mark[i]==false)
        {
            for(int j=i*i; j<=N; j+=i)
                mark[j]=true;
        }
    }
}
vector<int>generate_primes(int R)
{
    vector<int>Prime;
    for(int i=2; i<=R; i++)
    {
        if(mark[i]==false)
            Prime.push_back(i);
    }
    return Prime;
}
int main()
{
    sieve();
    int t;
    cin>>t;
    while(t--)
    {
        int l,r;
        cin>>l>>r;
        vector<int>primes=generate_primes(sqrt(r));
        vector<bool> segment(r-l+1);    ///By defaul all element are assined as "False"

        for(int i=0; i<primes.size(); i++)
        {
            int firstMultiple= (l/primes[i]) * primes[i];

            if(firstMultiple<l)
                firstMultiple+=primes[i];

            for(int j=max(firstMultiple, primes[i]*primes[i]); j<=r; j+=primes[i])
                segment[j-l]=true;
        }

        for(int i=l; i<=r; i++)
            if(segment[i-l]==false &&i!=1)
                cout<<i<<endl;

        cout<<endl;
    }
    return 0;
}
