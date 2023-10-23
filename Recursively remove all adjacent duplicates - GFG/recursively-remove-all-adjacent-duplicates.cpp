//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
public:
  
    string rremove(string s){
        // code here
        string ans="";
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            if(s[i]==s[i+1])
            {
                while(s[i]==s[i+1])
                i++;
            }
            else
            {
                ans+=s[i];
            }
            
        }
        if(ans==s)
        return ans;
        return rremove(ans);

    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Solution ob;
        cout << ob.rremove(s) << "\n";
    }
    return 0;
}
// } Driver Code Ends