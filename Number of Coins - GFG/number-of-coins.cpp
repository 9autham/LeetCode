//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    int f(int coins[],int M,int V,int idx,vector<vector<int>>&dp){
        if(idx==0){
            // cout<<V/coins[idx]<<"a ";
            if(V%coins[idx]==0){
                return V/coins[idx];
            }
            else{
                return 1e9;
            }
        }
        if(dp[idx][V]!=-1)return dp[idx][V];
        int nt=f(coins,M,V,idx-1,dp);
        int t=1e9;
        if(V>=coins[idx]){
            t=1+f(coins,M,V-coins[idx],idx,dp);
        }
        // cout<<nt<<" "<<t<<endl;
        return dp[idx][V]=min(t,nt);
    }
	public:
	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
	    vector<vector<int>>dp(M,vector<int>(V+1,-1));
	    sort(coins,coins+M);
	    int k=f(coins,M,V,M-1,dp);
	    if(k>=1e9){
	        return -1;
	    }
	    else{
	        return k;
	    }
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends