#include<bits/stdc++.h>
using namespace std;

const int N=1e7;
vector<bool>isPrime(N, true);

int main()
{
    isPrime[0]=isPrime[1]=false;
    for(int i=2; i<N; i++)
    {
        if(isPrime[i]==true)
        {
            for(int j=2*i; j<N; j+=i)
            {
                isPrime[j]=false;
            }
        }
    }

    for(int i=0; i<100; i++)
    cout<<isPrime[i]<<" ";
    return 0;
}
