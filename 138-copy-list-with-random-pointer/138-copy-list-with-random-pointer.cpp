/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
   
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        Node* temp = head;
        // step 1: adding copies just next to the original nodes.
        while(temp!=NULL){
            Node* copy = new Node(temp->val);
            copy->next = temp->next;
            temp->next = copy;
            temp = temp->next->next;    
        }
        // step 2: adding random pointers to copy nodes
        temp = head;
        while(temp!=NULL){
            if(temp->next and temp->random){
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }
        
        // step 3: removing the unwanted links.
        temp = head;
        Node* resultHead = head->next;
        while(temp and temp->next){
            Node* originalNext = temp->next->next;
            if(originalNext) temp->next->next = originalNext->next;
            temp->next = originalNext;
            temp = temp->next;
        }
        return resultHead;
    }

};