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
    
    int getLen(ListNode* head){
        if(head==NULL) return 0;
        return 1+getLen(head->next);
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int l1Len = getLen(l1);
        int l2Len = getLen(l2);
        if(l1Len<l2Len) return addTwoNumbers(l2,l1);
        ListNode* l1Ptr = l1, *l2Ptr = l2;
        int carry = 0;
        ListNode* last;
        while(l1Ptr){
            int value = l1Ptr->val + (l2Ptr==NULL?0:l2Ptr->val) + carry;
            l1Ptr->val = value%10;
            carry = value/10;
            last = l1Ptr;
            l1Ptr = l1Ptr->next;
            if(l2Ptr) l2Ptr = l2Ptr->next;
        }
        if(carry){
            ListNode* newNode = new ListNode(carry);
            last->next = newNode;
        }
        return l1;
    }
};