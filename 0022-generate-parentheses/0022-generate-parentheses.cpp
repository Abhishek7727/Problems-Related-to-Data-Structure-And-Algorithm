class Solution {
public:
    vector<string> generateParenthesis(int n) {
        
        vector<string>ans;
        int close=n;
        int open=n;
        string op="";
        solve(op,open,close,ans);
        return ans;
    }
    void solve(string op,int open,int close,vector<string>& ans)
    {
        if(open==0 && close==0)
        {
            ans.push_back(op);
            return;
        }
        if(open!=0)
        {
            string op1=op;
            op1.push_back('(');
            solve(op1,open-1,close,ans);
        }
        if(close>open)
        {
             string op2=op;
            op2.push_back(')');
            solve(op2,open,close-1,ans);
        }
    }
};