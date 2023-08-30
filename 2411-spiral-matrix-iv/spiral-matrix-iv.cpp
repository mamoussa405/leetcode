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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
       vector<vector<int>> ans(m, vector<int>(n, -2));
       string direction = "right";
       int x = 0;
       int y = 0;
       int cells = m * n;

       while (cells--)
       {
            ans[y][x] = (head != nullptr) ? head->val : -1;
            if (head != nullptr) head = head->next;
            if (direction == "right" && (x + 1 >= n || ans[y][x + 1] != -2))
                direction = "down";
            else if (direction == "down" && (y + 1 >= m || ans[y + 1][x] != -2))
                direction = "left";
            else if (direction == "left" && (x - 1 < 0 || ans[y][x - 1] != -2))
                direction = "up";
            else if (direction == "up" && (y - 1 < 0 || ans[y - 1][x] != -2))
                direction = "right";
            x += direction == "right";
            x -= direction == "left";
            y += direction == "down";
            y -= direction == "up";
       }
       return ans;
    }
};