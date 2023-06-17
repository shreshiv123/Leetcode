//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{    void func(vector<string> &ans,string temp,int n,int op,int cl){
    
    if(cl>=n){
        ans.push_back(temp);
        return;
    }
    if(op<n){
        func(ans,temp+'(',n,op+1,cl);
    }
    if(cl<op){
        func(ans,temp+')',n,op,cl+1);
    }
}
    public:
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here
        vector<string> ans;
        string temp;
        func(ans,temp,n,0,0);
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
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends