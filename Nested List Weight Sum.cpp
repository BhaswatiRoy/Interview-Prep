Problem: https://leetcode.com/problems/nested-list-weight-sum/description

/*
Approach:
Consider it as a tree with levels so we can do a BFS

nestedList = [[1,1],2,[1,1]]
result = 0, level = 1, q = [[[1,1], 2, [1,1]]]
q.front() = [[1,1], 2, [1,1]]
            [1,1] is a list -> push to q
            2 is integer with level = 1, so result += (2*1)
            [1,1] is a list -> push to q
q.front() = [1,1]
            1 & 1 are integers with level = 2, so result += (1+1)*2
            [1,1]
            1 & 1 are integers with level = 2, so result += (1+1)*2
result = 2 + 4 + 4 = 10

nestedList = [1,[4,[6]]]
result = 0, level = 2, q = [1,[4,[6]]]
q.front() = [1,[4,[6]]]
            1 is integer with level = 1, so result += (1*1)
            [4,[6]] is a list -> push to q
q.front() = [4,[6]]
            4 is integer with level = 2, so result += (4*2)
            [6] is a list -> push to q
q.front() = [6] 
            6 is integer with level = 3, so result += (6*3)
result = 1 + 8 + 18 = 27

TC: O(n) -> iterating through n elements 
SC: O(m) -> m = max number of nodes in a level stored in queue 
*/

int depthSum(vector<NestedInteger>& nestedList) 
{
        //NestedInteger is treated as a tree
        queue<vector<NestedInteger>>q;
        //pushing the root of the tree
        q.push(nestedList);
        int result=0, level=1;
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                vector<NestedInteger>p=q.front();
                q.pop();
                for(int i=0;i<p.size();i++)
                {
                    //if its single integer we reached depth 1
                    //so we can add it to our result
                    if(p[i].isInteger())
                    {
                        //gets the integer value if its integer
                        int value=p[i].getInteger();
                        result+=(value*level);
                    }
                    else
                    {
                        //returns nested list if not integer
                        q.push(p[i].getList());
                    }
                }
            }
            level++;
        }
        return result;
}
