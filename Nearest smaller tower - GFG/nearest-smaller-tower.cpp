//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    vector<int> nearestSmallerTower(vector<int> arr)
    {
        // code here
        int n=arr.size();
        vector<int>v1(n,-1);
        vector<int>v2(n,-1);
        stack<int>st;
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push(i);
            }
            else{
                while(!st.empty() and arr[st.top()]>arr[i]){
                    v1[st.top()]=i;
                    st.pop();
                }
                st.push(i);
            }
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                st.push(i);
            }
            else{
                while(!st.empty() and arr[st.top()]>arr[i]){
                    v2[st.top()]=i;
                    st.pop();
                }
                st.push(i);
            }
        }
        vector<int>v3(n);
        for(int i=0;i<n;i++){
            if(v1[i]==-1 and v2[i]==-1){
            v3[i]=-1;
            continue;
            }
            int x=0;
            if(v1[i]!=-1)
            x=abs(v1[i]-i);
            int y=0;
            if(v2[i]!=-1)
            y=abs(v2[i]-i);
            if(x==0){
                v3[i]=v2[i];
                continue;
            }
            if(y==0){
                v3[i]=v1[i];
                continue;
            }
            if(x<y){
                v3[i]=v1[i];
            }
            else if(x>y){
                v3[i]=v2[i];
            }
            else{
                if(arr[v1[i]]>=arr[v2[i]]){
                    v3[i]=v2[i];
                }
                else{
                    v3[i]=v1[i];
                }
            }
        }
        return v3;
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
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution ob;
        vector<int> ans = ob.nearestSmallerTower(v);
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends