#include<bits/stdc++.h>
using namespace std;
vector<int>sieve(int n)
{
    vector<bool>isPrime(n+1);

    for(int i=2; i*i<=n; i++)
        if(!isPrime[i])
            for(int j=2*i; j<=n; j+=i)
                isPrime[j]=true;

    vector<int>res;
    for(int i=2; i<=n; i++)
        if(!isPrime[i])
            res.push_back(i);

    return res;
}

void segmentedSieve(int l, int h)
{
    int root_h=sqrt(h);
    vector<bool> segment(h-l+1);
    vector<int>primes=sieve(root_h);

    for(int prime: primes)
    {
        int firstMultiple= (l/prime)*prime;

        if(firstMultiple<l)
            firstMultiple+=prime;

        for(int j=max(firstMultiple, prime*prime); j<=h; j+=prime)
            segment[j-l]=true;
    }

    for(int i=l; i<=h; i++)
        if(!segment[i-l] && i!=1)
            cout<<i<<" ";
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,h;
        cin>>l>>h;
        segmentedSieve(l,h);
        cout<<endl;
    }
    return 0;
}
