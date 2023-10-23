//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
      string ans="",help="";
      reverse(S.begin(),S.end());
      for(int i=0;i<S.length();i++)
      {
          if(S[i]=='.')
          {
              reverse(help.begin(),help.end());
              ans+=help+'.';
              help="";
          }
          else
          {
              help+=S[i];
          }
      }
      reverse(help.begin(),help.end());
      ans+=help;
      return ans;
        
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends