class LRUCache {
    struct Node {
        int key,value;
        Node *prev,*next;
        Node(int k,int v)
        {
            this->key=k;
            this->value=v;
            prev=NULL;
            next=NULL;
        }
    };
    int cap;
    unordered_map<int,Node*>mp;
    Node *head= new Node(-1,-1);
    Node *tail=new Node (-1,-1);

public:

    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
        
    }
    void addAfterHead(Node* node)
    {
        Node *temp=head->next;
        node->next=temp;
        node->prev=head;
        temp->prev=node;
        head->next=node;
    }
    void deleteNode(Node * node)
    {
        Node* prevNode=node->prev;
        Node * nextNode= node->next;

        prevNode->next=nextNode;
        nextNode->prev=prevNode;


    }

    
    int get(int key) {

        if(mp.find(key)!=mp.end())
        {
            Node* node=mp[key];
            deleteNode(node);
            addAfterHead(node);
            return node->value;

        }
        return -1;

        
    }
    
    void put(int key, int value) {

        if(mp.find(key)!=mp.end())
        {
           Node* node=new Node(key,value);
           
            deleteNode(mp[key]);
             mp[key]=node;
            addAfterHead(node);
        }
        else
        {
            if(mp.size()==cap)
            {
                mp.erase(tail->prev->key);
                deleteNode(tail->prev);
            }
            addAfterHead(new Node(key,value));
            mp[key]=head->next;
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */