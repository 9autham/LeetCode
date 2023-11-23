//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> maxCombinations(int n, int k, vector<int> &a, vector<int> &b) {
        // first sort a both array
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        // create a priority queue of max heap
        priority_queue<int> pq;
        
        for(int i = n-1 ; i >= 0 ; i--){
            for(int j = n-1 ; j >= 0 ; j--){
                // insert a negative element for mean heap
                int sum = (a[i] + b[j]) * -1;
                if(pq.size() < k){
                    pq.push(sum);
                }else if(sum < pq.top()){
                    pq.pop();
                    pq.push(sum);
                }else break;
            }
        }
       // create a vector of size k
        vector<int> result(k--);

        // geting value in vector
        while(!pq.empty()){
            // make value positive at their position
            result[k--] = pq.top()*-1;
            pq.pop();
        }
        
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> B[i];
        }
        Solution obj;
        vector<int> ans = obj.maxCombinations(N, K, A, B);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends