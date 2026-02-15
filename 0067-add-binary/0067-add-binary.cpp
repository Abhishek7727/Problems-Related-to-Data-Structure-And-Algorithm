class Solution {
public:
    string addBinary(string a, string b) {
        
        string res="";
        int carry=0;
        int n=a.length()-1;
        int m=b.length()-1;
        while(n>=0||m>=0||carry)
        {
            if(n>=0)
            {
                carry+=a[n]-'0';
                n--;
            }
            if(m>=0)
            {
                carry+=b[m]-'0';
                m--;
            }
            res+=carry%2 +'0';
            carry=carry/2;
        }
        reverse(res.begin(),res.end());
        return res;
    }
};