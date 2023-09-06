#include<bits/stdc++.h>
using namespace std;
#define maxx 100000
vector<int> status(maxx/32), v;


bool varify(int n, int pos)
{
    return (n & (1<<pos));
}

int mark(int n, int pos)
{
    return (n|(1<<pos));
}

void bitwiseSieve()
{
    for(int i=2; i*i<=maxx; i++)
    {
        if(varify(status[i/32], i%32)==false)
            for(int j=2*i; j<=maxx; j+=i)
                status[j/32]=mark(status[j/32], j%32);
    }

    for(int i=2; i<=maxx; i++)
        if(varify(status[i/32], i%32)==false)
            v.push_back(i);

}
int main()
{
    bitwiseSieve();
    int t;
    cin>>t;

    while(t--)
    {
        int m,n;
        cin>>m>>n;

        for (int prime : v)
        {
            if (prime >= m && prime <= n)
                cout << prime << endl;
          else if(prime >n)
                break;
        }
        cout<<endl;
    }

    return 0;
}

