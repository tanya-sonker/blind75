#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
/*
[1, 2, 3] , 4 => [0, 2]
[-1, -2, 3], -3 => [0, 1]
[4, 6, 7], 13 => [1, 2] 
[3, 2, 4], 6 => [1, 2] and not [0, 0]
    
brute force: O(n^2); 
difference helped get it down to O(n) time and space complexity
*/
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> m;
        vector<int> result;
        
        for(int i = 0; i < n; i++){
            int difference = target - nums[i]; 
            // find key and push value aka index if found
            if(m.find(difference) != m.end()){
                result.push_back(m[difference]);
                result.push_back(i);
            }
            // map array element to index 
            m[nums[i]] = i;
        }
        return result;
    }
};