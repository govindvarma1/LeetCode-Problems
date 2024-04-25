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
        ListNode* curr = head;
        while(curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1) {
            return head;
        }
        ListNode* NewNode = new ListNode;
        NewNode->next = head;
        ListNode* prev = NewNode;
        ListNode* curr = NewNode->next;
        while(curr!= nullptr) {
            int i = k-1;
            ListNode* temp = curr;
            ListNode* next = nullptr;
            ListNode* reversed = nullptr;
            while(i>0 && temp != nullptr) {
                temp = temp->next;
                i--;
            }
            if(temp == nullptr) {
                break;
            }
            next = temp->next;
            temp->next = nullptr;
            prev->next = nullptr;
            reversed = Reverse(curr);
            prev->next = reversed;
            curr->next = next;
            prev = curr;
            curr = curr->next;
            
        }        
        return NewNode->next;
    }
};