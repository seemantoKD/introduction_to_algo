#include <bits/stdc++.h>
using namespace std;

bool visited[1000];
vector<int> adj_list[1000];
// vector<int> component;

int dfs(int src)
{
    // component.push_back(src);
    // cout<<src<<" ";
    visited[src] = true;
    int count = 1;

    for (int child : adj_list[src])
    {
        if (!visited[child])
        {
            count += dfs(child);
        }
    }
    return count;
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

    vector<int> component;

    // int count = 0;

    for (int i = 0; i < node; i++)
    {
        if (!visited[i])
        {
            int count = dfs(i);
            component.push_back(count);
            // count++;
            // cout << count << " ";
        }
    }

    // sort(component.begin(),component.end(),greater<int>());
    sort(component.begin(), component.end());
    
    for (int number_of_component_element : component)
    {
        cout << number_of_component_element << " ";
    }
    cout << endl;

    return 0;
}