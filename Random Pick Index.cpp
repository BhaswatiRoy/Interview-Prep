Problem: https://leetcode.com/problems/random-pick-index/description/

/*
Approach 1: Hashing
1. Store all index of each element in a map
2. Then for a target value return a random index using rand() function
TC: O(n) -> iterating through all n elements
SC: O(n) -> storing all n elements

Approach 2: Reservoir Sampling
1. keep 2 variables "count" to store the count of occurrences of target & "result"
2. Iterate through the entire array and if we find the "target" we check
3. If result = -1 so we never found target before hence result = current index and count++
4. But if result != -1, we found the target before, hence count++ again to count this occurence
5. We check if rand()%count == 0, if yes then we update result = i 
6. This check ensures equal picking probability for the target value

rand() % count == 0 ensures that as more occurrences of the target are found, 
the probability of selecting the current occurrence decreases, maintaining equal chances for all occurrences.

For each subsequent occurrence of target, we pick the current index i with a probability of 1 / count. 
This is achieved by checking rand() % count == 0, where rand() generates a random number between 0 and RAND_MAX.
*/

//Approach 1: Hashing
unordered_map<int,vector<int>>mp
Solution(vector<int>& nums) 
{
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            mp[nums[i]].push_back(i);
        }
}
    
int pick(int target) 
{
        int size=mp[target].size();
        int randomindex=rand()%size;
        return mp[target][randomindex];
}

//Approach 2: Reservoir Sampling
vector<int>arr;
Solution(vector<int>& nums) 
{
        arr=nums;
}
    
int pick(int target) 
{
        //stores count of target
        int count=0;
        int result=-1;
        for(int i=0;i<arr.size();i++)
        {
            //if target found then proceed
            if(arr[i]==target)
            {
                //Reservoir Sampling: Pick the current index with probability = 1/count
                //if the result is not found then we do this to avoid zero division error
                //because for this count will be 0
                if(result==-1)
                {
                    result=i;
                    count++;
                }
                else
                {
                    count++;
                    if(rand()%count==0)
                    {
                        result=i;
                    }
                }
            }
        }
        if(count==0)
        {
            return -1;
        }
        return result;
}
