//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        // Code here
        vector<int>dp(n,1);
        vector<int>last(n,-1);
        int maxi=0;
        int maxidx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[j]<arr[i]){
                    if(1+dp[j]>dp[i]){
                        dp[i]=1+dp[j];
                        last[i]=j;
                    }
                    if(maxi<dp[i]){
                        maxi=max(maxi,dp[i]);
                        maxidx=i;
                    }
                }
            }
        }
        vector<int>ans;
        while(maxidx!=-1){
            ans.push_back(arr[maxidx]);
            maxidx=last[maxidx];
        }
        // ans.push_back(arr[maxidx]);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends