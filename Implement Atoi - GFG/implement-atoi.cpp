//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        //Your code here
        int ans=0,flag=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='-'||s[i]=='+')
            {
                if(i!=0)
                return -1;
                flag++;
                continue;
            }
            if((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<='Z'))
            return -1;
             
            int val=s[i]-'0';
            ans=ans*10+val;
        }
        if(flag!=0)
        return -ans;
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