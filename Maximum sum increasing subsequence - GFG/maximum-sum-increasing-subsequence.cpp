//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    int maxi=INT_MIN;
	    vector<int>sum(n);
	    for(int i=0;i<n;i++){
	        maxi=max(maxi,arr[i]);
	        sum[i]=arr[i];
	    }
	    for(int i=0;i<n;i++){
	        for(int j=0;j<i;j++){
	            if(arr[j]<arr[i]){
	                if(sum[j]<sum[i]){
	                    sum[i]=max(sum[j]+arr[i],sum[i]);
	                    maxi=max(maxi,sum[i]);
	                }
	            }
	        }
	    }
	    return maxi;
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends