class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      //  unordered_set<string>str;
       int left=0,len=0;
       unordered_map<char,int>mp;
        for(int i=0;i<s.length();i++)
        {
            mp[s[i]]++;
            while(mp[s[i]]>1)
            {
                char ch=s[left];
                mp[ch]--;
                left++;
            }
            len=max(len,i-left+1);
        }
        return len;
        
    }
};