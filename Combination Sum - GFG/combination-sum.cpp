//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
    void solve(int i,vector<int> &A,int B,vector<int> temp, vector<vector<int>> &ans){
        if(i>=A.size()){
            if(B==0) ans.push_back(temp);
            return;
        }
        if(A[i]<=B){
            temp.push_back(A[i]);
            solve(i,A,B-A[i],temp,ans);
            temp.pop_back();
        }
        while(i<A.size() && A[i]==A[i+1])i++;
        solve(i+1,A,B,temp,ans);
    }
  public:
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        sort(A.begin(),A.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0,A,B,temp,ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	
// } Driver Code Ends