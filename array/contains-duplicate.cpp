#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
/*
[1, 2, 3, 1] -> true
[1, 2, 3, 4] -> false
[1, 1, 1, 3, 3, 4, 3, 2] -> true 
O(n) ST
*/
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            if(s.find(nums[i]) != s.end()){
                return true;
            }
            s.insert(nums[i]);
        }
        return false;
    }
};