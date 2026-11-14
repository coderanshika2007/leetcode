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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode*dummy = new ListNode(-1);
        dummy->next = head;
        ListNode*curr = head;
        ListNode*prev = dummy;
      
        while(curr!=nullptr && curr->next != nullptr){
            ListNode*temp = curr;
            int count = 1;
            while(temp->next!=nullptr && temp->val == temp->next->val){
                count++;
                temp = temp->next;
            }
            if(count>=2){
                ListNode*after = temp->next;
                prev->next = temp->next;
                while(curr != after){
                    ListNode*delnode = curr;
                    curr = curr->next;
                    delete delnode;
                }
                
            }else{
                prev = curr;
                curr = curr->next;
            }
        }
        ListNode*ans = dummy->next;
        delete dummy;
        return ans;
    }
};