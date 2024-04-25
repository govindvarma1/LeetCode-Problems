/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    int findLength(ListNode* head) {
        ListNode* temp = head;
        int count = 0;
        while(temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lengthA = findLength(headA), lengthB = findLength(headB);
        while(lengthA>lengthB) {
            headA = headA->next;
            lengthA--;
        }
        while(lengthB>lengthA) {
            headB = headB->next;
            lengthB--;
        }
        while(headA != nullptr && headB != nullptr) {
            if(headA == headB) {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return nullptr;
    }
};