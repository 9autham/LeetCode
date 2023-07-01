//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool dfs(int i,int color,vector<int>&vis,vector<int>adj[],vector<int>&cv){
         vis[i]=1;
         cv[i]=0;
         queue<int>q;
         q.push(i);
         while(!q.empty()){
             int x=q.front();
             q.pop();
             for(auto it:adj[x]){
                 if(!vis[it]){
                     q.push(it);
                     vis[it]=1;
                     cv[it]=(!cv[x]);
                 }
                 else{
                     if(cv[it]==cv[x]){
                         return false;
                     }
                 }
             }
         }
         return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int>vis(V,0);
	    vector<int>color(V,-1);
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            if(dfs(i,0,vis,adj,color)==false){
	                return false;
	            }
	        }
	    }
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends