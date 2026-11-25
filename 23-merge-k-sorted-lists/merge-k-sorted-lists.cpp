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
    ListNode* mergetwolists(ListNode*a, ListNode*b){
        ListNode dummy(-1);
        ListNode*tail = &dummy;
        while(a!=nullptr && b!=nullptr){
            if(a->val <= b->val){
                tail->next = a;
                a = a->next;
            }else{
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }
        if(a!=nullptr){
            tail->next = a;
        }else{
            tail->next = b;
        }
        return dummy.next;
    }
    ListNode* mergerange(vector<ListNode*>&lists, int left, int right){
        if(left>right){
            return nullptr;
        }
        if(left  == right){
            return lists[left];
        }
        int mid = left + (right-left)/2;
        ListNode* forleft = mergerange(lists, left, mid);
        ListNode* forright = mergerange(lists, mid+1, right);
        return mergetwolists(forleft, forright); 
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()){
            return nullptr;
        }
        return mergerange(lists, 0, lists.size()-1);
    }
};