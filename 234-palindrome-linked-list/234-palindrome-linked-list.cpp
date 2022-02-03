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
    
    ListNode* rev(ListNode* head){
        if(head==NULL or head->next==NULL) return head;
        ListNode* newHead = rev(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while(fast!=NULL and fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        slow= rev(slow);
        while(slow){
            if(head->val!=slow->val) return false;
            slow = slow->next;
            head = head->next;
        }
        return true;
    }
};