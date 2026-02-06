#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node,vector<int> &vis,vector<vector<int>>& adj,stack<int>& st){
        vis[node]=1;

        for(auto ngb:adj[node] ){
            if(!vis[ngb]){
                dfs(ngb,vis,adj,st);
            }
        }

        st.push(node);


    }

    vector<int> topoSort(int V, vector<vector<int>>& adj) {

        stack<int> st;
        vector<int> vis(V,0);

        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,adj,st);
            }
        }

        vector<int> ans;

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;

    }
};

int main() {
    // Number of vertices
    int V = 6;

    // Adjacency list
    vector<vector<int>> adj(V);

    // Graph edges
    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    Solution obj;
    vector<int> topo = obj.topoSort(V, adj);

    cout << "Topological Sort (DFS): ";
    for (int x : topo) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
