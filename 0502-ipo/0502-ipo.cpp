class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();
        vector<pair<int,int>>proj;
        for(int i=0;i<n;i++)
        {
            proj.push_back({capital[i],profits[i]});
        }
        sort(proj.begin(),proj.end());
        priority_queue<int>maxH;
        int idx=0;
        while(k--)
        {
            while(idx<n){

            if(proj[idx].first>w)
            break;
            maxH.push(proj[idx].second);
            idx++;
            }

            if(maxH.empty())
            return w;
            w=w+maxH.top();
            maxH.pop();

        }
        return w;
        
    }
};