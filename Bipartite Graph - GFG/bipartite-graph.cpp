//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    bool bfs(int node,int col,vector<int>adj[],vector<int> &vis){
        queue<int> q;
        vis[node]=0;
        q.push(node);
        while(!q.empty()){
            int currNode=q.front();
            
            q.pop();
            for(auto it:adj[currNode]){
                if(vis[it]==-1){
                    vis[it]=!vis[currNode];
                    q.push(it);
                }
                else if(vis[it]==vis[currNode]) return false;
            }
        }
        return true;
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    
	    vector<int> vis(V,-1);
	    for(int i=0;i<V;i++){
	        if(vis[i]==-1){
	            if(bfs(i,0,adj,vis)==false) return false;
	        }
	    }
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends