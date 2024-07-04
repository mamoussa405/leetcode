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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* ans_head = nullptr;
        ListNode* tail = head;
        int val = 0;

        head = head->next;
        while (head) {
            if (head->val)
                val += head->val;
            else {
                if (!ans_head) {
                    ans_head = new ListNode(val);
                    tail = ans_head;
                }
                else {
                    tail->next = new ListNode(val);
                    tail = tail->next;
                }
                val = 0;
            } 
            head = head->next;
        }
        return ans_head;  
    }
};