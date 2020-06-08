/*
    Power of Two

    Given an integer, write a function to determine if it is a power of two.

    Example 1:
    Input: 1
    Output: true 
    Explanation: 20 = 1

    Example 2:
    Input: 16
    Output: true
    Explanation: 24 = 16

    Example 3:
    Input: 218
    Output: false
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        if(n==0)
            return false;
        
        //Log Method
        return ceil(log2(n)) == floor(log2(n));
        
        // 8 /2 -> 4,         4/2 -> 2,          2/2 -> 1
        
        // 12/2 -> 6,         6/2 -> 3, 
        
        //Iterative Method
        
        /*
        while(n != 1)
        {
            if(n%2 != 0)
                return false;
            n = n/2;
        }
        
        return true;*/        
    }
};