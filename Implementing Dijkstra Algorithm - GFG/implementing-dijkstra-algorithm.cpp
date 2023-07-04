//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int>ans(V,1e9);
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>q;
        q.push({0,S});
        ans[S]=0;
        while(!q.empty()){
            auto dist=q.top().first;  //distance
            auto node=q.top().second; //node
            q.pop();
            for(auto val:adj[node]){
                int edgewgt=val[1];
                int nodename=val[0];
                if(dist+edgewgt<ans[nodename]){
                    ans[nodename]=dist+edgewgt;
                    q.push({ans[nodename],nodename});
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends