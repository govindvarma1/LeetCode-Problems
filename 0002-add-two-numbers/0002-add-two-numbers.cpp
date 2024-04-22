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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* num1 = l1;
        ListNode* num2 = l2;
        ListNode* addedList = new ListNode;
        ListNode* ans = addedList;
        int carry = 0;
        while(num1 != nullptr && num2 != nullptr) {
            int value = num1->val + num2->val + carry;
            ListNode* temp = new ListNode(value%10);
            ans->next = temp;
            ans = ans->next;
            num1 = num1->next;
            num2 = num2->next;
            carry = value/10;
        }        
        while(num1 != nullptr) {
            int value = num1->val +carry;
            ListNode* temp = new ListNode(value%10);
            ans->next = temp;
            ans = ans->next;
            num1 = num1->next;
            carry = value/10;
        }
        while(num2 != nullptr) {
            int value = num2->val +carry;
            ListNode* temp = new ListNode(value%10);
            ans->next = temp;
            ans = ans->next;
            num2 = num2->next;
            carry = value/10;
        }
        if(carry == 1) {
            ListNode* temp = new ListNode(1);
            ans->next = temp;
        }
        return addedList->next;
    }
};