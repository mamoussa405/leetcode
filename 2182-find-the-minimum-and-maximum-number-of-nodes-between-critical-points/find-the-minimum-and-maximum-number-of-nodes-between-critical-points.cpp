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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev = head;
        ListNode* curr = head->next;
        int min_dis = INT_MAX, max_dis = 0;
        int dis = -1;

        while (curr && curr->next) {
            if ((curr->val > prev->val && curr->val > curr->next->val) || 
            (curr->val < prev->val && curr->val < curr->next->val)) {
                if (dis == -1)
                    dis = 0;
                else {
                    min_dis = min(min_dis, dis);
                    max_dis += dis;
                    dis = 0;
                }
            }
            prev = curr;
            curr = curr->next;
            dis += (dis != -1);
        }
        if (max_dis)
            return {min_dis, max_dis};
        return {-1, -1};
    }
};