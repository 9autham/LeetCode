//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int newColor,vector<vector<int>>&vis,int intial){
        vis[sr][sc]=1;
        image[sr][sc]=newColor;
        int arr[]={-1,0,1,0};
        int brr[]={0,1,0,-1};
        int n=image.size();
        int m=image[0].size();
        for(int i=0;i<4;i++){
            int nsr=sr+arr[i];
            int nsc=sc+brr[i];
            if(nsr>=0 and nsc>=0 and nsr<n and nsc<m and !vis[nsr][nsc] and image[nsr][nsc]==intial){
                dfs(image,nsr,nsc,newColor,vis,intial);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here
        int n=image.size();
        int m=image[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        dfs(image,sr,sc,newColor,vis,image[sr][sc]);
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends