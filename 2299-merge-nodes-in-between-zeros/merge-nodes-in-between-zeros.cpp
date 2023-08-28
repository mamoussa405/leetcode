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
       ListNode* ans = nullptr, *tmp = nullptr;
       ListNode* tail = nullptr;
       int sum;

       tmp = head->next;
       sum = 0;
       while (head)
       {
           while (tmp->val)
           {
               sum += tmp->val;
               tmp = tmp->next;
           }
           if (ans == nullptr)
           {
            ans = new ListNode(sum);
            tail = ans;
           }
            else
            {
                tail->next = new ListNode(sum);
                tail = tail->next;
            }
           head = tmp;
           if (head->next == nullptr) break;
           tmp = tmp->next;
           sum = 0;
       }
       return ans;
    }
};