//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        int n=nums.size();
        int x=0;
        for(int i=0;i<n;i++){
            x=x^nums[i];
        }
        int cnt=0;
        int z=x;
        while(z){
            if(z%2==1)break;
            cnt++;
            z=z>>1;
        }
        int num1=0;
        for(int i=0;i<n;i++){
            if(nums[i]&(1<<cnt)){
                num1=num1^nums[i];
            }
        }
        int num2=num1^x;
        vector<int>v;
        if(num1>num2){
            v.push_back(num2);
            v.push_back(num1);
        }
        else{
            v.push_back(num1);
            v.push_back(num2);
        }
        return v;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends