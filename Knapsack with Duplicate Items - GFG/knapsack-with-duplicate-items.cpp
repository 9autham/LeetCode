//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int f(int W,int val[],int wt[],int idx,vector<vector<int>>&dp){
        if(idx==0){
            int x=W/wt[idx];
            return val[0]*x;
        }
        if(dp[idx][W]!=-1)return dp[idx][W];
        int take=0;
        if(W-wt[idx]>=0)
        take=val[idx]+f(W-wt[idx],val,wt,idx,dp);
        int nottake=f(W,val,wt,idx-1,dp);
        return dp[idx][W]=max(take,nottake);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>>dp(N+1,vector<int>(W+1,-1));
        return f(W,val,wt,N-1,dp);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends