class Solution {
public:
  struct comparator
    {
        bool operator() (pair<int, string>& a, pair<int, string>& b)
        {
            if(a.first == b.first)           // if frequency are equal put lexicographically greater element on top
            {
                return a.second < b.second;
            }
            else                            // if frequency are not equal put the elements on top which has less frequency
            {
                return a.first > b.first;
            }
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mp;
        for(string w:words)
        {
            mp[w]++;
        }
        priority_queue<pair<int,string>, vector<pair<int,string>>,comparator>minH;
        for(auto x:mp)
        {
            minH.push({x.second,x.first});
            if(minH.size()>k)
            minH.pop();
        }
        vector<string>ans;
       while(minH.size())
        {
            ans.push_back(minH.top().second);
            minH.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};