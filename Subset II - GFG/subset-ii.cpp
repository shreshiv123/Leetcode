//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    void solve(int i,vector<int>& nums,vector<int> &ds,vector<vector<int>> &ans){
        
        
            ans.push_back(ds);
            
        for(int j=i;j<nums.size();j++){
            if(j>i && nums[j]==nums[j-1]) continue;
            ds.push_back(nums[j]);
            solve(j+1,nums,ds,ans);
            ds.pop_back();
        }
    }

  public:
    vector<vector<int>> printUniqueSubsets(vector<int>& nums) {
        // Write your code here
        sort(nums.begin(),nums.end());
         vector<vector<int>> ans;
         vector<int> ds;
         solve(0,nums,ds,ans);
         return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;
        vector<vector<int>> ans = obj.printUniqueSubsets(nums);
        sort(ans.begin(), ans.end());
        //   printAns(ans);
        cout << "[ ";
        for (int i = 0; i < ans.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < ans[i].size(); j++) cout << ans[i][j] << " ";
            cout << "]";
        }
        cout << " ]\n";

        // cout<< "~\n";
    }

    return 0;
}

// } Driver Code Ends