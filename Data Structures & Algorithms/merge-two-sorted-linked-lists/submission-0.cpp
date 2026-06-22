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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* l1 = list1;
        ListNode* l2 = list2;
        ListNode* ans= new ListNode(0);
        ListNode* list;
        ans->next=list;
        while (l1 != nullptr and l2 != nullptr) {
            if (l1->val < l2->val) {
                list->next = l1;
                l1=l1->next;
            } else {
                list->next = l2;
                l2=l2->next;
            }
            list = list->next;
        }
        while (l1 != nullptr) {
            list->next = l1;
            l1=l1->next;
            list = list->next;
        }
        while (l2 != nullptr) {
            list->next = l2;
            l2=l2->next;
            list = list->next;
        }
        return ans->next;
    }
};
