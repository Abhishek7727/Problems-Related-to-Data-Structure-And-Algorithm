class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int cnt=INT_MIN;
        unordered_map<int,int>mp;
        int i=0,j=0;
        while(j<fruits.size())
        {
            mp[fruits[j]]++;
         
             if(mp.size()<=2)
            {
                cnt=max(cnt,j-i+1);
                j++;
            }
            else if(mp.size()>2)
            {
                while(mp.size()>2)
                {
                    mp[fruits[i]]--;
                    if(mp[fruits[i]]==0)
                    {
                        mp.erase(fruits[i]);
                    }
                    i++;
                }
                j++;
                
            }

        }
        return cnt;
        
    }
};