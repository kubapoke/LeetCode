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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = getLength(head);

        int revs = n / k;

        ListNode *l = head, *temp;

        for(int i = 0; i < revs; i++)
        {
            if(i == 0)
                reverseSingleKGroup(head, k);
            else
            {
                temp = l->next;
                reverseSingleKGroup(l->next, k);
                l = temp;
            }
        }

        return head;
    }

    int getLength(ListNode* head) {
        int n = 1;

        while(head->next != nullptr)
        {
            head = head->next;
            n++;
        }

        return n;
    }

    void reverseSingleKGroup(ListNode*& head, int k)
    {
        ListNode *prev = head, *curr = head->next, *next;

        for(int i = 0; i < k - 1; i++)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head->next = curr;
        head = prev;
    }
};