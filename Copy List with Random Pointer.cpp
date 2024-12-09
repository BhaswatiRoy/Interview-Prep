Problem: https://leetcode.com/problems/copy-list-with-random-pointer/description

/*
Approach 1: extra space used
1. Store original node as key, and copy nodes as value in a map
2. Iterate through the original list and store everything in the map
3. Iterate again through the original list to set next & random pointers for copy nodes
4. return the copy node head in the end
TC: O(n) + O(n) -> double traversal
SC: O(n) -> hashmap used

Approach 2: no extra space used

*/

Node* copyRandomList(Node* head) 
{
        if(head==NULL)
        {
            return NULL;
        }
        Node *deepcopy=new Node(head->val);
        //pointer to iterate through actual list
        Node *temp=head;
        //storing {actual node, copy node}
        unordered_map<Node*,Node*>mp;
        //1st iteration: create all copy nodes & store in map
        while(temp!=NULL)
        {
            Node *newnode=new Node(temp->val);
            //key=actual node, value=copy node
            mp[temp]=newnode;
            temp=temp->next;
        }
        temp=head;
        //2nd iteration: set all next & random pointers
        while(temp!=NULL)
        {
            //extract the value (copy node) using key (original node)
            Node *copynode=mp[temp];
            //set next pointer to original node's next pointer
            copynode->next=mp[temp->next];
            //set random pointer to original node's random pointer
            copynode->random=mp[temp->random];
            temp=temp->next;
        }
        return mp[head];
}
