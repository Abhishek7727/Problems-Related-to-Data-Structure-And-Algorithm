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
    ListNode* rotateRight(ListNode* head, int k) {
        
         if(head==NULL)
        return NULL;
        ListNode* temp=head;
        int l=1;
        ListNode* prev=NULL;
        while(temp->next!=NULL)
        {
            l++;
            temp=temp->next;
        }
        temp->next=head;
        //int x=(l-k>0)?(l-k):(k-l);
        k=k%l;
        int x=l-k;
        if(x==0)
        return head;
        
        while(x--)
        {
            prev=head;
            head=head->next;
        }
        prev->next=NULL;
        return head;
        
    }
};