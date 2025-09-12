#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long node, edge, q;
    cin >> node >> edge >> q;

    long long adj_mat[node+5][node+5];

    // sobaike INT_MAX diye initialize
    for (long long i = 1; i <= node; i++)
    {
        for (long long j = 1; j <= node; j++)
        {
            if (i == j)
                adj_mat[i][j] = 0;
            else
                adj_mat[i][j] = LONG_LONG_MAX;
        }
    }

    while (edge--)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        adj_mat[a][b] = c;
        adj_mat[b][a] = c;
    }

    // floyed_warshall
    for (long long k = 1; k <= node; k++)
    {
        for (long long i = 1; i <= node; i++)
        {
            for (long long j = 1; j <= node; j++)
            {
                if ((adj_mat[i][k] != INT_MAX && adj_mat[k][j] != LONG_LONG_MAX) && adj_mat[i][k] + adj_mat[k][j] < adj_mat[i][j])
                    adj_mat[i][j] = adj_mat[i][k] + adj_mat[k][j];
            }
        }
    }

    while (q--)
    {
        long long  src, dst;
        cin >> src >> dst;
        if (adj_mat[src][dst] == LONG_LONG_MAX)
            cout << -1 << endl;
        else
            cout << adj_mat[src][dst] << endl;
    }
    return 0;
}

// exam shese eta sundor kore buje solve korbo ... ei code incomplete
