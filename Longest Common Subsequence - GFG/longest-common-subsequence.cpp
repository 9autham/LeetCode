//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int f(string t1, string t2,int idx1,int idx2,vector<vector<int>>&dp){
        if(idx1==0 or idx2==0)return 0;
        if(dp[idx1][idx2]!=-1)return dp[idx1][idx2];
        if(t1[idx1-1]==t2[idx2-1]){
            return 1+f(t1,t2,idx1-1,idx2-1,dp);
        }
        return dp[idx1][idx2]=max(f(t1,t2,idx1-1,idx2,dp),f(t1,t2,idx1,idx2-1,dp));
    }
    int lcs(int x, int y, string t1, string t2)
    {
        int n=t1.size();
        int m=t2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int idx1=1;idx1<=n;idx1++){
            for(int idx2=1;idx2<=m;idx2++){
                if(t1[idx1-1]==t2[idx2-1]){
                    dp[idx1][idx2]=1+dp[idx1-1][idx2-1];
                }
                else
                dp[idx1][idx2]=max(dp[idx1-1][idx2],dp[idx1][idx2-1]);
            }
        }
        return dp[n][m];
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