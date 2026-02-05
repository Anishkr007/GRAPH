#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findOrder(vector<string>& dict, int N, int K) {
        vector<vector<int>> adj(K);

        for(int i=0;i<N-1;i++){
            string w1 = dict[i];
            string w2 = dict[i+1];

            int len = min(w1.size(),w2.size());

            for(int j=0;j<len;j++){
                if(w1[j]!=w2[j]){
                    adj[w1[j]-'a'].push_back(w2[j]-'a');
                    break;
                }
            }

        }

        //calculate indeg...
        vector<int> indeg(K);

        for(int i=0;i<K;i++){
            for(auto it:adj[i])
                indeg[it]++;
            }
            // queue
            queue<int> q;
        for(int i=0;i<K;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }

        //
        string ans = "";
        while(!q.empty()){
            int node=q.front();
            q.pop();

            ans.push_back(char(node+'a'));

            for(auto it : adj[node]){
                indeg[it]--;
                if(indeg[it]==0){
                    q.push(it);
                }
            }
        }

        return ans;
    }
};

int main() {
    // 🔹 Example input (same as GFG / interview style)
    vector<string> dict = {"baa", "abcd", "abca", "cab", "cad"};
    int N = dict.size();
    int K = 4;  // number of unique characters (a,b,c,d)

    Solution obj;
    string order = obj.findOrder(dict, N, K);

    cout << "Alien Dictionary Order: " << order << endl;

    return 0;
}
