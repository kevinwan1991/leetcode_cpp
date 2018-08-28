/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example 1:

Given 1->2->3->4, reorder it to 1->4->2->3.
Example 2:

Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
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
    void reorderList(ListNode* head) {
        
        std::vector<ListNode*> nodes;
        auto node = head;
        
        while (node)
        {
            nodes.push_back(node);
            node = node->next;
        }
        
        auto size = nodes.size();
        for (auto i = 0; i < size/2; ++i)
        {
            auto max = size - 1;
            nodes[max-i]->next = nodes[i]->next;
            nodes[i]->next = nodes[max-i];
        }
        nodes[size/2]->next = nullptr;
    }
};

int main()
{
    auto head = new ListNode(1);
    auto node1 = new ListNode(2);
    auto node2 = new ListNode(3);
    auto node3 = new ListNode(4);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;


    Solution s;
    s.reorderList(head);

    while (head)
    {
        std::cout << head->val;
        head = head->next;
    }
}