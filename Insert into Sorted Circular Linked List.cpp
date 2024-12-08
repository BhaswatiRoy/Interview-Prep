Problem: https://leetcode.com/problems/insert-into-a-sorted-circular-linked-list/description/

/*
Approach:
Case 1: list empty so add new node & return 
Case 2: normal insertion between list: 1 2 4 5 (insert 3) (insert between 2 & 4)
Case 3: boundary insertion in list: 3 4 1 (insert 9) (insert between 4 & 9)
Case 4: no suitable place to insert: 5 6 7 8 (insert 2) (insert in last in that case) (insert between 8 & 5)

TC: O(n) -> worst case traversal of full list
SC: O(1)
*/

Node* insert(Node* head, int insertVal) 
{
        Node* temp=head;
        Node* newnode=new Node(insertVal);
        //list is empty
        if(head==NULL)
        {
            //make the node point to itself to make circular list
            newnode->next=newnode;
            return newnode;
        }
        while(true)
        {
            //normal insertion in between: 1 2 4 5 (insert 3)
            //temp = 2, temp->next = 4
            if(temp->val<=insertVal && temp->next->val>=insertVal)
            {
                break;
            }
            //end point of LL -> 3 4 1 (4 is breakpoint) (1 < 4)
            if(temp->val>temp->next->val)
            {
                //boundary insertion: 3 4 1 (insert 9) (will be after 4 & before 1)
                //boundary condition with last element (4) or with first element (1) should match
                if(temp->val<=insertVal || temp->next->val>=insertVal)
                {
                    break;
                }
            }
            temp=temp->next;
            //if we reached end of LL and didn't find suitable position break
            //insert anywhere in that case: 5 6 7 8 (insert 2)
            if(temp==head)
            {
                break;
            }
        }
        newnode->next=temp->next;
        temp->next=newnode;
        return head;
}
