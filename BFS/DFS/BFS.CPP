#include <bits/stdc++.h>
using namespace std;
vector<int> bfs(int start,vector<int>adj[],int n){
    vector<int> vis(n,0);
    queue<int> q;

    vis[start]=1;
    q.push(start);
    
    //bfs
    vector<int> bbfs;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        bbfs.push_back(node);

        for(auto it : adj[node]){
            if(!vis[it]){
                vis[it]=1;
                q.push(it);
            }
        }

    }
    return bbfs;
}
int main(){
    int n=5;
     vector<int> adj[n];

     adj[0]={1,4};
     adj[1]={0,2,3};
     adj[2]={1};
     adj[3]={1,4};
     adj[4]={0,3};

      vector<int> ans = bfs(0,adj,n);
     cout << "BFS Traversal: ";
    for (auto node : ans)
        cout << node << " ";
    cout << endl;

    return 0;

}