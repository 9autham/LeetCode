//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int f(vector<vector<int>>& v,int i,int j,vector<vector<int>>&dp){
        if(i<0 or j<0 or j>=v[0].size() or i>v.size())
            return INT_MIN;
        if(i== v.size()-1)
            return v[i][j];
        if(dp[i][j]!=-1)return dp[i][j];
        int ld=v[i][j]+f(v,i+1,j-1,dp);
        int rd=v[i][j]+f(v,i+1,j,dp);
        int r=v[i][j]+f(v,i+1,j+1,dp);
        return dp[i][j]=max(ld,max(rd,r));
    }
    int maximumPath(int N, vector<vector<int>>v)
    {
        // code here
        int n=v.size();
        int m=v[0].size();
        int mini=INT_MIN;
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        for(int i=0;i<m;i++){
            mini=max(mini,f(v,0,i,dp));
        }
        return mini;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends