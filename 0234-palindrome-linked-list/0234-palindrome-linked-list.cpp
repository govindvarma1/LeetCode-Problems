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

    ListNode* Reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* temp = nullptr;
        while( head!= nullptr) {
            temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* reversedNode = Reverse(slow);
        while(head != nullptr && reversedNode != nullptr) {
            if(head->val != reversedNode->val) {
                return false;
            }         
            reversedNode = reversedNode->next;
            head = head->next;
        }
        return true;
        
    }
};