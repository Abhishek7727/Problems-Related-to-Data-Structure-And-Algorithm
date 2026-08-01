class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>>cars;
        for(int i=0;i<speed.size();i++)
        {
            cars.push_back({position[i],speed[i]});
        }
        sort(cars.begin(),cars.end(),greater<pair<int,int>>());
        stack<double>st;
        for(auto &x:cars)
        {
             double time=(double)(target-x.first)/x.second;
             if(st.empty() || time>st.top())
             {
                st.push(time);
             }
        }
        return st.size();
    }
};