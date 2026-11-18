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
    ListNode* partition(ListNode* head, int x) {
        ListNode*lesshead = new ListNode(0);
       
        ListNode*highhead = new ListNode(0);
        ListNode*less = lesshead;
       
        ListNode*high = highhead;
        ListNode*curr = head;
        
        while(curr!=nullptr){
            ListNode*nextnode  = curr->next;
            curr->next =  nullptr;
            if(curr->val < x){
                less->next = curr;
                less = less->next;
            }
            else{
                high->next = curr;
                high = high->next;
            }
            curr = nextnode;
        }
       
        less->next = highhead->next;
        ListNode*newhead  = lesshead->next;

        delete lesshead;
        delete highhead;
        
        return newhead;
    }
};