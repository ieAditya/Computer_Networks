#include <bits/stdc++.h>
using namespace std;

void djikstra(vector<pair<int, int>> adj[], int source, vector<int> &distance)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});
    distance[source] = 0;
    while (!pq.empty())
    {
        int distanceofprevnode = pq.top().first;
        int prevnode = pq.top().second;
        pq.pop();
        for (pair<int, int> child : adj[prevnode])
        {
            int currnode = child.first;
            int distanceofcurrnode = child.second;
            if (distanceofprevnode + distanceofcurrnode < distance[currnode])
            {
                distance[currnode] = distanceofcurrnode + distanceofprevnode;
                pq.push({distance[currnode], currnode});
            }
        }
    }
}

int main()
{
    int v, e;
    cout << "Input number of vertices and edges : ";
    cin >> v >> e;
    vector<pair<int, int>> adj[v + 1];
    for (int i = 0; i < e; i++)
    {
        int e1, e2, w;
        cout << "Input e1, e2, weight : ";
        cin >> e1 >> e2 >> w;
        adj[e1].push_back({e2, w});
        adj[e2].push_back({e1, w});
    }
    int source;
    cout << "Input source : ";
    cin >> source;
    vector<int> distance(v + 1, INT_MAX);
    djikstra(adj, source, distance);
    for (int i = 1; i <= v; i++)
    {
        cout << "Distance of node " << i << " from source is " << distance[i] << endl;
    }
    return 0;
}