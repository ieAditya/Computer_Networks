#include <bits/stdc++.h>
using namespace std;
int main()
{
    int v, e;
    cin >> v >> e;
    vector<pair<int, int>> adj[v + 1];
    for (int i = 0; i < e; i++)
    {
        int e1, e2, w;
        cin >> e1 >> e2 >> w;
        adj[e1].push_back({e2, w});
        adj[e2].push_back({e1, w});
    }
    int source;
    cin >> source;
    vector<int> distance(v + 1, INT_MAX);
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
    cout << "The distance from source " << source << "are:-" << endl;
    for (int i = 1; i <= v; i++)
    {
        cout << distance[i] << " ";
    }
    cout << endl;
    return 0;
}