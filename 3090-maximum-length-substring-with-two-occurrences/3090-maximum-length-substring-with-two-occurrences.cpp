class Solution {
public:
    int maximumLengthSubstring(string s) {
      int i=0,j=0;
      int ans=0;
      unordered_map<char,int>mp;
      while(j<s.size())
      {
        mp[s[j]]++;
       
        
            while(mp[s[j]]>2)
            {
                mp[s[i]]--;
                if(mp[s[i]]==0)
                mp.erase(mp[s[i]]);
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        
      }
return ans;
        
    }
};