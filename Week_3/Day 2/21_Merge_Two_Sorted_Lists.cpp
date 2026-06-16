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
        ListNode* i = list1;
        ListNode* j = list2;
        ListNode* tail;
        ListNode* head;
        if (i!=nullptr && j!=nullptr && i->val < j->val || j==nullptr && i!=nullptr)
        {
            tail = i;
            head = i;
            i = i->next;
        }
        else if (i!=nullptr && j!=nullptr && i->val >= j->val || i==nullptr && j!=nullptr){
            tail = j;
            head = j;
            j = j->next;
        }
        while (i!=nullptr && j!=nullptr)
        {
            if (i->val < j->val)
            {
                tail->next = i;
                i = i->next;
            }
            else
            {
                tail->next = j;
                j = j->next;
            }
            tail = tail->next;
        }
        if (i==nullptr)
        {
            while (tail!=nullptr && j!=nullptr)
            {
                tail->next = j;
                j = j->next;
                tail = tail->next;
            }
        }
        if (tail!=nullptr && j==nullptr)
        {
            while (i!=nullptr)
            {
                tail->next = i;
                i = i->next;
                tail = tail->next;
            }
        }
        return head;
    }
};
