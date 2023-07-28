//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Disjoint{
    public:
    vector<int>rank,parent;
    Disjoint(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int ultimateparent(int node){
        if(node==parent[node])return node;
        return parent[node]=ultimateparent(parent[node]);
    }
    void unionbysize(int u,int v){
        int up_u=ultimateparent(u);
        int up_v=ultimateparent(v);
        if(up_v==up_u)return;
        if(rank[up_v]>rank[up_u]){
            parent[up_u]=up_v;
        }
        else if(rank[up_v]<rank[up_u]){
            parent[up_v]=up_u;
        }
        else{
            parent[up_u]=up_v;
            rank[up_v]++;
        }
    }
};
class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        // code here
        Disjoint ds(n);
        int cntExtras=0;
        for(auto val:edge){
            int u=val[0];
            int v=val[1];
            if(ds.ultimateparent(u)==ds.ultimateparent(v))cntExtras++;
            else{
                ds.unionbysize(u,v);
            }
        }
        int cnt=0;// no of proviences
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i)cnt++;
        }
        int ans=cnt-1;
        if(cntExtras>=ans)return ans;
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends