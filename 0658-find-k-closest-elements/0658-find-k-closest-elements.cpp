class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>>maxH;
        for(int i=0;i<k;i++)
        {
            int y=abs(arr[i]-x);
            maxH.push({y,arr[i]});

        }
        for(int i=k;i<arr.size();i++)
        {
            int y=abs(arr[i]-x);
            if(maxH.top().first>y || (maxH.top().first==y && maxH.top().second>arr[i]))
            {
                maxH.pop();
                maxH.push({y,arr[i]});
            }
            
        }
        vector<int>ans;
        while(maxH.size()>0)
        {
            ans.push_back(maxH.top().second);
            maxH.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};