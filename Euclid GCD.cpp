#include<bits/stdc++.h>
using namespace std;

/// Euclid's Algorithm
int gcd(int a, int b)
{
    if(b==0)
    {
        return a;
    }
    return gcd(b, a%b);
}
int main()
{
    int a,b;
    cin>>a>>b;

   cout <<"Euclid's Algorithm: "<< gcd(a,b) <<endl;

    return 0;
}

