Problem: https://leetcode.com/problems/closest-binary-search-tree-value/description

/*
1. Traverse through the binary search tree using DFS
2. calculate the difference between current node & target value
3. if difference is smaller then store the current node value
4. if the difference is same but the current node value is smaller than store node then store the current node value 
(If there are multiple answers, print the smallest)

TC: O(n) -> worst case of a skewed tree
SC: O(1) -> no extra space used
*/

void search(TreeNode* root, double target, double &diff, int &ans)
{
        if(root==NULL)
        {
            return;
        }
        //find difference between current node & target
        double currdiff=abs(target-root->val);
        //if we find a lesser difference then store this node
        //if its equal difference but node value is smaller than already stored node
        if(currdiff<diff || (currdiff==diff && root->val<ans))
        {
            diff=currdiff;
            ans=root->val;
        }
        if(target<root->val)
        {
            search(root->left,target,diff,ans);
        }
        else
        {
            search(root->right,target,diff,ans);
        }
}

int closestValue(TreeNode* root, double target) 
{
        double diff=INT_MAX;
        int ans=root->val;
        search(root,target,diff,ans);
        return ans;
}
