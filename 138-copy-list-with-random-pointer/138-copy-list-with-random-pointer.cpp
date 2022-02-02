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
        Node* ansHead;
        Node* ansTail;
        while(temp){
            if(ansHead==NULL){
                ansHead = temp->next;
                ansTail = temp->next;
            }else{
                ansTail->next = temp->next;
                ansTail = temp->next;
            }
            temp->next = temp->next->next;
            temp = temp->next;
        }
        return ansHead;
    }

};