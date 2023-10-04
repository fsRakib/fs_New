#include<bits/stdc++.h>
using namespace std;

// Extended Euclid's Algorithm ax + by = gcd(a,b)
vector<int>extended_gcd(int a, int b)
{
    if(b==0)
    {
        return {1,0, a};
    }
    vector<int>res=extended_gcd(b, a%b);

    //after recursive call
    int smallX=res[0];
    int smallY=res[1];
    int gcd=res[2];

    int x=smallY;
    int y=smallX-(a/b)*smallY;

    return {x,y, gcd};
}
int main()
{
    int a,b;
    cin>>a>>b; //relatively prime

    vector<int>ans=extended_gcd(a,b);
    cout<<ans[0]<<" and "<<ans[1]<<", gcd: "<<ans[2]<<endl;
    return 0;
}
