Problem: https://leetcode.com/problems/add-two-numbers/description

/*
Approach 1:
1. Create a new list and keep 2 pointers to that one to iterate and another to store head of new list
2. Iterate through the lists until both are empty or any carry is left to include
3. Find sum & carry at each point and take ahead the carry if needed
4. In end return head of list
TC: O(n) -> iterating through the longer list
SC: O(n) -> creating a new list

Approach 2: 
1. Everything is same as above just instead of a new list we change values in place
2. We also keep a "last" node to track the last processed node
3. So if l1 is shorter than l2 and l1 finishes early then we need to add new nodes
4. To add new nodes the "last" node will keep track of last processed node and append behind that.
TC: O(n)
SC: O(1)
*/

//creating a new list
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{
        //variables for tracking sum & carry
        int sum=0, carry=0;
        //ans will iterate and create the new list
        //head will point to start of new list
        ListNode* ans=new ListNode();
        ListNode* head=ans;
        //iterate till both lists done or carry is 0
        //because if carry is not 0 then we have to add carry to end
        while(l1!=NULL || l2!=NULL || carry!=0)
        {
            sum=0;
            if(l1!=NULL)
            {
                int val1=l1->val;
                sum+=val1;
                l1=l1->next;
            }
            if(l2!=NULL)
            {
                int val2=l2->val;
                sum+=val2;
                l2=l2->next;
            }
            sum+=carry;
            //sum = 11 then we will put 11%10 = 1 into node 
            //and put 11/10 = 1 into carry
            carry=sum/10;
            ListNode *newnode=new ListNode(sum%10);
            ans->next=newnode;
            ans=ans->next;
        }
        return head->next;
}

//changing values in place
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{
        //variables for tracking sum & carry
        int sum=0, carry=0;
        //iterate till both lists done or carry is 0
        //because if carry is not 0 then we have to add carry to end
        ListNode *head=l1;
        //the last pointer tracks the last processed node
        //so if l1 ends and we need to append new nodes we can use this
        ListNode *last;
        while(l1!=NULL || l2!=NULL || carry!=0)
        {
            sum=0;
            if(l1!=NULL)
            {
                int val1=l1->val;
                sum+=val1;
            }
            if(l2!=NULL)
            {
                int val2=l2->val;
                sum+=val2;
                l2=l2->next;
            }
            sum+=carry;
            //sum = 11 then we will put 11%10 = 1 into node 
            //and put 11/10 = 1 into carry
            carry=sum/10;
            //if l1 is not finished just keep changing values in place
            if(l1!=NULL)
            {
                l1->val=(sum%10);
                last=l1;
                l1=l1->next;
            }
            //if l1 is finished then add new nodes
            //use the last pointer to track the last node 
            else
            {
                last->next=new ListNode(sum%10);
                last=last->next;
            }
        }
        return head;
}
