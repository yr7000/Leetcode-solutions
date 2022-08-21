/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {  
      if(head == NULL) return NULL;
      head->next = removeZeroSumSublists(head->next);
      int sum = 0;
      ListNode* temp = head;
      while(temp){
        sum += temp->val;
        temp = temp->next;
        if(sum == 0) return temp;
      }
      return head;
    }
};