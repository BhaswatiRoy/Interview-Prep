Problem:

/*
     4         
   /   \
 9      0
/ \
5  1
currsum = (currsum*10) + root->val
currsum = 0
currsum = 0*10 + 4 = 4
currsum = 4*10 + 9 = 49
currsum = 49*10 + 5 = 495

Approach: 
1. Use DFS traversal and go through each path
2. generate the numeric value of that path 
3. store all numerical path values into a vector and find sum in the end

TC: O(n) -> simple DFS traversal
SC: O(1) -> no extra space used
*/

//currsum is made locally not globally so each recursive path has its own currsum
//otherwise pass by reference will store last call values making currsum quite higher
//totalsum is passed globally because we need to store its last call value
void dfs(int currsum, int &totalsum, TreeNode *root)
{
        if(root==NULL)
        {
            return;
        }
        //math equation to find sum of a path
        currsum = (currsum*10) + root->val;
        //if leaf found then store currsum to a vector
        if(root->left==NULL && root->right==NULL)
        {
            totalsum+=currsum;
        }
        dfs(currsum,totalsum,root->left);
        dfs(currsum,totalsum,root->right);
}

int sumNumbers(TreeNode* root) 
{
        int currsum=0, totalsum=0;
        dfs(currsum,totalsum,root);
        return totalsum;
}
