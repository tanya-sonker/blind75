#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
/*
s = anagram
smap = a -> 2, g -> 1, m -> 1, n -> 1, r -> 1
t = nagaram 
tmap = a -> 2, g -> 1, m -> 1, n -> 1, r -> 1

s = rat
smap = a -> 1, r -> 1, t -> 1
t = car
tmap = a -> 1, c -> 1, r -> 1

O(n) T O(1) S
*/
    bool isAnagram(string s, string t) {

        if(s.length() != t.length()){
            return false;
        }

        int arr[26] = {0};

        for(int i = 0; i < s.length(); i++){
            char ch = s[i] - 'a';
            arr[ch]++;
        }

        for(int i = 0; i < t.length(); i++){
            char ch = t[i] - 'a';
            arr[ch]--;
            // compare counts, return false if not same
            if(arr[ch] < 0){
                return false;
            }
        }
        return true;
    }

/*
O(n) TS
O(n) T O(n) S
    bool isAnagram(string s, string t) {

        if(s.length() != t.length()){
            return false;
        }

        map<char, int> smap;
        map<char, int> tmap;

        for(int i = 0; i < s.length(); i++){
            smap[s[i]]++;
        }

        for(int i = 0; i < t.length(); i++){
            tmap[t[i]]++;
        }

        for(int i = 0; i < s.length(); i++){
            // compare counts, return false if not same
            if(smap[s[i]] != tmap[s[i]]){
                return false;
            }
        }
        return true;
    }

    bool isAnagram(string s, string t) {

        if(s.length() != t.length()){
            return false;
        }

        map<char, int> m;

        for(int i = 0; i < s.length(); i++){
            m[s[i]]++;
            m[t[i]]--;
        }

        for(auto it : m){
            // compare counts, return false if not same
            if(it.second != 0){
                return false;
            }
        }
        return true;
    }
*/
};