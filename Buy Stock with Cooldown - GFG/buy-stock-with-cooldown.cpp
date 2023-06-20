//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long f(vector<long long>&prices,int idx,int buy,vector<vector<long long>>&dp){
        if(idx>=prices.size()){
            return 0;
        }
        if(dp[idx][buy]!=-1)return dp[idx][buy];
        if(buy){
            long long  b=-prices[idx]+f(prices,idx+1,0,dp);
            long long int nb=f(prices,idx+1,buy,dp);
            return dp[idx][buy]=max(b,nb);
        }
        else{
            long long int s=prices[idx]+f(prices,idx+2,1,dp);
            long long int ns=f(prices,idx+1,buy,dp);
            return dp[idx][buy]=max(s,ns);
        }
    }
    long long maximumProfit(vector<long long>&prices, int n) {
        // Code here
        vector<vector<long long>>dp(n+1,vector<long long>(2,-1));
        return f(prices,0,1,dp);
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