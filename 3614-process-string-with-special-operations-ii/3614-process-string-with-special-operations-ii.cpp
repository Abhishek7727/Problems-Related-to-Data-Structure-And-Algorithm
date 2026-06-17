typedef long long ll;
class Solution {
public:
    char processStr(string s, long long k) {
        ll len=0;
        for(char ch:s)
        {
            if(ch=='*' && len>0)
            len--;
            
            else if(ch=='#')
            len*=2;
            else if(ch>='a' && ch<='z')
            len++;
           
        }
        if(k>=len)
        return '.';

        for(int i=s.size()-1;i>=0;i--)
        {
            char ch=s[i];
            if(islower(ch)){
                 
            if(k==len-1)
            return ch;
            len--;
           
            }

            else if(ch=='*')
            {
                len++;
            }
            else if(ch=='#')
            {
                len=len/2;
                if(k>=len)
                {
                    k=k-len;
                }
            }
            else if(ch=='%')
            {
                k=len-k-1;
            }

        }
        return '.';

        
    }
};