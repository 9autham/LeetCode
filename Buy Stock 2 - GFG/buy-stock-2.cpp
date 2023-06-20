//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long f(vector<long long>&prices,int buy,int idx,vector<vector<int>>&dp){
        if(idx==prices.size()){
            return 0;
        }
        if(dp[idx][buy]!=-1)return dp[idx][buy];
        if(buy){
            int buying=-prices[idx]+f(prices,0,idx+1,dp);
            int notbuy=0+f(prices,buy,idx+1,dp);
            return dp[idx][1]=max(buying,notbuy);
        }
        else{
            int sell=prices[idx]+f(prices,1,idx+1,dp);
            int notsell=0+f(prices,buy,idx+1,dp);
            return dp[idx][0]=max(sell,notsell);
        }
    }
    long long maximumProfit(vector<long long>&prices, int n) {
        // Code here
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return f(prices,1,0,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> prices;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            prices.push_back(x);
        }
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends