class Solution {
public:
    int findMin(vector<int> &nums) {
        int lo = 0;
        int hi = nums.size()-1;

        while(lo < hi){
            int mid = lo + (hi - lo)/2;

            if(nums[mid] > nums[hi]){
                //min must be in the RHS
                lo = mid+1;
            } else{ //nums[mid] <= nums[lo]
                hi = mid; //min must be in the LHS incl. mid
            }
        }
        return nums[lo];
    }
};
