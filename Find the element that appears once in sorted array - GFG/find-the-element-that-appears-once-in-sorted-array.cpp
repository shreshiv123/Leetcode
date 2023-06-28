//{ Driver Code Starts
// Driver code

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
  public:
    int findOnce(int arr[], int n)
    {
        //code here.
        int s=0,e=n-1;
        int mid=(s+e)/2;
        while(s<e){
            if(mid%2==0){
                if(arr[mid+1]!=arr[mid]) 
                e=mid;
                else s=mid+2;
            }
            else{
                if(arr[mid-1]!=arr[mid]) e=mid-1;
                else s=mid+1;
            }
            mid=(s+e)/2;
        }
        return arr[e];
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for(int i = 0;i < n;i++)
        {
            cin>>A[i];
        }
        
        Solution ob;
        
        int res = ob.findOnce(A,n);
        cout << res << endl;
    }
    
    return 0;
}
// } Driver Code Ends