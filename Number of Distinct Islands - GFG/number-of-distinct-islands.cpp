//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(vector<vector<int>>&vis,vector<vector<int>>&grid,int i,int j,vector<pair<int,int>>&to,int row,int col){
        vis[i][j]=1;
        int n=grid.size();
        int m=grid[0].size();
        // cout<<i-row<<" "<<j-col<<endl;
        to.push_back({i-row,j-col});
        int arr[]={-1,0,+1,0};
        int brr[]={0,+1,0,-1};
        for(int k=0;k<4;k++){
             int nrow=i+arr[k];
             int ncol=j+brr[k];
             if(ncol>=0 and nrow>=0 and ncol<m and nrow<n and !vis[nrow][ncol] and grid[nrow][ncol]==1){
                 dfs(vis,grid,nrow,ncol,to,row,col);
             }
        }
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        set<vector<pair<int,int>>>st;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] and grid[i][j]==1){
                    vector<pair<int,int>>to;
                    dfs(vis,grid,i,j,to,i,j);
                    st.insert(to);
                }
            }
        }
        return st.size();
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
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends