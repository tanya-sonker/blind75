#include <iostream>
#include <vector>
using namespace std;

// O(m x n) ST
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int> spiral;
        
        // int r = matrix.size();
        // int c = matrix[0].size();
            
        int left = 0, right = matrix[0].size();
        int top = 0, bottom = matrix.size();
        
        while (left < right && top < bottom) {
            // get every value in top row
            for(int i = left; i < right; i++){
                spiral.push_back(matrix[top][i]);
            }
            top++;
            
            // get every value in right column
            for(int i = top; i < bottom; i++){
                spiral.push_back(matrix[i][right - 1]); // right is out of bounds
            }
            right--;
            
            // only 1 row or column
            if(!(left < right && top < bottom)){
                break;
            }
            
            // get every value in bottom row
            for(int i = right - 1; i >= left; i--){
                spiral.push_back(matrix[bottom - 1][i]); // bottom is out of bounds
            }
            bottom--;
            
            // for every value in left column
            for(int i = bottom - 1; i >= top; i--){
                spiral.push_back(matrix[i][left]);
            }
            left++;
            
        }
            
        return spiral;    
    }
};