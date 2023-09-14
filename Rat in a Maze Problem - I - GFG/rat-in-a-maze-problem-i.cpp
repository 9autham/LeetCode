//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void solve(vector<string>&ans,vector<vector<int>> &m,int n,int i,int j,string s,vector<vector<int>>vis){
        //base Conditon
        if(i==n-1 and j==n-1){
            ans.push_back(s);
            return;
        }
        int dx[]={1,0,0,-1};
        int dy[]={0,-1,1,0};
        for(int k=0;k<4;k++){
            int row=i+dx[k];
            int col=j+dy[k];
            if(row>=0 and col>=0 and col<n and row<n and m[row][col]==1 and k==0 and !vis[row][col]){
                vis[row][col]=1;
                s.push_back('D');
                solve(ans,m,n,row,col,s,vis);
                vis[row][col]=0;
                s.pop_back();
            }
            if(row>=0 and col>=0 and col<n and row<n and m[row][col]==1 and k==1 and !vis[row][col]){
                vis[row][col]=1;
                s.push_back('L');
                solve(ans,m,n,row,col,s,vis);
                vis[row][col]=0;
                s.pop_back();
            }
            if(row>=0 and col>=0 and col<n and row<n and m[row][col]==1 and k==2 and !vis[row][col]){
                vis[row][col]=1;
                s.push_back('R');
                solve(ans,m,n,row,col,s,vis);
                vis[row][col]=0;
                s.pop_back();
            }
            if(row>=0 and col>=0 and col<n and row<n and m[row][col]==1 and k==3 and !vis[row][col]){
                vis[row][col]=1;
                s.push_back('U');
                solve(ans,m,n,row,col,s,vis);
                vis[row][col]=0;
                s.pop_back();
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string>ans;
        if(m[0][0]!=1)return ans;
        vector<vector<int>>vis(n,vector<int>(n,0));
        vis[0][0]=1;
        solve(ans,m,n,0,0,"",vis);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends