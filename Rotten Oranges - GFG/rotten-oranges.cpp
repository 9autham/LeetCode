//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }
        int arr[]={-1,0,+1,0};
        int brr[]={0,+1,0,-1};
        int cnt=0;
        while(!q.empty()){
            cnt++;
            int n1=q.size();
            for(int i=0;i<n1;i++){
                pair<int,int>x=q.front();
                q.pop();
                int r=x.first;
                int c=x.second;
                for(int i=0;i<4;i++){
                    int nrow=r+arr[i];
                    int ncol=c+brr[i];
                    if(nrow>=0 and ncol>=0 and nrow<n and ncol<m and !vis[nrow][ncol] and grid[nrow][ncol]==1){
                        // cout<<nrow<<" "<<ncol<<endl;
                        vis[nrow][ncol]=1;
                        q.push({nrow,ncol});
                        grid[nrow][ncol]=2;
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)return -1;
            }
        }
        return cnt-1;
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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends