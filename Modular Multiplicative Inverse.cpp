#include<bits/stdc++.h>
using namespace std;

///Extended Euclid's Algorithm ax+ by= gcd(a, b)
vector<int>extended_gcd(int a, int b)
{
    if(b==0)
        return {1, 0, a}; //return value of x,y

    vector<int> result= extended_gcd(b, a%b);

    //After recursive call is over
    int smallX=result[0];
    int smallY=result[1];
    int gcd= result[2];

    int x=smallY;
    int y=smallX-(a/b)*smallY;

    return{x, y, gcd};
}

///MMI
int modular_multiplicative_inverse(int a, int m)
{
    vector<int>result= extended_gcd(a, m);
    int x=result[0];
    int gcd= result[2];

    if(gcd!=1)
    {
        cout<<"Multiplicative Modulo Inverse doesn't exist";
        return -1;
    }
    int ans= (x%m+m)%m;
    return ans;
}
int main()
{
    int a,m;
    cin>>a>>m;      ///relatively prime

    cout<<modular_multiplicative_inverse(a,m)<<endl;
    return 0;
}
