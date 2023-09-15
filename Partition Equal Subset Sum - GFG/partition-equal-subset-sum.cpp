//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool f(int arr[],int i,int target,vector<vector<int>>&dp){
        if(target==0)return true;
        if(target<0)return false;
        if(i==0)return (arr[0]==target);
        if(dp[i][target]!=-1)return dp[i][target];
        bool pick=f(arr,i-1,target-arr[i],dp);
        bool notpick=f(arr,i-1,target,dp);
        return dp[i][target]=pick|notpick;
    }
    int equalPartition(int N, int arr[])
    {
        int target=accumulate(arr,arr+N,0);
        if(target%2)return 0;
        target=target/2;
        vector<vector<int>>dp(N+1,vector<int>(target+1,-1));
        if(f(arr,N-1,target,dp))return 1;
        return 0;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends