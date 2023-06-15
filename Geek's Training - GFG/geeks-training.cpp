//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int f(vector<vector<int>>& points,int i,int x,vector<vector<int>>&dp){
        if(i==-1)return 0; 
        if(dp[i][x]!=-1)return dp[i][x];
        int maxi=INT_MIN;
        for(int k=0;k<3;k++){
            if(k!=x){
                maxi=max(maxi,points[i][k]+f(points,i-1,k,dp));
            }
        }
        return dp[i][x]=maxi;
    }
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        vector<vector<int>>dp(n+1,vector<int>(4,-1));
        return f(points,n-1,3,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends