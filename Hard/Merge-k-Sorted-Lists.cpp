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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> PQ;

        for(int i = 0; i < lists.size(); i++)
        {
            if(lists[i] != nullptr)
                PQ.push(make_pair(lists[i]->val, i));
        }

        ListNode *head = nullptr, *tail = nullptr;
        pair<int, int> P;

        while(PQ.size() > 0)
        {
            P = PQ.top();
            PQ.pop();

            if(head == nullptr)
            {
                head = tail = lists[P.second];
            }
            else
            {
                tail -> next = lists[P.second];
                tail = lists[P.second];
            }

            lists[P.second] = lists[P.second] -> next;

            if(lists[P.second] != nullptr)
            {
                PQ.push(make_pair(lists[P.second]->val, P.second));
            }
        }

        if(tail != nullptr)
            tail -> next = nullptr;

        return head;
    }
};