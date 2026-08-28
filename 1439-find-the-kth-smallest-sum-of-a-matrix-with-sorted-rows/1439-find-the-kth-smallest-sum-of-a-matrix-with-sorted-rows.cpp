class Solution {
public:
    int kthSmallest(vector<vector<int>>& nums, int k) {
        int n = nums.size(), m = nums[0].size();
        priority_queue<int> pq;
        for(int i = 0;i<m;i++){
            pq.push(nums[0][i]);
            if(pq.size() > k)pq.pop();
        }
        for(int i = 1;i<n;i++){
            priority_queue<int> temp,npq;
            for(int j = 0;j<m;j++){
                while(pq.size()){
                    temp.push(pq.top());
                    int a = pq.top() + nums[i][j];
                    pq.pop();
                    npq.push(a);
                    if(npq.size() > k)npq.pop();
                }
                swap(pq,temp);
            }
            swap(pq,npq);
        }
        return pq.top();
    }
};