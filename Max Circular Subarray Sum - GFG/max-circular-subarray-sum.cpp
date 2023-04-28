//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
    int kadans(int arr[],int num){
        int maxi=INT_MIN;
        for(int i=0;i<num;i++){
            maxi=max(maxi,arr[i]);
        }
        if(maxi<0)return maxi;
        int s=0;
        maxi=0;
        for(int i=0;i<num;i++){
            s+=arr[i];
            maxi=max(maxi,s);
            if(s<0)
            s=0;
        }
        return maxi;
    }
    int circularSubarraySum(int arr[], int num){
        
        // your code here
        int x=kadans(arr,num);
        int maxi=INT_MIN;
        for(int i=0;i<num;i++){
            maxi=max(maxi,arr[i]);
        }
        if(maxi<0)return maxi;
        int s=0;
        for(int i=0;i<num;i++){
            s+=arr[i];
            arr[i]=arr[i]*(-1);
        }
        int y=kadans(arr,num);
        // return y;
        return max(x,s+y);
    }
};

//{ Driver Code Starts.

int main()
 {
	int T;
	
	//testcases
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    //calling function
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends