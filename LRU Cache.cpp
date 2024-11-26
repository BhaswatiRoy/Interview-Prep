Problem: https://leetcode.com/problems/lru-cache/description

/*
1. Create a doubly linked list for 2 values (key & value) and 2 pointers (prev & next)
2. Create a map to store the key and the node address to check which nodes exist in the cache
3. Create 2 functions to insert & remove nodes - inserting right after the head & removing right before the tail
4. In the get() function, we check if the map does not have the key then return -1
5. Otherwise if it exists in the map, then remove the node and reinsert it right after the head because its LRU
6. In the put() function, if the map has the key, then update the value of the key, and remove & reinsert it after the head because its LRU
7. Otherwise, if the map does not have the key, we check if the capacity is not filled and then just insert the node.
8. And if the capacity is full then we remove the node right before the tail because its not used since a long. 

TC: O(1) + O(1) -> get() + put() 
SC: O(capacity) -> max space of doubly linked list/map
*/

//define the node for the doubly linked list
//has 2 node value (key + value) & 2 pointers (prev + next)
class Node
{
        public:
            int key, val;
            Node* prev;
            Node* next;
            Node(int key, int val)
            {
                this->key = key;
                this->val = val;
                next=NULL;
                prev=NULL;
            }
  };
    
unordered_map<int,Node*>mp;
Node* head;
Node* tail;
int lrucapacity;

void insertnode(Node* node)
{
        //insert right after head
        node->next=head->next;
        head->next->prev=node;
        head->next=node;
        node->prev=head;
}

void removenode(Node* node)
{
        //prev node pointing to next node & next node pointing to prev node
        node->prev->next=node->next;
        node->next->prev=node->prev;
}

LRUCache(int capacity) 
{
        lrucapacity=capacity;
        //dummy head & tail to store key, value
        head=new Node(0,0);
        tail=new Node(0,0);
        head->next=tail;
        tail->prev=head;
}

int get(int key) 
{
        //the map does not have the key
        if(mp.find(key)==mp.end())
        {
            return -1;
        }
        Node* node=mp[key];
        removenode(node);
        insertnode(node);
        return node->val;
}
    
void put(int key, int value) 
{
        //if the value already exists in the map
        if(mp.find(key)!=mp.end())
        {
            //update the value of key
            Node* node=mp[key];
            node->val=value;
            //remove & reinsert the node after head because its LRU
            removenode(node);
            insertnode(node);
        }
        //if the value does not exist in the map
        //check if the size is within capacity
        else 
        {
            if(mp.size()==lrucapacity)
            {
                Node* lru=tail->prev;
                mp.erase(lru->key);
                removenode(lru);
                delete lru;
            }
            Node* newnode=new Node(key,value);
            mp[key]=newnode;
            insertnode(newnode);
        }
}
