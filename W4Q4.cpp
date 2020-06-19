/*
    H-Index II

    Given an array of citations sorted in ascending order (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.

    According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."

    Example:
    Input: citations = [0,1,3,5,6]
    Output: 3 
    Explanation: [0,1,3,5,6] means the researcher has 5 papers in total and each of them had 
                received 0, 1, 3, 5, 6 citations respectively. 
                Since the researcher has 3 papers with at least 3 citations each and the remaining 
                two with no more than 3 citations each, her h-index is 3.
    Note:

    If there are several possible values for h, the maximum one is taken as the h-index.

    Follow up:
        * This is a follow up problem to H-Index, where citations is now guaranteed to be sorted in ascending order.
        * Could you solve it in logarithmic time complexity?
*/


class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        int n = citations.size();
        if(n == 1)
            return citations[0] != 0;
        int h_index ;
        
        int l=0, r = n-1;
        while(l<=r)
        {
            int mid = l + (r-l) / 2;
            
            int h = citations[mid];
            
            if(h == n - mid)
                return n-mid;
            else if(h > n - mid)
                r = mid-1;
            else
                l = mid+1;       
        }
        return n-l;
    }
};