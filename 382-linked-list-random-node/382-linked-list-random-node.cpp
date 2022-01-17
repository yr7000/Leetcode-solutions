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
    
    ListNode *tempHeadPointer;
    int length = 0;
    
    Solution(ListNode* head) {
        tempHeadPointer = head;
        while(head){
            length++;
            head = head->next;
        }
    }
    
    int getRandom() {
        int ind = rand()%length;
        ListNode* temp2 = tempHeadPointer;
        for(int i=0;i<ind;i++){
            temp2 = temp2->next;
        }
        return temp2->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */