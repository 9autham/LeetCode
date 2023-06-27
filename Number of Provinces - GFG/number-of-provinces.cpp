//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int>vis(V,0);
        queue<int>q;
        int n=adj.size();
        int m=adj[0].size();
        vector<vector<int>>adj1(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i!=j and adj[i][j]==1){
                    adj1[i].push_back(j);
                    adj1[j].push_back(i);
                }
            }
        }
        int cnt=0;
        for(int i=0;i<V;i++){
            if(!vis[i]){
            vis[i]=1;
            q.push(i);
            cnt++;
            while(!q.empty()){
                int x=q.front();
                q.pop();
                for(auto val:adj1[x]){
                    if(!vis[val]){
                        vis[val]=1;
                        q.push(val);
                    }
                }
            }
        }
    }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends