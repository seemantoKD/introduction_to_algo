#include <bits/stdc++.h>
using namespace std;

bool visited[1000];
vector<int> adj_list[1000];

void dfs(int src)
{
    // cout<<src<<" ";
    visited[src] = true;

    for (int child : adj_list[src])
    {
        if (!visited[child])
        {
            dfs(child);
        }
    }
}

int main()
{
    int node, edge;
    cin >> node >> edge;

    while (edge--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    memset(visited, false, sizeof(visited));

    int count = 0;

    for (int i = 0; i < node; i++)
    {
        if (!visited[i])
        {
            dfs(i);
            count++;
        }
    }
    cout << count << endl;
    return 0;
}