//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to count the number of ways in which frog can reach the top.
    int mod=1e9+7;
    long long f(int n,vector<int>&dp){
        if(n==0)return 1;
        if(n<0)return 0;
        if(dp[n]!=-1)return dp[n];
        long long t1=f(n-1,dp);
        long long t2=f(n-2,dp);
        long long t3=f(n-3,dp);
        return dp[n]=(t1+t2+t3)%mod;
    }
    long long countWays(int n)
    {
        vector<int>dp(n+1,-1);
        return f(n,dp);
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends