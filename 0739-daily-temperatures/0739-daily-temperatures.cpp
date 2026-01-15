class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        vector<int>ans;
        stack<pair<int,int>>st;
        int n=arr.size();
        for(int i=n-1;i>=0;i--)
        {
            if(st.size()==0)
            ans.push_back(0);
            else if(st.top().first>arr[i])
            {
                ans.push_back(st.top().second-i);
            }
            else if(st.size()!=0 && st.top().first<=arr[i])
            {
                while(st.size()!=0 && st.top().first<=arr[i])
                {
                    st.pop();

                }
                if(st.size()==0)
                ans.push_back(0);
                else 
                 ans.push_back(st.top().second-i);

            }
            st.push({arr[i],i});
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};