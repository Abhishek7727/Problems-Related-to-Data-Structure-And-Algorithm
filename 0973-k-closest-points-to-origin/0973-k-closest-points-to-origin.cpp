class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& arr, int k) {
        vector<vector<int>>ans;
        priority_queue<pair<int,pair<int,int>>>maxH;
      
        for(int i=0;i<arr.size();i++)
        {
             maxH.push({arr[i][0]*arr[i][0]+arr[i][1]*arr[i][1],{arr[i][0],arr[i][1]}});
             if(maxH.size()>k)
             {
                maxH.pop();
             }
        }
        while(maxH.size())
        {
            ans.push_back({maxH.top().second.first,maxH.top().second.second});
            maxH.pop();
        }
        return ans;
        
    }
};