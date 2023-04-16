//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        int maxsum=INT_MIN;
        for(int i=0;i<n;i++){
            maxsum=max(maxsum,arr[i]);
        }
        if(maxsum<=0) return maxsum; 
        maxsum=0;
        int maxi=maxsum;
        for(int i=0;i<n;i++){
            if((maxsum+arr[i])>0){
                maxsum=maxsum+arr[i];
                maxi=max(maxi,maxsum);
            }
            else{
                maxsum=0;
            }
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}

// } Driver Code Ends