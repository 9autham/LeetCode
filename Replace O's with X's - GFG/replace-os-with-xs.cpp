//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void dfs(vector<vector<char>>&mat,vector<vector<int>>&vis,vector<vector<char>>&ans,int i,int j){
        vis[i][j]=1;
        ans[i][j]='O';
        int n=mat.size();
        int m=mat[0].size();
        int arr[]={-1,0,+1,0};
        int brr[]={0,+1,0,-1};
        for(int k=0;k<4;k++){
            int nrow=i+arr[k];
            int ncol=j+brr[k];
            if(nrow>=0 and ncol>=0 and ncol<m and nrow<n and !vis[nrow][ncol] and mat[nrow][ncol]=='O'){
                dfs(mat,vis,ans,nrow,ncol);
            }
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<char>>ans(n,vector<char>(m,'X'));
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            if(!vis[i][0] and mat[i][0]=='O'){
                dfs(mat,vis,ans,i,0);
            }
            if(!vis[i][m-1] and mat[i][m-1]=='O'){
                dfs(mat,vis,ans,i,m-1);
            }
        }
        for(int i=0;i<m;i++){
            if(!vis[0][i] and mat[0][i]=='O'){
                dfs(mat,vis,ans,0,i);
            }
            if(!vis[n-1][i] and mat[n-1][i]=='O'){
                dfs(mat,vis,ans,n-1,i);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends