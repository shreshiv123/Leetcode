//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        // code here 
        int i=0,j=0,k=n-1;
        while(j<=k && i<=j){
            if(a[j]==0){
                a[j]=a[i];
                a[i]=0;
                i++;
                j++;
            }
            else if(a[j]==2){
                a[j]=a[k];
                a[k]=2;
                k--;
            }
            else j++;
        }
    }
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends