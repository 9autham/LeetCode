//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(vector<vector<int>> &grid,vector<vector<int>>&vis,vector<vector<int>>&ans,int i,int j){
        int n=grid.size();
	    int m=grid[0].size();
        vis[i][j]=1;
        ans[i][j]=0;
        int arr[]={-1,0,1,0};
        int brr[]={0,1,0,-1};
        for(int k=0;k<4;k++){
            int nrow=i+arr[k];
            int ncol=j+brr[k];
            if(ncol>=0 and nrow>=0 and ncol<m and nrow<n and !vis[nrow][ncol] and grid[nrow][ncol]==1){
                dfs(grid,vis,ans,nrow,ncol);
            }
        }
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n=grid.size();
	    int m=grid[0].size();
	    vector<vector<int>>vis(n,vector<int>(m,0));
	    vector<vector<int>>ans=grid;
	    for(int i=0;i<n;i++){
	        if(!vis[i][0] and grid[i][0]==1){
	            dfs(grid,vis,ans,i,0);
	        }
	        if(!vis[i][m-1] and grid[i][m-1]==1){
	            dfs(grid,vis,ans,i,m-1);
	        }
	    }
	    for(int j=0;j<m;j++){
	        if(!vis[0][j] and grid[0][j]==1){
	            dfs(grid,vis,ans,0,j);
	        }
	        if(!vis[n-1][j] and grid[n-1][j]==1){
	            dfs(grid,vis,ans,n-1,j);
	        }
	    }
	    int cnt=0;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(ans[i][j]==1){
	                cnt++;
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends