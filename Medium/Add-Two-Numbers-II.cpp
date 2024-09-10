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
        ListNode *prev = nullptr, *next, *l = nullptr;

        while(l1->next)
        {
            next = l1->next;
            l1->next = prev;
            prev = l1;
            l1 = next;
        }

        l1->next = prev;

        prev = nullptr;

        while(l2->next)
        {
            next = l2->next;
            l2->next = prev;
            prev = l2;
            l2 = next;
        }

        l2->next = prev;

        int rem = 0;

        while(l1 || l2 || rem)
        {
            int val = rem;
            rem = 0;

            if(l1)
            {
                val += l1->val;
                l1 = l1-> next;
            }
            if(l2)
            {
                val += l2->val;
                l2 = l2-> next;
            }

            if(val >= 10)
            {
                val -= 10;
                rem = 1;
            }

            l = new ListNode(val, l);
        }

        return l;
    }
};