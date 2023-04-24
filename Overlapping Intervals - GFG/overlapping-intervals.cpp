//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& in) {
         // Code here
         sort(in.begin(),in.end());
         int start=in[0][0];
         int end=in[0][1];
         int n=in.size();
        //  in.push_back({INT_MAX,INT_MAX});
         vector<vector<int>>ans;
         for(int i=1;i<n;i++){
             if(in[i][0]>end){
                 vector<int>v(2);
                 v[0]=start;
                 v[1]=end;
                 ans.push_back(v);
                 start=in[i][0];
                 end=in[i][1];
             }
             else{
                 end=max(end,in[i][1]);
             }
         }
         vector<int>v(2);
                 v[0]=start;
                 v[1]=end;
                 ans.push_back(v);
         return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends