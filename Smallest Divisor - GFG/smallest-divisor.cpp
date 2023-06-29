//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    bool isPossible(int mid,int K,vector<int> &nums){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%mid==0){
                sum=sum+(nums[i]/mid);
            }
            else sum=sum + 1 +(nums[i]/mid);
        }
        return sum<=K;
    }
  public:
    int smallestDivisor(vector<int>& nums, int K) {
      sort(nums.begin(),nums.end());
       
       int s=1,e=nums[nums.size()-1];
       int mid=(s+e)/2;
       int ans=1e9;
       while(s<=e){
           if(isPossible(mid,K,nums)){
               ans=min(ans,mid);
               e=mid-1;
           }
           else s=mid+1;
           mid=(s+e)/2;
       }
       return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n, k;
        cin >> n >> k;
        vector<int> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];

        Solution obj;
        cout << obj.smallestDivisor(vec, k) << endl;
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends