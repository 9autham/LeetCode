//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int f(vector<int>&nums,int idx,vector<int>&dp){
        if(idx==0)return nums[0];
        if(idx<0)return 0;
        if(dp[idx]!=-1)return dp[idx];
        int take=nums[idx]+f(nums,idx-2,dp);
        int nottake=f(nums,idx-1,dp);
        return dp[idx]=max(take,nottake);
    }
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        vector<int>dp(n,-1);
        vector<int>nums;
        for(int i=0;i<n;i++){
            nums.push_back(arr[i]);
        }
        return f(nums,nums.size()-1,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends