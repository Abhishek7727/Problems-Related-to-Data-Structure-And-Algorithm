class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        stack<int>st;
        for(int i=0;i<arr.size();i++)
        {
            int curr=arr[i];
            if(!st.empty() &&curr <0 && st.top()>0 )
            {
               
                while(!st.empty() && abs(curr)>abs(st.top()) && st.top()>0)
                {
                    st.pop();
                    
                }
                 if(!st.empty() && abs(curr)<abs(st.top()) && curr <0 && st.top()>0)
                   continue;
                if(!st.empty() && abs(curr)==abs(st.top())  &&curr <0 && st.top()>0)
                {
                    st.pop();
                    //continue;
                }
               else
                st.push(curr);
            

            }
            else
            st.push(arr[i]);
        }
        int n=st.size();
        vector<int>res(n);
        int i=1;
        while(st.size()>0)
        {
           res[n-i]=st.top();
           st.pop();
           i++;
        }
        return res;
        
    }
};