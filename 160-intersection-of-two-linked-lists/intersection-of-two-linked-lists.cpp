/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = 0;
        int len2 = 0;
        ListNode*temp1 = headA;
        ListNode*temp2 = headB;
        while(temp1!=nullptr){
            len1++;
            temp1 = temp1->next;
        }
        while(temp2!=nullptr){
            len2++;
            temp2 = temp2->next;
        }
        if(len1>len2){
            while(len1>len2){
                headA = headA->next;
                len1--;
            }
        }else if(len2>len1){
            while(len2>len1){
                headB = headB->next;
                len2--;
            }
        }
        temp1 = headA;
        temp2 = headB;
        while(temp1 != temp2){
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return temp1;
    }
};