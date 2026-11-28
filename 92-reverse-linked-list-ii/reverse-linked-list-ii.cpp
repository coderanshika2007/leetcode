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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == nullptr || left == right){
            return head;
        }
        ListNode*temp = head;
        int count = 1;
        ListNode*pos = nullptr;
        ListNode*posi = nullptr;
        while(temp!=nullptr){
            if(count ==  left){
                pos =  temp;
            }
            if(count == right){
                posi = temp;
            }
            temp = temp->next;
            count++;
        }
        ListNode*prevNode;
        if(left>1){
            temp = head;
            while(temp->next!=pos){
                temp = temp->next;
            }
            prevNode = temp;
        }
        ListNode*prev = posi->next;
        ListNode*curr =  pos;
        int steps = right-left+1;
        while(steps--){
            ListNode*next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        if(prevNode != nullptr){
            prevNode->next = posi;
        }else{
            head = posi;
        }
        return head;
    }
};