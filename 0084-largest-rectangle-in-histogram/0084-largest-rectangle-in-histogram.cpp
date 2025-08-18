class Solution {
public:
   

    vector<int>nearestGreatestRight(vector<int>arr)
    {
        vector<int>v;
        stack<pair<int,int>>st;
        int idx=arr.size();
        for(int i=idx-1;i>=0;i--)
        {
            if(st.size()==0)
            {
                v.push_back(idx);
            }
            else if(st.size()>0 && st.top().first<arr[i])
            {
               v.push_back(st.top().second);
            }
            else if(st.size()>0 && st.top().first>=arr[i])
            {
                while(st.size()>0 && st.top().first>=arr[i])
                {
                    st.pop();
                }

                if(st.size()==0)
                {
                    v.push_back(idx);
                }
                else 
                {
                    v.push_back(st.top().second);   
                }
            }
            st.push({arr[i],i});
        }
        reverse(v.begin(),v.end());
        return v;   
    }
    vector<int>nearestGratestLeft(vector<int>arr)
    {
        vector<int>v;
        stack<pair<int,int>>st;
        int idx=-1;
        for(int i=0;i<arr.size();i++)
        {
            if(st.size()==0)
            {
                v.push_back(-1);
            }
            else if(st.size()>0 && st.top().first<arr[i])
            {
               v.push_back(st.top().second);
            }
            else if(st.size()>0 && st.top().first>=arr[i])
            {
                while(st.size()>0 && st.top().first>=arr[i])
                {
                    st.pop();
                }

                if(st.size()==0)
                {
                    v.push_back(-1);
                }
                else 
                {
                    v.push_back(st.top().second);   
                }
            }
            st.push({arr[i],i});
        }
        return v;

    }
    int largestRectangleArea(vector<int>& arr) {
    int n=arr.size();
    int ans=0;
    vector<int>left=nearestGratestLeft(arr);
    vector<int>right=nearestGreatestRight(arr);
    for(int i=0;i<n;i++)
    {
        int width=right[i]-left[i]-1;
        int area=width*arr[i];
        ans=max(ans,area);
    }
    return ans;
        
    }
};