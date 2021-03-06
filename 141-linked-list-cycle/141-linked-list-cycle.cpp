/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL) return false;
        ListNode* slow = head, *fast = head;
        do{
            slow = slow->next;
            if(fast->next==NULL or fast->next->next==NULL) return false;
            fast = fast->next->next;
        }while(slow!=fast);
        return true;
    }
};