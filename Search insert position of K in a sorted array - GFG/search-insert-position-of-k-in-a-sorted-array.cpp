//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int searchInsertK(vector<int>Arr, int N, int k)
    {
         int ans=-1;
        int s=0,e=N-1;
        int mid=s+(e-s)/2;
        while(s<=e){
            if(Arr[mid]==k) return mid;
            else if(Arr[mid]<k){
                ans=mid;
                s=mid+1;
            }
            else e=mid-1;
            mid=s+(e-s)/2;
        }
    
        return ans +1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        vector<int>Arr(N);
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.searchInsertK(Arr, N, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends