/*
    Largest Divisible Subset

    Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:

    Si % Sj = 0 or Sj % Si = 0.

    If there are multiple solutions, return any subset is fine.

    Example 1:
    Input: [1,2,3]
    Output: [1,2] (of course, [1,3] will also be ok)

    Example 2:
    Input: [1,2,4,8]
    Output: [1,2,4,8]
*/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
            
        int n = nums.size();
        if(n==0)
            return {};
        
        
        int len[n] , index[n];
        memset(len, 1, sizeof(len));
        memset(index, 0, sizeof(index));
        int maxLen = 1;
        int pointer = 0;
        
        sort(nums.begin(), nums.end());
        
        for(int i=1; i<n; i++)
        {
            index[i] = i;
            for(int j=0; j<i; j++)
                if(nums[i] % nums[j] == 0 && len[j] + 1 > len[i])
                {
                    len[i]  = len[j] + 1;
                    index[i] = j;
                }
                    
            if(len[i] > maxLen)
            {
                maxLen = len[i];
                pointer = i;
            }
        }
        
        vector<int> res;
        res.push_back(nums[pointer]);
        while(pointer != index[pointer])
        {
            pointer = index[pointer];
            res.push_back(nums[pointer]);
        }
        return res;    
    }
    
};