//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n=grid.size();
	    int m=grid[0].size();
	    vector<vector<int>>vis(n,vector<int>(m,0));
	    queue<pair<pair<int,int>,int>>q;
	    vector<vector<int>>ans(n,vector<int>(m,0));
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==1){
	                q.push({{i,j},0});
	                vis[i][j]=1;
	            }
	        }
	    }
	    int arr[]={-1,0,1,0};
	    int brr[]={0,1,0,-1};
	    while(!q.empty()){
	        auto x=q.front();
	        int row=x.first.first;
	        int col=x.first.second;
	        int dist=x.second;
	        q.pop();
	        ans[row][col]=dist;
	        for(int i=0;i<4;i++){
	            int nrow=row+arr[i];
	            int ncol=col+brr[i];
	            if(ncol>=0 and nrow>=0 and ncol<m and nrow<n and !vis[nrow][ncol] and grid[nrow][ncol]==0){
	                vis[nrow][ncol]=1;
	                q.push({{nrow,ncol},dist+1});
	            }
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends