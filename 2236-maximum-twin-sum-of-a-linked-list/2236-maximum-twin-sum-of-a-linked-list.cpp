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
    int pairSum(ListNode* head) {
        int size = 0;
        ListNode *slow = head, *fast = head;
        while(fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        ListNode *firstHalf, *secondHalf;
        firstHalf = head;
        ListNode *cur = slow, *prev = NULL, *nxt;
        while(cur != NULL){
            nxt = cur -> next;
            cur -> next = prev;
            prev = cur;
            cur = nxt;
        }
        secondHalf = prev;
        int ans = 0;
        while(secondHalf != NULL){
            ans = max(ans, firstHalf -> val + secondHalf -> val);
            secondHalf = secondHalf -> next;
            firstHalf = firstHalf -> next;
        }
        return ans;
    }
};