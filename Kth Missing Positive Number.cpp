Problem:

/*
Approach:
1. Find all missing numbers and store them in a vector
2. Traverse through the entire array and check which one is missing
3. Store the missing numbers
4. In last we check till k after last numbers because what is no missing numbers are in array so need to check after end of array

TC: O(n+k) -> traversing entire array then again k times
SC: O(n) -> vector storing missing values
*/

int findKthPositive(vector<int>& arr, int k) 
{
        int n=arr.size(),last=1;
        vector<int>missing;
        //if there are missing numbers in between then this loop helps
        //2 3 4 7 -> helps to find missing numbers within this
        for(int i=0;i<n;i++)
        {
            while(last<arr[i])
            {
                missing.push_back(last);
                last++;
            }
            last=arr[i]+1;
        }
        //if there are no missing numbers in between then this loop helps
        //1 2 3 4 -> helps to calculate numbers after end 
        for(int j=0;j<k;j++)
        {
            missing.push_back(last);
            last++;
        }
        return missing[k-1];
}
