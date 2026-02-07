class Solution {
public:
    void solve(vector<int>& arr,int k,int i)
    {
        if(arr.size()==1)
        return;
        int idx=(i+k-1)%arr.size();
        arr.erase(arr.begin()+idx);
        solve(arr,k,idx);

    }
    int findTheWinner(int n, int k) {
        vector<int>v;
        for(int i=1;i<=n;i++)
        {
            v.push_back(i);
        }
        solve(v,k,0);
        return v[0];

        
    }
};