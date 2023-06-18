//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
      void solve(int i,int K,int N,vector<int> ds,vector<vector<int>> &ans){
         if(K==0 && N==0) {ans.push_back(ds);
         return;}
         for(int j=i;j<=9;j++){
             if(j>N) break;
             ds.push_back(j);
             solve(j+1,K-1,N-j,ds,ans);
             ds.pop_back();
         }
      }
  public:
    vector<vector<int>> combinationSum(int K, int N) {
        // code heresort(nums.begin(),nums.end());
         vector<vector<int>> ans;
         vector<int> ds;
         solve(1,K,N,ds,ans);
         return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K >> N;

        Solution obj;
        vector<vector<int>> ans = obj.combinationSum(K, N);
        sort(ans.begin(), ans.end());
        for (auto &arr : ans) {
            for (auto it : arr) cout << it << ' ';
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends