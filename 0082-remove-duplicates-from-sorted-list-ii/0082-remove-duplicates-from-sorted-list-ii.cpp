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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode ans(0);
        ans.next = head;
        ListNode* prev = &ans;
        ListNode* temp = head;
        while(temp != nullptr && temp->next != nullptr) {
            bool isDuplicate = false;
            ListNode* next = temp->next;

            while(next != nullptr && next->val == temp->val) {
                isDuplicate = true;
                next = next->next;
            }
            
            if(isDuplicate) {
                prev->next = next;
            } else {
                prev = temp;
            }
            temp = next;            
        }
        return ans.next;
    }
};