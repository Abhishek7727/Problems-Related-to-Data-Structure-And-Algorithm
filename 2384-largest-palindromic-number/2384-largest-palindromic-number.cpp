class Solution {
public:
    string largestPalindromic(string s) {
        vector<int>freq(10,0);
        for(char ch:s)
        {
            freq[ch-'0']++;
        }
        string left="";
        int mid=-1;
        for(int i=9;i>=0;i--)
        {
            if(i==0 && left.empty())
            continue;
            for(int j=0;j<freq[i]/2;j++)
            {
                left+=char(i+'0');
            }
            if(freq[i]%2)
            mid=max(mid,i);
        }
        if(left.empty()&& mid==-1)
        return "0";
        string right=left;
        reverse(right.begin(),right.end());
        if(mid!=-1)
        return left+char(mid+'0')+right;

        return left+right;

        
    }
};