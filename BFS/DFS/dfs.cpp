#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adj[], vector<int> &vis) {
    vis[node] = 1;
    cout << node << " ";

    for(int neighbor : adj[node]) {
        if(!vis[neighbor]) {
            dfs(neighbor, adj, vis);
        }
    }
}

int main() {
    int n = 5;
    vector<int> adj[n];

    adj[0] = {1, 4};
    adj[1] = {0, 2, 3};
    adj[2] = {1};
    adj[3] = {1, 4};
    adj[4] = {0, 3};

    vector<int> vis(n, 0);
    cout << "DFS Order: ";
    dfs(0, adj, vis);
}
