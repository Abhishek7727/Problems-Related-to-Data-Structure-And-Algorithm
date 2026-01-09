class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int maxLen=0;
        int start=0,end=0;
        int ans=0;
        unordered_map<int,int>mp;

        while(end<s.size())
        {
          mp[s[end]]++;
          maxLen=max(maxLen,mp[s[end]]);

      

          while((end-start+1)-maxLen>k)
          {
            mp[s[start]]--;         
            start++;
          }
         
        
          ans =max(ans,end-start+1);
          end++;
        }
        return ans;
    }
};