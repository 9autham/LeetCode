//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        // Code here
        vector<vector<pair<int,int>>>adj(n);
        for(auto val:flights){
            adj[val[0]].push_back({val[1],val[2]});
        }
        priority_queue <pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>q;
        vector<int>dis(n,1e9);
        //{k,{dis,node}}
        q.push({0,{0,src}});
        while(!q.empty()){
            auto it=q.top();
            q.pop();
            int k=it.first;
            int dist=it.second.first;
            int node=it.second.second;
            if(k>K)continue;
            for(auto val: adj[node]){
                int d=dist+val.second;
                int no=val.first;
                if(dis[no]>d){
                    dis[no]=d;
                    q.push({k+1,{d,no}});
                }
            }
        }
        if(dis[dst]==1e9)return -1;
        return dis[dst];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends