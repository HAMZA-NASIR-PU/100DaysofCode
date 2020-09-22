//Dijkstas algorithm using priority Queue
#include <iostream>
#include <vector>
#include <queue>
#define int long long
using namespace std;

typedef pair<int, int> iPair;

int distance(vector<vector<iPair> >& adj, int s, int t) {
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    vector<int> distance(adj.size(), 1000000000);
    vector<bool> processed(adj.size(), false);
    distance[s] = 0;
    pq.push(make_pair(distance[s], s));
    while (!pq.empty()) {
        int node = pq.top().second;
        int node_weight = pq.top().first;
        pq.pop();
        if (!processed[node]) {
            processed[node] = true;

            for (const auto& neighbour : adj[node]) {
                int neighbour_node = neighbour.first;
                int edge_weight = neighbour.second;
                if (!processed[neighbour_node]) {
                    if (node_weight + edge_weight < distance[neighbour_node]) {
                        distance[neighbour_node] = node_weight + edge_weight;
                        pq.push(make_pair(distance[neighbour_node], neighbour_node));
                    }
                }
            }
        }
    }
    return distance[t] == 1000000000 ? -1 : distance[t];
}

signed main() {
    int n, m;
    std::cin >> n >> m;
    vector<vector<iPair>> adj(n);
    for (int i = 0; i < m; i++) {
        int x, y, w;
        std::cin >> x >> y >> w;
        adj[x - 1].push_back({ y - 1, w });
    }
    int s, t;
    std::cin >> s >> t;
    s--, t--;
    std::cout << distance(adj, s, t);
}
