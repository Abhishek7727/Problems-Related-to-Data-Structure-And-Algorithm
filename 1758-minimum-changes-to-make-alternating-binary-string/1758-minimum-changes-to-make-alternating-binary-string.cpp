class Solution {
public:
    int minOperations(string s) {
        int one=0,zero=0;
        for(int i=0;i<s.length();i++)
        {
            if(i%2==0)
            {
                if(s[i]=='1')
                {
                    zero++;
                }
                else
                one++;
            }
            else
            {
                if(s[i]=='1')
                {
                    one++;
                }
                else
                zero++;
            }
        
        }
        return min(one,zero);
    }
};