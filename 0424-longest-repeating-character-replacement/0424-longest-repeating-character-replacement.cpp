class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0,right=0,ans=0,maxLen=0;
        unordered_map<int,int>mp;
        while(right<s.size())
        {
            mp[s[right]]++;
            maxLen= max(maxLen,mp[s[right]]);

            if((right-left+1)-maxLen>k)
            {
                while((right-left+1)-maxLen>k)
                {
                    mp[s[left]]--;
                    left++;
                }
            }

            ans=max(ans,right-left+1);
            right++;
        }
        return ans;
        
    }
};