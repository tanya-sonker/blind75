#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /*
    column becomes row 
    but could transpose (rotate around diagonal) first and then reverse 
    
    1 2 3       1 4 7       7 4 1       
    4 5 6  ->   2 5 8  ->   8 5 2
    7 8 9       3 6 9       9 6 3
    
    in coordinates for transpose 
    10 -> 01
    20 -> 02
    21 -> 12
    30 -> 03 
    31 -> 13
    32 -> 23
    
    in coordinates for reflect
    03 -> 00 
    02 -> 01 
    01 -> 02
    00 -> 03
    13 -> 10
    12 -> 11
    11 -> 12
    10 -> 13

    O(n^2) T O(1) S
    */
    
    // rotating around diagonal     
    void transpose(vector<vector<int>>& matrix) {
        
        int n = matrix.size();
        
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int temp = matrix[j][i];
                matrix[j][i] = matrix[i][j];
                matrix[i][j] = temp;
            }
        }
    }
    
    // 2 pointer approach, meeting halfway n/2 so same distance
    void reflect(vector<vector<int>>& matrix) {
        
        int n = matrix.size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n / 2; j++){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][n - 1 - j];
                matrix[i][n - 1 - j] = temp;
            }
        }
    }
    
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        reflect(matrix);
    }
};