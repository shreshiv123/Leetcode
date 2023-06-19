//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    bool dfs(vector<vector<char>>& b, string word,int row,int col,vector<vector<int>> &vis,int ind){
        if(ind==word.size()) return true;
        if(row>=b.size() || row<0 || col>=b[0].size() || col<0) return false;
        vis[row][col]=1;
        int delcol[4]={-1,0,1,0};
        int delrow[4]={0,-1,0,1};
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(ncol>=0 && ncol<b[0].size() && nrow>=0 && nrow<b.size() && !vis[nrow][ncol] && b[nrow][ncol]==word[ind]){
                if(dfs(b,word,nrow,ncol,vis,ind+1)) return true;
            }
        }
        vis[row][col]=0;
        return false;
    }
public:
    bool isWordExist(vector<vector<char>>& b, string word) {
        // Code here
        int n=b.size();
        int m=b[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        char s=word[0];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(b[i][j]==s){
                    if(dfs(b,word,i,j,vis,1)) return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends