class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>ans;
        int i=0;
        for(int num=1;num<=n && i<target.size();num++)
        {
            if(target[i]==num)
            {
                ans.push_back("Push");
                i++;
            }
            else{
                ans.push_back("Push");
                ans.push_back("Pop");
               
            }
        }
        return ans;
        
    }
};