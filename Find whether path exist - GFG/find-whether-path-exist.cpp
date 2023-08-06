//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int sr=-1;
        int sc=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    sr=i;
                    sc=j;
                }
            }
        }
        queue<pair<int,int>>q;
        q.push({sr,sc});
        vis[sr][sc]=1;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int arr[4]={0,1,0,-1};
            int brr[4]={-1,0,1,0};
            for(int k=0;k<4;k++){
                int nrow=it.first+arr[k];
                int ncol=it.second+brr[k];
                if(nrow<n and ncol<m and nrow>=0 and ncol>=0 and !vis[nrow][ncol] and grid[nrow][ncol]!=0){
                    q.push({nrow,ncol});
                    if(grid[nrow][ncol]==2)return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends