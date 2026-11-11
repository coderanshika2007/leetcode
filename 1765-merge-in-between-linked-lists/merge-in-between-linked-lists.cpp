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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode*temp1 =  list1;
        ListNode*temp2 = list2;
        ListNode*temp = temp1;
        ListNode*hash = temp1;
        ListNode*hash1 = hash;
        int count = 0;
        int access = 0;
        while(count != (a-1)){
            temp = temp->next;
            count++;
        }
        while(access != (b+1)){
            hash = hash->next;
            access++;
        }
        temp1 = temp;
        hash1 = hash;

        temp1->next = temp2;
        while(temp2->next!=nullptr){
            temp2 = temp2->next;
        }
        temp2->next = hash1;

return list1;
    }
};