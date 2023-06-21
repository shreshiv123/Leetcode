//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  
  public:
    vector<int> nextGreaterElement(int N, vector<int>& arr) {
        int n=arr.size();
        vector<int> ans(n,-1);
        stack<long long> st;
        for(int i= 2*n-1;i>=0;i--){
            while(!st.empty() && st.top()<=arr[i%n]){
                st.pop();
            }
            if(!st.empty()) ans[i%n]=st.top();
            st.push(arr[i%n]);
        }
        /*vector<int>ans1;
        for(int i=0;i<n;i++) ans1.push_back(ans[i]);*/
        return ans;
    }

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        vector<int> ans = obj.nextGreaterElement(N, arr);
        for (auto &it : ans) {
            cout << it << ' ';
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends