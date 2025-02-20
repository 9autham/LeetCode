//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int NumberofLIS(int n, vector<int>&arr) {
        // Code here
        vector<int>dp(n,1);
        vector<int>hash(n,1);
        int maxi=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[i]>arr[j] and 1+dp[j]>dp[i]){
                    dp[i]=1+dp[j];
                    hash[i]=hash[j];
                }
                else if(arr[i]>arr[j] and 1+dp[j]==dp[i]){
                    hash[i]=hash[i]+hash[j];
                }
            }
            maxi=max(maxi,dp[i]);
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(maxi==dp[i]){
                cnt=cnt+hash[i];
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            arr.push_back(x);
        }
        
        Solution obj;
        cout<<obj.NumberofLIS(n, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends