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
    
    ListNode* reverseLinkedList(ListNode* head,int k,ListNode* prevNode){
        ListNode* iterator = head;
        int cnt = 0;
        while(true){
            cnt++;
            ListNode* temp = iterator->next;
            iterator->next = prevNode;
            if(cnt==k) return iterator;
            prevNode = iterator;
            iterator = temp;
        }
        return NULL;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* tempHead = head;
        int cnt = 0;
        while(tempHead){
            cnt++;
            if(cnt==k) break;
            tempHead = tempHead->next;
        }
        if(cnt!=k) return head;
        ListNode* prevNode = tempHead->next;
        head = reverseLinkedList(head,k,prevNode);
        
        tempHead = head;
        cnt = 0;
        while(tempHead){
            cnt++;
            if(cnt==k) break;
            tempHead = tempHead->next;
        }
        
        tempHead->next = reverseKGroup(tempHead->next,k);
        return head;
    }
};