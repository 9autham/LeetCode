//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define mod 1000000007
class Solution {
  public:
    int f(int i,int j,vector<vector<int>>& grid,vector<vector<int>>&dp){
        if(i==0 and j==0 and grid[0][0]==0)return 1;
        if(i<0 or j<0)return 0;
        if(grid[i][j]==1)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int a=0;
        if(grid[i][j]==0)
        a=f(i-1,j,grid,dp);
        int b=0;
        if(grid[i][j]==0)
        b=f(i,j-1,grid,dp);
        return a+b;
    }
    int totalWays(int n, int m, vector<vector<int>>& grid) {
        // Code here
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<n;i++){
            if(grid[i][0]==0)
            dp[i][0]=1;
        }
        for(int i=0;i<m;i++){
            if(grid[0][i]==0)
            dp[0][i]=1;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(grid[i][j]==1){dp[i][j]=0;continue;}
                long long int a=0;
        if(grid[i][j]==0)
        a=dp[i-1][j];
        long long int b=0;
        if(grid[i][j]==0)
        b=dp[i][j-1];
        dp[i][j]=(a+b)%mod;
            }
        }
        return dp[n-1][m-1]%mod;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < m; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.totalWays(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends