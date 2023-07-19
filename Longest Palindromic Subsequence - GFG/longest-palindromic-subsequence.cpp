//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    int func(int i,int j,string a,string b,int n,vector<vector<int>> &dp){
        if (i>=n || j>=n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=0;
        if(a[i]==b[j]) return dp[i][j]= 1 + func(i+1,j+1,a,b,n,dp);
        else {
            ans=func(i+1,j+1,a,b,n,dp);
           ans=max(ans,max(func(i+1,j,a,b,n,dp),func(i,j+1,a,b,n,dp)));
    }
    return dp[i][j]=ans;}
  public:
    int longestPalinSubseq(string a) {
        //code here
        
        string b=a;
        reverse(b.begin(),b.end());
        int n=a.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        return func(0,0,a,b,n,dp);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends