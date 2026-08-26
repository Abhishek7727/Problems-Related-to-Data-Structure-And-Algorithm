class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.size();
        int i=0;
        int j=0;
        string ans="";
        int bestLen=INT_MAX;
        int one=0;
        while(j<n)
        {
            if(s[j]=='1')
            one++;
            while(one==k)
            {
                int len=j-i+1;
                if(bestLen>j-i+1)
                {
                    bestLen=j-i+1;
                    ans=s.substr(i,bestLen);
                }
                else if(bestLen==len)
                {
                    string curr=s.substr(i,len);
                    if(ans>curr)
                    ans=curr;
                }
                if(s[i]=='1')
                one--;
                i++;
            }
            j++;
        }
        return ans;
    }
};