class Solution {
public:
    int minPartitions(string str) {
        int ans=0;
        
        for(char s:str)
        {
            ans=max(ans,s-'0');
        }
        return ans;
        
    }
};