#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1000];
bool visited[1000];

void bfs(int src, int &count)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        // cout<<par<<" ";
        count++;

        for (int child : adj_list[par])
        {
            if (!visited[child])
            {
                q.push(child);
                visited[child] = true;
            }
        }
    }
}

int main()
{
    int count = 0;
    int node, edge;
    cin >> node >> edge;

    while (edge--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    int n;
    cin >> n;

    memset(visited, false, sizeof(visited));

    bfs(n, count);
    cout << count << endl;
    return 0;
}