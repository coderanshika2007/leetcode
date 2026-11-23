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
        if(head==NULL){
            return head;
        }
        Node* curr = head;
        while(curr!=NULL){
            Node* newNode = new Node(curr->val);
            newNode->next = curr->next;
            curr->next = newNode;
            curr = newNode->next;
        }
        curr = head;
        while(curr != nullptr){
            if(curr->random != nullptr){
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }
        curr = head;
        Node* copyhead = head->next;
        Node* copy = copyhead;
        while(copy->next != nullptr){
            curr->next = curr->next->next;
            copy->next = copy->next->next;
            curr = curr->next;
            copy = copy->next;
        }
        curr->next = nullptr;
        copy->next = nullptr;
        return copyhead;
    }
};