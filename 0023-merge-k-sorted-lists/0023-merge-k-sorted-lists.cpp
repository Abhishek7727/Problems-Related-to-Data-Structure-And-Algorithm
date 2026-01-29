/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>minH;

        for(int i=0;i<lists.size();i++)
        {
          //  ListNode* head=lists[i];
            if(lists[i] != nullptr) 
            minH.push({lists[i]->val,lists[i]});
        }
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        while(minH.size()>0)
        {
            auto it=minH.top();
            minH.pop();
            if(it.second->next)
            {
                minH.push({it.second->next->val,it.second->next});
                
            }
            temp->next=it.second;
            temp=temp->next;
        }
        return dummy->next;



        
    }
};