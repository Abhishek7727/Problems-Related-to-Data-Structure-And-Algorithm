class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(auto x:tokens)
        {
            if(x=="+" || x=="-" || x=="/"|| x=="*")
            {
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                int res;
                if(x=="+") res=b+a;
                else if(x=="-") res=b-a;
                else if (x=="*") res=b*a;
                else {
                    res=b/a;
                }
                st.push(res);
            }
            else{
                 st.push(stoi(x));
            }

        }
        return st.empty() ? 0 : st.top();
    }
};