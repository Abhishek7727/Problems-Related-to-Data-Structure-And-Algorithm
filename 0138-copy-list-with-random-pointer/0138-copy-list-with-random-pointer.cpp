/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution{

public:
void insertAtTail(Node* &head, Node* &tail, int d) {
        Node* newNode = new Node(d);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail -> next = newNode;
            tail = newNode;
        }
    }
    
    Node* copyRandomList(Node* head) {
        Node* cloneHead=NULL;
        Node* cloneTail=NULL;
        Node* temp=head;
        while(temp!=NULL)
        {
            insertAtTail(cloneHead,cloneTail,temp->val);
            temp=temp->next;
        }
        unordered_map<Node*,Node*>mp;
        Node* org=head;
        Node* cpy=cloneHead;
        while(cpy!=NULL)
        {
            mp[org]=cpy;
            org=org->next;
            cpy=cpy->next;
        }
        org=head;
        cpy=cloneHead;
        while(cpy!=NULL)
        {
            cpy->random=mp[org->random];
            org=org->next;
            cpy=cpy->next;
        }
        return cloneHead;

        
    }
};