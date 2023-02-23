#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
/*
[eat, tea, tan, ate, nat, bat]
// sort each string so sorted string will be key and push original string as value
aet -> eat, tea, ate
ant -> tan, nat
abt -> bat
// push values into vector and return
[[eat, tea, ate], [tan, nat], [bat]]

sorting string -> O(k log k) if k is max length of string
doing this for n number of strings so time complexity = O(n * k log k)
using vector of vector so O(n * k)
*/
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        
        unordered_map<string, vector<string>> m;
        
        for(int i = 0; i < strs.size(); i++){
            string s = strs[i];
            sort(strs[i].begin(), strs[i].end());
            m[strs[i]].push_back(s);
        }
        
        for(auto it : m){
            ans.push_back(it.second);
        }
        
        return ans;
    }
};