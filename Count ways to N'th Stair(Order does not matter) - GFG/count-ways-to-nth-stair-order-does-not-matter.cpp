//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    int f(int n,int k){
	        if(n==0)return 1;
	        if(k==1){
	            return 1;
	        }
	        int t=0;
	        if(n>=2)
	        t=f(n-2,k);
	        int nt=f(n,k-1);
	        return t+nt;
	    }
		int nthStair(int n){
		    //  Code here
		    return f(n,2);
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthStair(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends