#include <iostream>
using namespace std;

// Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    /*
        2
       1 3
       
            5
        1       4
              3   6
              
       1
         1
         0
    -1
    */
    
    bool dfs(TreeNode* root, TreeNode* low, TreeNode* high){
        // empty trees are valid
        if(root == nullptr) return true;
        
        // if doesn't have bst property, return false
        if((low != nullptr && root->val <= low->val) || (high != nullptr && root->val >= high->val)){
            return false;
        }
           
        // satisfies property so check left and right subtrees
        // left subtree's max would be root->val since everything to its left is smaller than root
        // right subtree's min would be root->val since everything to its right is bigger than root
        return dfs(root->left, low, root) && dfs(root->right, root, high);
            
    }
    bool isValidBST(TreeNode* root) {
        return dfs(root, nullptr, nullptr);
    }
};