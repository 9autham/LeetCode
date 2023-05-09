//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        vector<int>v;
        int m=matrix.size();
        int n=matrix[0].size();
        int rs=0,cs=0,ce=n-1,re=m-1;
         while(cs<=ce and rs<=re)
        {
        for(int i=cs;i<=ce;i++){
            v.push_back(matrix[rs][i]);
        }
        rs++;
        for(int i=rs;i<=re;i++){
            v.push_back(matrix[i][ce]);
        }
        ce--;
        if (rs > re || cs > ce) break;//I
        for(int i=ce;i>=cs;i--){
            v.push_back(matrix[re][i]);
        }
        re--;
        for(int i=re;i>=rs;i--){
            v.push_back(matrix[i][cs]);
        }
        cs++;
        }
        return v;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends