#include <iostream>
using namespace std;

// Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

/*
  3 pointer apporach where p1 is initially null (will become tail) and 
  is a reference to previos, p2 is the element you're reversing beginning 
  with head and p3 is the reference to next. O(N) T O(1) S

  p1 = null
  p2 = head

  keep doing this till p2 != null meaning you reached the tail
  p3 = p2 -> next // saving reference 
  p2 -> next = p1; // reversing link to node
  p1 = p2; // move p1 ahead to where p2 was
  p2 = p3; // mode p2 ahead to where p3 was

  O(n) T O(1) S
 */

class Solution {
public:

    ListNode* reverseList(ListNode* head) {

      ListNode* p1 = nullptr;
      ListNode* p2 = head;

      while(p2 != nullptr){
        ListNode* p3;
        p3 = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p3;
      }

      return p1;
    }

};