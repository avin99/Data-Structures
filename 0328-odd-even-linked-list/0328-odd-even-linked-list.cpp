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
    ListNode* oddEvenList(ListNode* head) {
        if( head == NULL) return head;
        ListNode *cur = head, *sec, *prev;
        prev = cur -> next;
        while(cur && cur -> next){
            sec = cur -> next;
            cur -> next = cur -> next -> next;
            if(sec -> next)
            sec -> next = sec -> next -> next;
            if(cur -> next)
            cur = cur -> next;
        }
        cur -> next = prev;
        return head;
    }
};