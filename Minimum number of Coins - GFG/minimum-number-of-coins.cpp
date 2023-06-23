//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> minPartition(int N)
    {
vector<int> ans;
int notes[10]={1,2,5,10,20,50,100,200,500,2000};
  int paise=N;
  int i=9;
  while(paise>0 && i>=0){
        while(paise<notes[i])i--;
        while(paise>=notes[i]){ ans.push_back(notes[i]);
         paise-=notes[i]; }
         i--;
        
  }
  return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> numbers = ob.minPartition(N);
        for(auto u: numbers)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends