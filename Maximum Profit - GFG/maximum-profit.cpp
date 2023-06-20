//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int Alpha=0;
    int f(int A[],int idx,int buy,int k,vector<vector<vector<int>>>&dp){
        if(idx==Alpha or k==0)return 0;
        if(dp[idx][buy][k]!=-1)return dp[idx][buy][k];
        if(buy){
            int s=-A[idx]+f(A,idx+1,0,k,dp);
            int ns=f(A,idx+1,buy,k,dp);
            return dp[idx][buy][k]=max(s,ns);
            // s kaadu it should be b ans nb
        }
        else{
            int b=A[idx]+f(A,idx+1,1,k-1,dp);
            int nb=f(A,idx+1,buy,k,dp);
            return dp[idx][buy][k]=max(b,nb);
        }
    }
    
    int maxProfit(int K, int N, int A[]) {
        // code here
        Alpha=N;
        vector<vector<vector<int>>>dp(N+1,vector<vector<int>>(2,vector<int>(K+1,-1)));
        return f(A,0,1,K,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends