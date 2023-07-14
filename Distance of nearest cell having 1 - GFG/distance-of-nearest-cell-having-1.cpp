//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{  public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n=grid.size();
	    int m=grid[0].size();
	    	vector<vector<int>> ans(n,vector<int> (m,0));
	    	vector<vector<int>> vis(n,vector<int> (m,0));
	    	queue<pair<pair<int,int>,int>> qp;
 int delrow[4]={0,-1,0,1};
    int delcol[4]={-1,0,1,0};
	    	for(int i=0;i<n;i++){
	    	    for(int j=0;j<m;j++){
	    	        if(grid[i][j]==1) {
	    	            qp.push({{i,j},0});
	    	            vis[i][j]=1;
	    	    }
	    	}}
	    	 while(!qp.empty()){
        int row=qp.front().first.first;
        int col=qp.front().first.second;
        int steps=qp.front().second;
        qp.pop();
       
        
            for(int p=0;p<4;p++){
                int nrow=row+delrow[p];
                int ncol=col+delcol[p];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==0){
                   ans[nrow][ncol]=steps+1;
                   qp.push({{nrow,ncol},steps+1});
                    vis[nrow][ncol]=1;
                }
            }
        
        
    }
	    	return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends