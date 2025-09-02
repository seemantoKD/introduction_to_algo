#include <bits/stdc++.h>
using namespace std;

// globally declare
vector<int> adj_list[100005];
bool visited[100005];
int level[100005];
int parent[100005];

// bredth first search function
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;
    level[src] = 0;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        for (int child : adj_list[par])
        {
            if (!visited[child])
            {
                q.push(child);
                visited[child] = true;
                level[child] = level[par] + 1;
                parent[child] = par;
            }
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
    memset(level, -1, sizeof(level));
    memset(parent, -1, sizeof(parent));

    bfs(1); // source 1
    int dst = node;

    if (!visited[dst])
    {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    vector<int> path;
    while (dst != -1)
    {
        path.push_back(dst);
        dst = parent[dst];
    }
    cout << path.size() << endl;
    reverse(path.begin(), path.end());
    for (int val : path)
    {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}