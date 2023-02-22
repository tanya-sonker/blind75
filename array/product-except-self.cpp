#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
/*
O(n) ST
[1, 2, 3, 4] 
left [1, 1, 2, 6]
x
right [24, 12, 4, 1]
=
result [24, 12, 8, 6]

O(n) T O(1) S
[1, 2, 3, 4]
left = 1
result [1, 1, 2, 6]
right = 1
j: 3 [4], right: 4, j-1: 2 [2] -> 8
j: 2 [3], right: 12, j-1: 1 [1] -> 12
j: 1 [2], right: 24, j-1: 0 [1] -> 24 
result [24, 12, 8, 6]
*/
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> product;

        int n = nums.size();
        int leftSum = 1;
        product.push_back(leftSum);

        for(int i = 1; i < n; i++){
            leftSum *= nums[i - 1];
            product.push_back(leftSum);
        }
        
        int rightSum = 1;
        for(int j = n - 1; j >= 1; j--){
            rightSum *= nums[j];
            product[j - 1] *= rightSum;
        }

        return product;
    }
};