Problem: https://leetcode.com/problems/boundary-of-binary-tree/description

/*
1. Start with root->left and find the left boundary of the tree without leaf nodes
2. Start with root->right and find the reverse right boundary of tree using stack without leaf nodes
3. Start with root and find all the leaf nodes 
4. root + left boundary + leaves + reverse right boundary -> boundary Traversal

TC: O(h) + O(n) + O(h) + O(h) -> (h = height) left traversing + leaves + right traversing + elements from stack
SC: O(n) -> stack + output vector
*/

//left boundary without leaf nodes
void leftboundary(TreeNode *root, vector<int>&ans)
{
        //since we are passing root->left we check if its a blank subtree
        //or stop when we reach a leaf node
        if(root==NULL || (root->left==NULL && root->right==NULL))
        {
            return;
        }
        ans.push_back(root->val);
        //if we get left node value then take it
        if(root->left!=NULL)
        {
            leftboundary(root->left, ans);
        }
        //otherwise check for right node values
        else
        {
            leftboundary(root->right, ans);
        }
}

//leaf nodes
void leafnodes(TreeNode *root, vector<int>&ans)
{
        if(root==NULL)
        {
            return;
        }
        //if its a leaf node then only add to vector
        if(root->left==NULL && root->right==NULL)
        {
            ans.push_back(root->val);
        }
        leafnodes(root->left,ans);
        leafnodes(root->right,ans);
}

//right boundary without leaf nodes
void rightboundary(TreeNode* root, stack<int>&st)
{
        //since we are passing root->right we check if its a blank subtree
        //or stop when we reach a leaf node
        if(root==NULL || (root->left==NULL && root->right==NULL))
        {
            return;
        }
        //push values in stack to get reversed order for right subtree
        st.push(root->val);
        //if we get a right node value take it 
        if(root->right!=NULL)
        {
            rightboundary(root->right, st);
        }
        //otherwise check for left node value
        else
        {
            rightboundary(root->left, st);
        }
}

vector<int> boundaryOfBinaryTree(TreeNode* root) 
{
        vector<int>ans;
        stack<int>st;
        //a tree root with no left or right subtree will not be added
        //because it will be added during leafnode() so we dont have double values
        if(!(root->left==NULL && root->right==NULL))
        {
            ans.push_back(root->val);
        }
        leftboundary(root->left,ans);
        leafnodes(root,ans);
        rightboundary(root->right,st);
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
}
