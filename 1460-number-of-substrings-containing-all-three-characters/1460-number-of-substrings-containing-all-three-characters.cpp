class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int>mp;
        mp['a']=0;
        mp['b']=0;
        mp['c']=0;
        int n=s.size();
        int i=0,j=0,count=0;
        while(j<s.size())
        {
            char ch=s[j];
           
                mp[ch]++;
                while(mp['a']>0 && mp['b']>0 &&mp['c']>0)
                {
                    count+=n-j;
                    mp[s[i]]--;
                    i++;
                }
                j++;
        
        }  
        return count;
        
    }
};