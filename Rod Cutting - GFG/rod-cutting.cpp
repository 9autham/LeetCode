//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int f(int price[],int n,int idx,vector<vector<int>>&dp){
        if(idx==0){
            return n*price[0];
        }
        if(dp[idx][n]!=-1)return dp[idx][n];
        int nt=f(price,n,idx-1,dp);
        int t=0;
        if((idx+1)<=n){
            t=price[idx]+f(price,n-idx-1,idx,dp);
        }
        return dp[idx][n]=max(t,nt);
    }
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return f(price,n,n-1,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends