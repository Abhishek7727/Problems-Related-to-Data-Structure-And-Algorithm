class Solution {
public:
    vector<vector<int>>mergeOverLap(vector<vector<int>>&arr)
    {
        int start1=arr[0][0];
        int end1=arr[0][1];
        vector<vector<int>>ans;
        for(int i=1;i<arr.size();i++)
        {
           int start2=arr[i][0];
           int end2=arr[i][1];
            if(end1>=start2)
            {
                start1=start1;
                end1=max(end1,end2);
               
            }
            else{
                ans.push_back({start1,end1});
                start1=start2;
                end1=end2;

            }

        }
         ans.push_back({start1,end1});
         return ans;

    }
    vector<vector<int>> insert(vector<vector<int>>& arr, vector<int>& newInterval) {
        vector<vector<int>>res;
        bool flag=false;
        for(int i=0;i<arr.size();i++)
        {
            if(flag==false && arr[i][0]>=newInterval[0])
            {
                res.push_back({newInterval[0],newInterval[1]});
                flag=true;
            }
           res.push_back({arr[i][0],arr[i][1]});
        //    cout<< arr[i][0] <<" " ;
        //    cout<< arr[i][0] <<endl;
        }
        if(flag==false)
        {
             res.push_back({newInterval[0],newInterval[1]});
        }
        return mergeOverLap(res);
    }
};