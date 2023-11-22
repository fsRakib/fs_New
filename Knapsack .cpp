#include<bits/stdc++.h>
using namespace std;
int v[105],wt[105];
long long dp[105][100005];

long long Knapsack(int idx, int wt_left)
{
    if(wt_left ==0) return 0;
    if(idx<0) return 0;
    if(dp[idx][wt_left]!=-1)
        return dp[idx][wt_left];

    /// Don't choose item at idx
    long long ans= Knapsack(idx-1, wt_left);
    /// Choose item at idx
    if(wt_left - wt[idx]>=0)
        ans = max (ans, Knapsack(idx-1, wt_left - wt[idx])+v[idx]);
    return dp[idx][wt_left]=ans;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int n,w;
    cin>>n>>w;
    for(int i=0; i<n; i++)
    {
        cin>>wt[i] >>v[i];
    }
    cout<<Knapsack(n-1, w);
    return 0;
}
