//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define mod 1000000007
class Solution{
	public:
	int f(int arr[],int i,int sum,vector<vector<int>>&dp){
	    if(i==0){
	        if(sum==0 and arr[i]==0)return 2;
	        if(sum==0 or sum==arr[i])return 1;
	        return 0;
	    }
	    if(dp[i][sum]!=-1)return dp[i][sum];
	    int take=0;
	    if(sum>=arr[i]){
	        take=f(arr,i-1,sum-arr[i],dp);
	    }
	    int nottake=f(arr,i-1,sum,dp);
	    return dp[i][sum]=(take+nottake)%mod;
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>>dp(n+1,vector<int>(sum+1,0));
        for(int i=0;i<n;i++){
            for(int s=0;s<=sum;s++){
                if(i==0){
	        if(s==0 and arr[i]==0)dp[i][s]=2;
	        else if(s==0 or s==arr[i])dp[i][s]=1;
	        else dp[i][s]=0;
	    }
            }
        }
        for(int i=1;i<n;i++){
            for(int s=0;s<=sum;s++){
                int take=0;
	            if(s>=arr[i]){
	                take=dp[i-1][s-arr[i]];
	            }
	           int nottake=dp[i-1][s];
	           dp[i][s]=(take+nottake)%mod;
            }
        }
        return dp[n-1][sum];
	}
	  
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends