#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
/*
[2, 0, 2, 1, 1, 0]
3 pointers where p0 is for 0 boundary, p1 to iterate and p2 for 2 boundary
[0, 0 | 1, 1, | 2, 2]
stop when p1 crosses p2. p0 and p1 at beginning, p2 at end
when p1 = 0, swap with p0 to put in right spot for 0s, increment both
when p1 = 2, swap with p2 to put in right spot for 2s, decrement only p2
when p1 = 1, increment only p1
*/
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int p0 = 0;
        int p1 = 0;
        int p2 = n - 1;
        
        while(p1 <= p2){
            if(nums[p1] == 0){
                swap(nums[p1], nums[p0]);
                p1++;
                p0++;
            }
            else if(nums[p1] == 2){
                swap(nums[p1], nums[p2]);
                p2--;
            }
            else {
                p1++;
            }
        }
    }
};