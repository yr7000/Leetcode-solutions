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
    
    ListNode* reverseLinkedList(ListNode* iterator,ListNode* last){
        ListNode* prevNode = last;
        while(iterator!=last){
            ListNode* temp = iterator->next;
            iterator->next = prevNode;
            prevNode = iterator;
            iterator = temp;
        }
        return prevNode;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* tempHead = head;
        for(int i=0;i<k;i++){
            if(tempHead==NULL) return head;
            tempHead = tempHead->next;
        }
        ListNode* newHead = reverseLinkedList(head,tempHead);
        head->next = reverseKGroup(head->next,k);
        return newHead;
    }
};