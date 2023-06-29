//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    bool isPossible(int mid,vector<int> &p,int h){
        int H=0;
        for(int i=0;i<p.size();i++){
            if(p[i]%mid==0) H+=p[i]/mid;
            else H=H+1+(p[i]/mid);
        }
        return H<=h;
    }
  public:
    int Solve(int N, vector<int>& piles, int H) {
        // Code here
        int s=1,e=INT_MAX;
        int ans=-1;
        int mid=s+(e-s)/2;
        while(s<=e){
            if(isPossible(mid,piles,H)){
                ans=mid;
                e=mid-1;
            }
            else s=mid+1;
            mid=s+(e-s)/2;
        }
        return ans;
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
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends