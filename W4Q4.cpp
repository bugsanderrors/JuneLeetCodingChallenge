/*
    Find the Duplicate Number

    Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist.
    Assume that there is only one duplicate number, find the duplicate one.

    Example 1:
    Input: [1,3,4,2,2]
    Output: 2

    Example 2:
    Input: [3,1,3,4,2]
    Output: 3

    Note:
        * You must not modify the array (assume the array is read only).
        * You must use only constant, O(1) extra space.
        * Your runtime complexity should be less than O(n^2).
        * There is only one duplicate number in the array, but it could be repeated more than once.
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int s = nums[0], f = nums[nums[0]];
        
        while(s != f)
        {
            s = nums[s];
            f = nums[nums[f]];
        }
        
        s = 0;
        
        while(s != f)
        {
            s = nums[s];
            f = nums[f];
        }
        
        return s; 
    }
};