//Check whether gicen graph is bipartite or not.
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int bipartite(vector<vector<int> >& adj) {
    queue<int> q;
    vector<bool> visited(adj.size(), false);
    vector<bool> color(adj.size(), false);  //false for black and true for white.

    for (int i = 0; i < adj.size(); i++) {
        if (!visited[i]) {
            color[i] = true;
            visited[i] = true;
            q.push(i);

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (const int& neighbour : adj[node]) {
                    if (color[node] == color[neighbour] && visited[neighbour] == true) {
                        return 0;
                    }
                    if (!visited[neighbour]) {
                        color[neighbour] = color[node] == true ? false : true;
                        visited[neighbour] = true;
                        q.push(neighbour);
                    }
                }
            }
        }
    }

    return 1;
}

int main() {
    int n, m;
    std::cin >> n >> m;
    vector<vector<int> > adj(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int x, y;
        std::cin >> x >> y;
        adj[x - 1].push_back(y - 1);
        adj[y - 1].push_back(x - 1);
    }
    std::cout << bipartite(adj);
}
