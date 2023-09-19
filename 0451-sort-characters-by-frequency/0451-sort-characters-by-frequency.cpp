class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
        }
        priority_queue<pair<int,char>>maxh;
        for(auto it:mp)
        {
            maxh.push({it.second,it.first});
        }
        
        string ans;
        while(maxh.size()>0)
        {
            auto it=maxh.top();
            while(it.first!=0)
            {
                ans.push_back(it.second);
                it.first--;
            }
            maxh.pop();
        }
        
        return ans;
        
        
        
    }
};