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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr){
            return head;
        }
        ListNode*curr = head;
        ListNode*newhead = nullptr;
        ListNode*tail = nullptr;
        while(curr!=nullptr){
            ListNode*grouphead = curr;
            ListNode*prev = nullptr;
            ListNode*nextnode = nullptr;
            int count = 0;
            ListNode*temp = curr;
            while(temp!=nullptr && count<k){
                temp = temp->next;
                count++;
            }
            if(count<k){
                if(tail!=nullptr){
                    tail->next = curr;
                }
                break;
            }
            count = 0;
            
            do{
                nextnode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextnode;
                count++;
            }while(curr != nullptr && count<k);

            if(newhead == nullptr){
                newhead = prev;
            }
            if(tail != nullptr){
                tail->next = prev;
            }
            tail = grouphead;
        }
        return newhead;
    }
};