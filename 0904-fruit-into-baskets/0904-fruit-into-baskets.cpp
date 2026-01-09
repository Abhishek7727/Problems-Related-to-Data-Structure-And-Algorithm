class Solution {
public:
    int totalFruit(vector<int>& arr) {
        int ans=0;
        int i=0,j=0;
        unordered_map<int,int>mp;
        while(j<arr.size())
        {
            mp[arr[j]]++;
            if(mp.size()<=2)
            ans=max(ans,j-i+1);

            else if(mp.size()>2)
            {
                while(mp.size()>2)
                {
                    mp[arr[i]]--;
                   
                    if(mp[arr[i]]==0)
                    mp.erase(arr[i]);
                     i++;
                }
              //  if(mp.size()==2)
                ans=max(ans,j-i+1);
            }
            j++;
        }
        return ans;
    }
};