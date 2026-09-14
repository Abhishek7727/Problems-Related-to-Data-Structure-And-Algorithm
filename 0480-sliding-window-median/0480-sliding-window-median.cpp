class Solution {
public:
    priority_queue<int>left;
    priority_queue<int,vector<int>,greater<int>>right;
    int leftSize=0,rightSize=0;
    unordered_map<int,int>delayed;

    void prunLeft()
    {
        while(!left.empty() && delayed[left.top()]>0)
        {
            delayed[left.top()]--;
            left.pop();
        }
    }
     void prunRight() {
        while (!right.empty() && delayed[right.top()] > 0) {
            delayed[right.top()]--;
            right.pop();
        }
    }
    
    void balance()
    {
        if(leftSize>rightSize+1)
        {
            prunLeft();
            right.push(left.top());
            left.pop();
            leftSize--;
            rightSize++;
        }
        else if(rightSize>leftSize)
        {
            prunRight();
            left.push(right.top());
            right.pop();
            rightSize--;
            leftSize++;
        }
    }

    void add(int n)
    {
        if(left.empty() || left.top()>=n)
        {
            left.push(n);
            leftSize++;
        }
        else{
        right.push(n);
        rightSize++;
        }

        balance();
    }
    void remove(int num)
    {
        delayed[num]++;
        if(!left.empty() && num<=left.top())
        {
            leftSize--;
            if(left.top()==num)
            prunLeft();
        }
        else
        {
            rightSize--;
            if(!right.empty() && right.top()==num)
            prunRight();

        }
        balance();
    }
    double getMedian()
    {
        prunLeft();
        prunRight();
        if(leftSize>rightSize)
        {
            return left.top();
        }
        return ((double)left.top()+right.top())/2.0;
    }
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double>ans;
        for(int i=0;i<k;i++)
        {
            add(nums[i]);
        }
        ans.push_back(getMedian());

        for(int i=k;i<nums.size();i++)
        {
            remove(nums[i-k]);
            add(nums[i]);
            ans.push_back(getMedian());
        }
        return ans;
        
    }
};