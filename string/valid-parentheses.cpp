#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    /*
    stack
    3 types of characters () {} []
    1) () [] -> ( ) [ ] -> ] has a [ -> ( has a )
    2) ({}) -> ( { and compare } )
    3) [, [[
    4) ], ])
    5) )[
    
    O(n) time and O(n) space
    */
    bool isValid(string s) {
        stack<char> paren;
        
        for(int i = 0; i < s.length(); i++){
            
            char ch = s[i];
            
            if(ch == ')'){
                if(paren.empty()){
                    paren.push('#');
                }
                if(paren.top() == '('){
                    paren.pop();
                }
                else {
                    return false;
                }
            }
            
            if(ch == '}'){
                if(paren.empty()){
                    paren.push('#');
                }
                if(paren.top() == '{'){
                    paren.pop();
                }
                else {
                    return false;
                }
            }
            
            if(ch == ']'){
                if(paren.empty()){
                    paren.push('#');
                }
                if(paren.top() == '['){
                    paren.pop();
                }
                else {
                    return false;
                }
            }
                         
            if(ch == '(' || ch == '{' || ch == '['){
                paren.push(ch);
            }
        }
        
        return paren.empty();
    }
};