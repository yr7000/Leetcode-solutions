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
    ListNode *findIntersection(ListNode *head){
        ListNode *slow = head, *fast = head;
        do{
            if(fast==NULL or fast->next==NULL) return NULL;
            slow = slow->next;
            fast = fast->next->next;
        }while(slow!=fast);
        
        fast = head;
        while(slow!=fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *tempHead = headA;
        while(tempHead->next) tempHead = tempHead->next;
        tempHead->next = headB;
        ListNode* result = findIntersection(headA);
        tempHead->next  = NULL;
        return result;
    }
};