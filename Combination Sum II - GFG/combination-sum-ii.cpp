//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    void solve(int i,vector<int> &A,int B,vector<int> &temp, vector<vector<int>> &ans){
        
            if(B==0) {ans.push_back(temp);
            return;}
        
        for(int j=i;j<A.size();j++){
            
        if(j>i && A[j]==A[j-1]) continue;
        if(A[j]>B)break;
            temp.push_back(A[j]);
            solve(j+1,A,B-A[j],temp,ans);
            temp.pop_back();
            
    
        }
    }
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    vector<vector<int> > combinationSum2(vector<int> &A, int B) {
        sort(A.begin(),A.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0,A,B,temp,ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> candidates(n);
        for (int i = 0; i < n; ++i) {
            cin >> candidates[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;

        vector<vector<int>> comb = obj.combinationSum2(candidates, k);
        sort(comb.begin(), comb.end());
        cout << "[ ";
        for (int i = 0; i < comb.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < comb[i].size(); j++) {
                cout << comb[i][j] << " ";
            }
            cout << "]";
        }
        cout << " ]\n";

        // cout << "\n~\n";
    }
    fclose(stdout);
    return 0;
}

// } Driver Code Ends