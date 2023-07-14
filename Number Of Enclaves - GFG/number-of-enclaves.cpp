//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &mat) {
        // Code here
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++){
        if(mat[i][0]==1){
            q.push({i,0});
            vis[i][0]=1;
        }
        if(mat[i][m-1]==1)
       { q.push({i,m-1});
       vis[i][m-1]=1;}
    }
    for(int j=1;j<m-1;j++){
        if(mat[0][j]==1)
        {q.push({0,j});
         vis[0][j]=1;}
        
        if(mat[n-1][j]==1)
        {q.push({n-1,j});
        vis[n-1][j]=1;}
    }
    
    int delrow[4]={0,-1,0,1};
    int delcol[4]={-1,0,1,0};
    while(!q.empty()){
        int row=q.front().first;
        int col=q.front().second;
         mat[row][col]=0;
        q.pop();
         for(int p=0;p<4;p++){
                int nrow=row+delrow[p];
                int ncol=col+delcol[p];
               
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && mat[nrow][ncol]==1){
                   
                   q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                }
            }
    }
   int count=0;
   for(int i=0;i<n;i++){
       for(int j=0;j<m;j++){
           if(mat[i][j]==1) count++;
       }
   }
   return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends