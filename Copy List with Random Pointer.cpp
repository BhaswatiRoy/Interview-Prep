Problem: https://leetcode.com/problems/copy-list-with-random-pointer/description

/*
Approach 1: extra space used
1. Store the original node as a key, and copy nodes as values in a map
2. Iterate through the original list and store everything on the map
3. Iterate again through the original list to set next & random pointers for copy nodes
4. return the copy node head at the end
TC: O(n) + O(n) -> double traversal
SC: O(n) -> hashmap used

Approach 2: no extra space used
1 -> 1_copy -> 2 -> 2_copy
1. Insert copy nodes within the original nodes
2. Each node's next node is the copy node
3. Set random pointers of each copy node using random pointers of the original node
4. Finally set the next pointers of each copy node using the next pointers of the original node
5. Also set the original pointers to the original next node correctly
TC: O(n) + O(n) + O(n) -> triple traversal
SC: O(1) 
*/

//Approach 1: extra space used
Node* copyRandomList(Node* head) 
{
        if(head==NULL)
        {
            return NULL;
        }
        Node *deepcopy=new Node(head->val);
        //pointer to iterate through the actual list
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
            //extract the value (copy node) using the key (original node)
            Node *copynode=mp[temp];
            //set the next pointer to the original node's next pointer
            copynode->next=mp[temp->next];
            //set random pointer to original node's random pointer
            copynode->random=mp[temp->random];
            temp=temp->next;
        }
        return mp[head];
}

//Approach 2: no extra space used
Node* copyRandomList(Node* head) 
{
        if(head==NULL)
        {
            return NULL;
        }
        Node *deepcopy=new Node(head->val);
        Node *temp=head;
        //insert copy nodes in between
        //original pointing to copy, copy pointing to original's next
        while(temp!=NULL)
        {
            Node *copynode=new Node(temp->val);
            copynode->next=temp->next;
            temp->next=copynode;
            //temp->next is copy node, temp->next->next is original's next node
            temp=temp->next->next;
        }
        temp=head;
        //set random pointers for copy node
        while(temp!=NULL)
        {
            //copy node's random pointer set
            //temp->random->next is where the copy list is
            if(temp->random!=NULL)
            {
                temp->next->random=temp->random->next;
            }
            //temp->next is copy node, temp->next->next is original's next node
            temp=temp->next->next;
        }
        temp=head;
        //iterate in the copy list
        Node *result=temp->next;
        Node *copyhead=temp->next;
        while(temp!=NULL)
        {
            //original node's next was initially pointed to copy 
            //now its pointing to the original's next
            temp->next=temp->next->next;
            //increment temp to next original node
            temp=temp->next;
            //next of next original node is copy's next
            if(result->next!=NULL)
            {
                result->next=temp->next;
            }
            //increment result
            result=result->next;
        }
        return copyhead;
}
