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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode*tempA = list1;
        ListNode*tempB = list2;
        if(tempA == nullptr){
            return tempB;
        }
        if(tempB == nullptr){
            return tempA;
        }
        ListNode*head = nullptr;
        if(tempA->val <= tempB->val){
            head = tempA;
            tempA = tempA->next;
        }else{
            head = tempB;
            tempB = tempB->next;
        }
        ListNode*tail = head;
        while(tempA != nullptr && tempB != nullptr){
            
            if(tempA->val<=tempB->val){
                tail->next = tempA;
                tempA = tempA->next;
            }else{
               tail->next = tempB;
               tempB = tempB->next;
            }
            tail = tail->next;
        }
        if(tempA != nullptr){
            tail->next = tempA;
        }else{
            tail->next = tempB;
        }
        return head;
    }
};