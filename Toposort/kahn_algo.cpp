#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topoSort(int V, vector<vector<int>>& adj) {
        vector<int> enque(V,0);

        for(int i=0;i<V;i++){
            for(auto it: adj[i]){
                enque[it]++;
            }
        }

        queue<int> q;

        for(int i=0;i<V;i++){
            if(enque[i]==0){
                q.push(i);
            }
        }

        vector<int> ans;

        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);

            for(auto ngr : adj[node]){
                enque[ngr]--;
                if(enque[ngr]==0){
                    q.push(ngr);

                }
            }
        }
        return ans;
    }
};

int main() {
    int V = 6;
    vector<vector<int>> adj(V);

    adj[5].push_back(2);
    adj[5].push_back(0);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    Solution obj;
    vector<int> topo = obj.topoSort(V, adj);

    cout << "Topological Sort (Kahn): ";
    for (int x : topo) cout << x << " ";
    cout << endl;

    // cycle check
    if (topo.size() < V)
        cout << "Cycle exists\n";
    else
        cout << "No cycle\n";

    return 0;
}
