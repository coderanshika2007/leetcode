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
    int getDecimalValue(ListNode* head) {
        int decimal_value = 0;
        int i = 0;
        ListNode*temp = head;
        while(temp!=nullptr){
            temp = temp->next;
            i = i+1;
        }
        int powers = i-1;
        ListNode*curr = head;
        while(curr!=nullptr){
            decimal_value += curr->val*pow(2,powers);
            curr = curr->next;
            powers = powers-1;
        }
        return decimal_value;
    }
};