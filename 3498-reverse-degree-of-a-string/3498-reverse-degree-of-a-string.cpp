class Solution {
public:
    int reverseDegree(string s) {
        int ans=0;
        int i=1;
        for(char ch:s)
        {
            ans+=(26+'a'-ch)*i;
            i++;
        }
        return ans;
    }
};