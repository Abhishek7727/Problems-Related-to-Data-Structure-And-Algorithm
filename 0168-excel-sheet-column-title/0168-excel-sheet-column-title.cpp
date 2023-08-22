class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;
      //  int n=0;
        while(columnNumber)
        {
            columnNumber--;
            int m=columnNumber%26;
            columnNumber/=26;
            ans+='A'+m;
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};