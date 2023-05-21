//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
 void func(int ind,vector<vector<int>> &ans,vector<int>& nums,vector<int> temp){

         ans.push_back(temp);
         
     for(int i=ind;i<nums.size();i++){
         if(i!=ind && nums[i]==nums[i-1]) continue;
         temp.push_back(nums[i]);
         func(i+1,ans,nums,temp);
         temp.pop_back();
     }
 }
  public:
    vector<vector<int>> printUniqueSubsets(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        vector<int> temp;
        func(0,ans,nums,temp);
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