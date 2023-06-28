//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool Search(int N, vector<int>& A, int Key) {
        int s=0,e=N-1;
        int mid=s+(e-s)/2;
        while(s<=e){
            if(A[mid]==Key) return 1;
            if(A[mid]==A[s] && A[mid]==A[e]){
                s=s+1;
                e=e-1;
                continue;
            }
            if(A[mid]>=A[s]){
              if(A[mid]>Key && A[s]<=Key)
                e=mid;
                else s=mid+1;
            }
            else {
                if(A[mid]<Key && Key<=A[e])
                s=mid+1;
                else e=mid;
            }
            mid=s+(e-s)/2;
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int key;
        cin >> key;

        Solution obj;
        cout << obj.Search(n, a, key) << "\n";
    }
    return 0;
}
// } Driver Code Ends