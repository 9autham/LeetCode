//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int f(vector<int>& height,int i,vector<int>&dp){
      if(i==0)return 0;
      if(dp[i]!=-1)return dp[i];
      int pick=INT_MAX;
      int notpick=abs(height[i-1]-height[i])+f(height,i-1,dp);
      if(i-2>=0){
          pick=abs(height[i-2]-height[i])+f(height,i-2,dp);
      }
      return dp[i]=min(pick,notpick);
  }
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int>dp(n+1,-1);
        return f(height,n-1,dp);
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
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends