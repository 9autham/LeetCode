//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        int n=heights.size();
        int m=heights[0].size();
        priority_queue <pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>q;
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        q.push({0,{0,0}});
        int arr[]={-1,0,1,0};
        int brr[]={0,1,0,-1};
        while(!q.empty()){
            auto it=q.top();
            q.pop();
            int diff=it.first;
            int row=it.second.first;
            int col=it.second.second;
            for(int i=0;i<4;i++){
                int nrow=row+arr[i];
                int ncol=col+brr[i];
                if(nrow>=0 and ncol>=0 and nrow<n and ncol<m){
                    int x=max(diff,abs(heights[row][col]-heights[nrow][ncol]));
                    if(dist[nrow][ncol]>x){
                        dist[nrow][ncol]=x;
                        q.push({x,{nrow,ncol}});
                    }
                }
            }
        }
        if(1e9==dist[n-1][m-1])return 0;
        return dist[n-1][m-1];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends