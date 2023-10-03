//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& sl) {
        //code here
        
        vector<string> temp=sl;
        unordered_map<string,vector<int>> mp;
        for(int i=0;i<sl.size();i++){
            sort(temp[i].begin(),temp[i].end());
            mp[temp[i]].push_back(i);
        }
        vector<vector<string>> ans;
        for(auto it:mp){
            vector<string> tempu;
            for(auto itt:it.second){
                tempu.push_back(sl[itt]);
            }
           
            ans.push_back(tempu);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}

// } Driver Code Ends