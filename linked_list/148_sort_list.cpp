/*
Sort a linked list in O(n log n) time using constant space complexity.

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4
Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <vector>
#include <iostream>

struct ListNode
{
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        return quickSort(head, nullptr);
    }

    ListNode* quickSort(ListNode* start, ListNode* end)
    {
        // start must be ahead of end
        if (start == end)
        {
            return start;
        }

        auto head = partition(start, end);

        auto pivot = start;
        auto subHead1 = quickSort(head, pivot);
        auto subHead2 = quickSort(pivot->next, end);

        pivot->next = subHead2;
        return subHead1;
    }

    ListNode* partition(ListNode* start, ListNode* end)
    {
        if (start == end)
        {
            return start;
        }
        else
        {
            auto head = start;
            auto threshold = start->val;
            auto pre = start;

            while (pre != end)
            {
                auto node = pre->next;
                if (node == end)
                {
                    break;
                }
                else if (node && node->val < threshold)
                {
                    pre->next = node->next;
                    node->next = head;
                    head = node;
                }
                else
                {
                    pre = pre->next;
                }
            }

            return head;
        }
    }
};

int main()
{
    auto head = new ListNode(4);
    auto node1 = new ListNode(2);
    auto node2 = new ListNode(1);
    auto node3 = new ListNode(3);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;


    Solution s;
    head = s.sortList(head);

    while (head)
    {
        std::cout << head->val;
        head = head->next;
    }
}