class Solution {
public:
    int leastInterval(vector<char>& task, int gap) {
       int seat=1;
       int n=task.size();
       unordered_map<char,int>mp;
       unordered_map<char,int>nextPos;
       for(int i=0;i<n;i++)
       {
        mp[task[i]]++;
        nextPos[task[i]]=1;
       }

       priority_queue<pair<int,char>>maxH;
       for(auto x:mp)
       {
        maxH.push({x.second,x.first});
       }

       while(maxH.size()>0)
       {
           vector<pair<int,char>>temp;
           while(maxH.size()>0)
           {
            pair<int,char>ele=maxH.top();
            maxH.pop();
            if(nextPos[ele.second]<=seat)
            {
                if(ele.first>1)
                {
                    maxH.push({ele.first-1,ele.second});
                   
                }
                nextPos[ele.second]=seat+gap+1;
                break;
            }
            else
            {
                temp.push_back(ele);
            }

           }
           for(int i=0;i<temp.size();i++)
           {
            maxH.push(temp[i]);
           }
           seat++;
       }
       return seat-1;

        
    }
};