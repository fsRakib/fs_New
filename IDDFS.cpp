#include<bits/stdc++.h>
using namespace std;

///Depth-Limited Search (DLS)
bool DLS(const vector<vector<int>>& graph, int src, int target, int depthLimit)
{
    if (src == target)
        return true;
    if (depthLimit <= 0)
        return false;
    for (int neighbor : graph[src])

        if (DLS(graph, neighbor, target, depthLimit - 1))
            return true;
    return false;
}

///Iterative Deepening Depth-First Search (IDDFS)
bool IDDFS(const vector<vector<int>>& graph, int src, int target, int maxDepth)
{
    for (int depth = 0; depth <= maxDepth; ++depth)
        if (DLS(graph, src, target, depth))
            return true;
    return false;
}

int main()
{
    int n, m;
    cout << "Enter node : ";
    cin >> n ;
    cout << "Enter edge : ";
    cin>> m;

    // Create the graph as an adjacency list
    vector<vector<int>> graph(n + 1);
    cout << "Enter the edges :" << endl;
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int target, maxDepth, src;
    cout << "source node: ";
    cin >> src;
    cout << "target node: ";
    cin >> target;
    cout << "maximum depth: ";
    cin >> maxDepth;

    if (IDDFS(graph, src, target, maxDepth))
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;

        ///test case
        /*
        7
        6
        0 1
        0 2
        1 3
        1 4
        2 5
        2 6
        0
        6
        3
        */
        ///Ans: Found

    return 0;
}
