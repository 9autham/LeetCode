//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
        vector <int> rotate (int n, int d)
        {
            //code here.
            if(d>16)d=d%16;
            
            vector<int>bits(16,0);
            
            for(int i=0;i<16;i++){
                int m=(1<<i);
                bits[i]=n&m;
            }
            
            int ans1{};
            for(int i=0;i<16;i++){
                if(bits[i]){
                    ans1+=(1<<(i+d)%16);
                }
            }
            int ans2{};
            for(int i=0;i<16;i++){
                if(bits[i]){
                    ans2+=(1<<(16+(i-d))%16);
                }
            }
            return {ans1,ans2};
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        
        int n, d; cin >> n >> d;
        Solution ob;
        vector <int> res = ob.rotate (n, d);
        cout << res[0] << endl << res[1] << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends