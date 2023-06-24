//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
         if(x.size() & 1) return false;
        // Your code here
        stack<char> st;
        int i=0;
        while(i<x.size()){
            if(x[i]=='{' || x[i]=='(' || x[i]=='[') st.push(x[i]);
            else if(st.empty()) return false;
            else {
                if((st.top()=='[' && x[i]!=']') || (st.top()=='{' && x[i]!='}') || (st.top()=='(' && x[i]!=')'))
                return false;
                else st.pop();
            }
            i++;
        }
        return true;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends