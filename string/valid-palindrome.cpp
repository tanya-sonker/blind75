#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    /*
    2 pointer approach
    race a car -> raceacar (8) i < j
    i -> r, a, c, e 
    j -> r, a, c, a
    
    dabc cba d (10) -> dabccbad (8) i < j
    i -> d, a, b, c
    j -> d, a, b, c
    
    abccba (6) i < j
    i -> a, b, c
    j -> a, b, c
    
    abcdcba (7) i, j meet
    i -> a, b, c, d
    j -> a, b, c, d 
    
    
    "A man, a plan, a canal: Panama" -> amanaplanacanalpanama
    i -> a m a n a p l a n a c
    j -> a m a n a p l a n a c
    */

    bool isPalindrome(string s) {

        for (int i = 0, j = s.size() - 1; i <= j; i++, j--) {
            // multiple whitespaces get ignored
            while (i < j && !isalnum(s[i])){
                i++;
            }
            while (i < j && !isalnum(s[j])){
                j--;
            }

            if (tolower(s[i]) != tolower(s[j])){
                return false;
            }
        }

    return true;
  }
};