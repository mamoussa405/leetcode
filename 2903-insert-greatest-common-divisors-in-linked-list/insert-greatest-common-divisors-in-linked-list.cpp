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
    void insertNode(ListNode* curr, ListNode *newNode)
    {
        ListNode* tmp = curr->next;
        curr->next = newNode;
        newNode->next = tmp;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* tmp = head;       

        while (tmp)
        {
            if (tmp->next)
            {
                int gcd = __gcd(tmp->val, tmp->next->val);
                insertNode(tmp, new ListNode(gcd));
                tmp = tmp->next->next;
            }
            else
                tmp = tmp->next;
        }
        return head;
    }
};