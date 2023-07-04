//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dis(n,vector<int>(m,1e9));
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        priority_queue <pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>q;
        q.push({0,{source.first,source.second}});
        dis[source.first][source.second]=0;
        while(!q.empty()){
            int dist=q.top().first;
            int nodei=q.top().second.first;
            int nodej=q.top().second.second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=nodei+dr[i];
                int ncol=nodej+dc[i];
                if(nrow>=0 and ncol>=0 and nrow<n and ncol<m and grid[nrow][ncol]==1 and dist+1<dis[nrow][ncol]){
                    dis[nrow][ncol]=1+dist;
                    q.push({dis[nrow][ncol],{nrow,ncol}});
                }
            }
        }
        int ans=dis[destination.first][destination.second];
        if(ans==1e9){
            return -1;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends