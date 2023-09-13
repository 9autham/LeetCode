//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S){
        // code here
        string ans="";
        for(int i=0;i<N;i++){
            if(S>=9){
                ans.push_back('9');
                S=S-9;
            }
            else{
                ans.push_back(char(S+'0'));
                S=0;
            }
        }
        if(S!=0)return "-1";
        if(ans[0]=='0' and N!=1)return "-1";
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends