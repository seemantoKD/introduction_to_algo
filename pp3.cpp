#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1000];

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

    int input_node;
    cin >> input_node;

    cout << adj_list[input_node].size() << endl;
    return 0;
}