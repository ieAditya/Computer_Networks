#include <bits/stdc++.h>
using namespace std;

int main()
{
    int edges, vertices;
    cout << "Input num of edges and vertices : ";
    cin >> edges >> vertices;
    int matrix[vertices + 1][edges + 1] = {0};

    for (int i = 1; i <= edges; i++)
    {
        int v1, v2;
        cout << "Input edge " << i << " vertices as v1 v2 : ";
        cin >> v1 >> v2;
        matrix[v1][i] = 1;
        matrix[v2][i] = -1;
    }

    for (int i = 0; i <= vertices; i++)
    {
        for (int j = 0; j <= edges; j++)
        {
            if (i == 0 && j == 0)
            {
                cout << "\t";
            }
            else if (i == 0 && j > 0)
            {
                cout << "e" << j << "\t";
            }
            else if (j == 0 && i != 0)
            {
                cout << "v" << i << "\t";
            }
            else
                cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}