//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int f(vector<int>& height, int i, int k,vector<int>&dp){
        if(i==0)return 0;
        int mini=INT_MAX;
        if(dp[i]!=-1)return dp[i];
        for(int j=1;j<=k;j++){
            int pick=INT_MAX;
            if(i-j>=0)
            pick=abs(height[i]-height[i-j])+f(height,i-j,k,dp);
            mini=min(mini,pick);
        }
        return dp[i]=mini;
    }
    int minimizeCost(vector<int>& height, int n, int k) {
        vector<int>dp(n+1,-1);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            int mini=INT_MAX;
            for(int j=1;j<=k;j++){
            int pick=INT_MAX;
            if(i-j>=0)
            pick=abs(height[i]-height[i-j])+dp[i-j];
            mini=min(mini,pick);
            dp[i]=mini;
        }
    }
        return dp[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends