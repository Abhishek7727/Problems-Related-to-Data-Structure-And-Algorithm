class Solution {
public:
    string smallestSubsequence(string s) {
        vector<bool>vis(26,false);
        vector<int>last(26);
        for(int i=0;i<s.size();i++)
        {
            last[s[i]-'a']=i;
        }
        string res="";
        
        for(int i=0;i<s.size();i++)
        {
            if(vis[s[i]-'a'])
            continue;

            while(!res.empty() && s[i]<res.back() && last[res.back()-'a']>i)
            {
                vis[res.back()-'a']=false;
                res.pop_back();
              
            }
            res+=s[i];
            vis[s[i]-'a']=true;
        }
        return res;
    }
};