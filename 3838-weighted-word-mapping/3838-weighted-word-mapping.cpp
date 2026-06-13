class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans="";
        for(int i=0;i<words.size();i++)
            {
                string s=words[i];
                int sum=0;
                for(char ch:s)
                    {
                        sum+=weights[ch-'a'];
                    }
                int mod=sum%26;
                char ch='z'-mod;
                ans.push_back(ch);
            }
        //cout<<ans<<" ";
        return ans;
            
    }
};