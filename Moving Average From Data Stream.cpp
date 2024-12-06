Problem: https://leetcode.com/problems/moving-average-from-data-stream/description

/*
Approach:
1. Keep a queue
2. Save sum value and push current element to queue
3. If queue.size() exceeds the max size then remove the least recently used
4. Return avg = sum/count in the end

TC: O(1) -> add/remove operation of queue
SC: O(size) -> max size of queue needed
*/

queue<double>q;
int maxsize;
double sum=0;
MovingAverage(int size) 
{
        //keep track of size of queue
        maxsize=size;
}
    
double next(int val) 
{
        sum+=val;
        q.push(val);
        //if queue size exceeds then remove the least recently used
        if(q.size()>maxsize)
        {
            sum-=q.front();
            q.pop();
        }
        int count=q.size();
        //return average in end
        return (sum/count);
}
