//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> graph[]) {
        int n=V;
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(auto val:graph[i]){
                adj[val].push_back(i);
            }
        }
        vector<int>in(n,0);
        for(int i=0;i<n;i++){
            for(auto val:adj[i]){
                in[val]++;
            }
        }
        vector<int>ans;
        queue<int>q;
        for(int i=0;i<n;i++){
            if(in[i]==0){
                q.push(i);
                ans.push_back(i);
            }
        }
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(auto val:adj[x]){
                in[val]--;
                if(in[val]==0){
                    q.push(val);
                    ans.push_back(val);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends