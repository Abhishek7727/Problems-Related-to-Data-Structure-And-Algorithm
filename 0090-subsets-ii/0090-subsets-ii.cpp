class Solution {
public:vector<vector<int>>ans;
    set<vector<int>>s;
    
    void solve(vector<int>input, vector<int>output){
        
        if(input.size() == 0){
            
            if(s.find(output) == s.end()){
                s.insert(output);
                ans.push_back(output);   
            }
            
            return;
        }
        
        vector<int>op1 = output, op2 = output;
        
        op1.push_back(input[0]);
        input.erase(input.begin() + 0);
        
        solve(input, op1);
        solve(input, op2);   
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        vector<int>op;
        
        solve(nums, op);
        return ans; 
    }
};