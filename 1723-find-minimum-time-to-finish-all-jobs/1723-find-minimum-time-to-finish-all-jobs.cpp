class Solution {
public:
    bool solve(int ind,vector<int>&jobs,vector<int>&worker,int limit)
    {
        if(ind==jobs.size())
        {
            return true;
        }
        for(int i=0;i<worker.size();i++)
        {
            if(worker[i]+jobs[ind]<=limit)
            {
                worker[i]+=jobs[ind];
            
            if(solve(ind+1,jobs,worker,limit))
            return true;
                    
            worker[i]-=jobs[ind];
            }    
                if(worker[i]==0)
                break;
            
        }
        return false;
    }
    int minimumTimeRequired(vector<int>& jobs, int k) {
        sort(jobs.rbegin(),jobs.rend());
        int low=*max_element(jobs.begin(),jobs.end());
        int high=accumulate(jobs.begin(),jobs.end(),0);

        int ans=high;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            vector<int>worker(k,0);
            if(solve(0,jobs,worker,mid))
            {
                ans=min(ans,mid);
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }

        }
        return ans;

        
    }
};