//{ Driver Code Starts
// Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
public:
    int mod = 1e9 + 7;

    long long int f(int n, int x, int idx, vector<vector<long long>>& dp) {
        if (n == 0) return 1;
        if (idx == 0) return 0;
        if (n < 0) return 0;
        if (dp[n][idx] != -1) return dp[n][idx];

        long long int zz = pow(idx, x);
        long long int take = f(n - zz, x, idx - 1, dp);
        long long int nottake = f(n, x, idx - 1, dp);

        return dp[n][idx] = (take + nottake) % mod;
    }

    int numOfWays(int n, int x) {
        // code here
        int Highest = 1;
        while (pow(Highest, x) <= n) {
            Highest++;
        }
        Highest--;

        vector<vector<long long>> dp(n + 1, vector<long long>(Highest + 1, -1));
        return f(n, x, Highest, dp);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n, x;
        cin >> n >> x;
        Solution ob;
        cout<<ob.numOfWays(n, x)<<endl;
    }
    return 0;
}

// } Driver Code Ends