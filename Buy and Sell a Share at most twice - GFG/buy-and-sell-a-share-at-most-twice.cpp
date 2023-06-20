//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
int f(vector<int>&price,int idx,int buy,int k,vector<vector<vector<int>>>&dp){
    if(idx==price.size() or k==0){
        return 0;
    }
    if(dp[idx][buy][k]!=-1)return dp[idx][buy][k];
    if(buy){
        int b=-price[idx]+f(price,idx+1,0,k,dp);
        int nb=f(price,idx+1,buy,k,dp);
        return dp[idx][buy][k]=max(b,nb);
    }
    else{
        int s=price[idx]+f(price,idx+1,1,k-1,dp);
        int ns=f(price,idx+1,buy,k,dp);
        return dp[idx][buy][k]=max(s,ns);
    }
}
int maxProfit(vector<int>&price){
    //Write your code here..
    int n=price.size();
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
    for
    return f(price,0,1,2,dp);
}

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}

// } Driver Code Ends