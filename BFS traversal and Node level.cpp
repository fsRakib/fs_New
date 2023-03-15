#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int> g[N];
int visited[N];
int level[N];

void BSF(int source)
{
    queue<int>q;
    q.push(source);
    visited[source]=1;
    cout<<"Order of BFS traversal:"<<endl;
    while(!q.empty())
    {
        int current_vertex=q.front();
        q.pop();
        cout<<current_vertex<<" ";
        for(int child : g[current_vertex])
        {
            if(!visited[child])
            {
                q.push(child);
                visited[child]=1;
                level[child]=level[current_vertex]+1;
            }
        }
    }
    cout<<endl;
}
int main()
{
    int n;
    cin>>n;

    for(int i=0; i<n-1; i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    BSF(1);
    for(int i=1; i<=n; i++)
    {
        cout <<"Node: "<<i<<" level: "<<level[i]<<endl;
    }
    return 0;
}
