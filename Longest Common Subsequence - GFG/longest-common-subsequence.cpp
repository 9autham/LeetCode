//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    int f(string s1,string s2,int i,int j,vector<vector<int>>&dp){
        if(i==0 or j==0)
        return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s1[i-1]==s2[j-1]){
            return dp[i][j]=1+f(s1,s2,i-1,j-1,dp);
        }
        return dp[i][j]=max(f(s1,s2,i-1,j,dp),f(s1,s2,i,j-1,dp));
    //Function to find the length of longest common subsequence in two strings.
    }
    int lcs(int x, int y, string s1, string s2)
    {
        vector<vector<int>>dp(x+2,vector<int>(y+2,0));
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[x][y];
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends