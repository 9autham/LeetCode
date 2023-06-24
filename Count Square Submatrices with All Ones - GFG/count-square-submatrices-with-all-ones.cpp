//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSquares(int N, int M, vector<vector<int>> &matrix) {
        // code here
        vector<vector<int>>dp=matrix;
        for(int i=1;i<N;i++){
            for(int j=1;j<M;j++){
                if(dp[i][j]==0){
                    dp[i][j]=0;
                }
                else{
                    dp[i][j]=1+min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
                }
            }
        }
        int cnt=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                cnt=cnt+dp[i][j];
            }
        }
        return cnt;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;

        vector<vector<int>> matrix(N, vector<int>(M));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        cout << obj.countSquares(N, M, matrix) << endl;
    }
    return 0;
}
// } Driver Code Ends