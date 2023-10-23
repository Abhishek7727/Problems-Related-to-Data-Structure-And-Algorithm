//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
public:
    string solve(string s)
    {
        string res="";
        int i=0,n=s.length();
        while(i<n)
        {
            if(i<n-1 && s[i]==s[i+1])
            {
                while(s[i]==s[i+1] &&i<n-1)
                {
                    i++;
                }
            }
            else
            res+=s[i];
            i++;
        }
        return res;
    }
    string rremove(string s){
        // code here
        string ans=s,temp="";
        while(temp.size()!=ans.size())
        {
            temp=ans;
            ans=solve(ans);
        }
        return ans;
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