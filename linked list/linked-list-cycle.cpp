#include <iostream>
using namespace std;

// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };

class Solution {
public:
    bool hasCycle(ListNode *head) {
        // O(n) T O(1) S
        ListNode* slow = head;
        ListNode* fast = head;
        // if even/odd # of nodes, no cycle is when null
         while(fast != nullptr && fast->next != nullptr){
             slow = slow->next;
             fast = fast->next->next;
             // later otherwise if only 1 node will say true
             if(slow == fast){
                 return true;
             }
         }
        return false;
    }
/*
    bool hasCycle(ListNode *head) {
        // O(n) ST
        // but what happens when there are duplicates?
        set<int> s;
        
         while(head != nullptr){
             if(s.find(head->val) != s.end()){
                 return true;
             }
             s.insert(head->val);
             head = head->next;
         }
        return false;
    }
*/
};