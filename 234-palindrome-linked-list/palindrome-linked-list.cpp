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
    bool isPalindrome(ListNode* head) {
        vector<int> original;
        vector<int> reversed;
        ListNode*temp = head;
        ListNode*prev = nullptr;
        ListNode*next = nullptr;
        while(temp!=nullptr){
            original.push_back(temp->val);
            temp = temp->next;
        }
        ListNode*curr = head;
        while(curr!=nullptr){
           next = curr->next;
           curr->next = prev;
           prev = curr;
           curr = curr->next;
           curr = next;
        }
        ListNode* temp2 = prev;
        while (temp2 != nullptr) {
            reversed.push_back(temp2->val);
            temp2 = temp2->next;
        }
        
    return original == reversed;

    }
};