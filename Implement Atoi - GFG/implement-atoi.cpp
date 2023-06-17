//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    void func(int &ans,int i,string str,bool &a){
        if(i>=str.size()) return;
        if(str[i]>='0' && str[i]<='9')ans= (ans*10) + str[i]-'0';
        else a=true;
        func(ans,i+1,str,a);
    }
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        int ans=0;
        bool a=false;
        if(str[0]=='-')
        func(ans,1,str,a);
        else func(ans,0,str,a);
        if(a) return -1;
        if(str[0]=='-') return -1*ans;
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
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends