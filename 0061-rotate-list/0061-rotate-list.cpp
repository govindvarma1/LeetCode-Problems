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

    int findLength(ListNode* head) {
        int count = 0;
        while(head != nullptr) {
            head = head->next;
            count++;
        }
        return count;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        int n = findLength(head);
        if(n == 1 || n == 0 || k%n==0) {
            return head;
        }
        k = k%n;
        ListNode* slow = head;
        ListNode* fast = head;
        while(k>0) {
            fast = fast->next;
            k--;
        }
        while(fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* temp = head;
        head = slow->next;
        fast->next = temp;
        slow->next = nullptr; 
        return head;
    }
};