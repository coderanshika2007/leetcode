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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*temp = head;
        int length = 0;
        while(temp!=nullptr){
            length++;
            temp = temp->next;
        }
        int target = length - n + 1;
        if(target == 1){
            ListNode*delnode = head;
            head = head->next;
            delete delnode;
            return head;
        }
        temp = head;
        for(int i=1; i<target-1; i++){
            temp = temp->next;
        }
        if(temp!=nullptr){
                ListNode*delnode = temp->next;
                temp->next = temp->next->next;
                delete delnode;
        }
        return head;
    }
};