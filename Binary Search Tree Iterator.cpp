Problem: https://leetcode.com/problems/binary-search-tree-iterator/description

/*
      7
    /   \
   3     15
        /  \
      9      20
1. stack has -> {7,3} (3 on top)
2. next() gives 3 
3. next() gives 7 & 7 has right node so {15, 9} (9 on top) will be pushed
4. next() gives 9
5. next() gives 15 & 15 has right node so {20} (20 on top) will be pushed
6. next() gives 20 & 
7. hasnext() gives false
TC: O(n) -> covers all nodes
SC: O(H)-> at max it stores H elements i.e all on left
*/

stack<TreeNode*>st;
BSTIterator(TreeNode* root) 
{
        //push all elements from that node to left side of the node
        while(root!=NULL)
        {
            st.push(root);
            root=root->left;
        }
}
    
int next() 
{
        TreeNode* top=st.top();
        int topval=top->val;
        st.pop();
        //if the stack top node has a right
        TreeNode* node=top->right;
        //then push all left nodes of that right node in stack
        while(node!=NULL)
        {
            st.push(node);
            node=node->left;
        }
        return topval;
}
    
bool hasNext() 
{
        //if stack has elements then current element has its next
        if(!st.empty())
        {
            return true;
        }
        return false;
}
