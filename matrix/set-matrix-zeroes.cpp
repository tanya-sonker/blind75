#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
/*
1 1 1
1 0 1 -> (1, 1) -> (1, 0) (1, 1) (1, 2) (0, 1) (1, 1) (2, 1) -> fix i and j iterate over lengths
1 1 1 

0 1 2 0    -> (0, 0) -> (0, 1) (0, 2) (0, 3) (0, 0) (1, 0) (2, 0)
3 4 5 2 -|
1 3 1 5    -> (0, 3) -> (0, 0) (0, 1) (0, 2) (0, 3) (1, 3) (2, 3)

O(M x N) T where M is # of rows and N is # of columns
and O(M + N) S since using sets, no additional space since changing matrix in-place
*/
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        
        set<int> rows;
        set<int> cols;
        
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(matrix[i][j] == 0){
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }
        
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(rows.find(i) != rows.end() || cols.find(j) != cols.end()){
                    matrix[i][j] = 0;
                }
            }
        }
                
    }
};