//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int f(vector<int>&prices,int idx,int buy,vector<vector<int>>&dp){
        if(idx==prices.size()){
            return 0;
        }
        if(dp[idx][buy]!=-1)return dp[idx][buy];
        if(buy){
            int take=-prices[idx]+f(prices,idx+1,0,dp);
            int nottake=f(prices,idx+1,buy,dp);
            return dp[idx][buy]= max(take,nottake);
        }
        else{
            int take=prices[idx]+f(prices,idx+1,1,dp);
            int nottake=f(prices,idx+1,buy,dp);
            return dp[idx][buy]=max(take,nottake);
        }
    }
    int stockBuyAndSell(int n, vector<int> &prices){
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return f(prices,0,1,dp);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> prices(n);
        Array::input(prices,n);
        
        Solution obj;
        int res = obj.stockBuyAndSell(n, prices);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends