//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long f(vector<long long>&prices,int idx,int buy,int fee,vector<vector<long long>>&dp){
        if(idx==prices.size()){
            return 0;
        }
        if(dp[idx][buy]!=-1)return dp[idx][buy];
        if(buy){
            long int b=-prices[idx]+f(prices,idx+1,0,fee,dp);
            long int nb=f(prices,idx+1,buy,fee,dp);
            return dp[idx][buy]=max(b,nb);
        }
        else{
            long int s=prices[idx]-fee+f(prices,idx+1,1,fee,dp);
            long int ns=f(prices,idx+1,buy,fee,dp);
            return dp[idx][buy]=max(s,ns);
        }
    }
    long long maximumProfit(vector<long long>&prices, int n, int fee) {
        // Code here
        vector<vector<long long>>dp(n+1,vector<long long>(2,-1));
        return f(prices,0,1,fee,dp);
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
        
        int fee; cin>>fee;
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n, fee)<<"\n";
    }
    return 0;
}
// } Driver Code Ends