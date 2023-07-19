//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& intervals) {
         vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        int x=intervals[0][0];
        int y=intervals[0][1];
        for(int i=1;i<n;i++){
            if((x<=intervals[i][0] and y>=intervals[i][0]) or (x<=intervals[i][0] and y>=intervals[i][1])){
                x=min(x,intervals[i][0]);
                y=max(y,intervals[i][1]);
            }
            else{
                vector<int>v(2);
                v[0]=x;
                v[1]=y;
                ans.push_back(v);
                x=intervals[i][0];
                y=intervals[i][1];
            }
        }
        vector<int>v(2);
                v[0]=x;
                v[1]=y;
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