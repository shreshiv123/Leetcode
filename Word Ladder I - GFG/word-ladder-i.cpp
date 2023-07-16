//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string Word, string ttWord, vector<string>& List) {
        // Code here
        set<string> st(List.begin(),List.end());
        queue<pair<string,int>> q;
        q.push({Word,1});
        while(!q.empty()){
            string currW=q.front().first;
            int len=q.front().second;
            if(currW==ttWord) return len;
            q.pop();
            for(int i=0;i<currW.size();i++){
                string orgW=currW;
                for(char it='a';it<='z';it++){
                    orgW[i]=it;
                    if(st.find(orgW)!=st.end()){
                        q.push({orgW,len+1});
                        st.erase(orgW);
                    }
                    orgW=currW;
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends